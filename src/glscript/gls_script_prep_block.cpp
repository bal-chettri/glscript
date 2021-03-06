//
// 
// 
// This file is part of glScript project.
//
//   glScript is free software: you can redistribute it and/or modify
//   it under the terms of the GNU Lesser General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   glScript is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Lesser General Public License for more details.
//
//   You should have received a copy of the GNU Lesser General Public License
//   along with glScript. If not, see <http://www.gnu.org/licenses/>.
//
//   Copyright (c) 2012 Bal Bahadur Chettri
//
//   Author: Bal Bahadur Chettri (balu.chettri@gmail.com)
//
#include "stdafx.h"
#include <glscript/gls_script_preprocessor.h>
#include <glscript/gls_script_loader.h>
#include <glscript/gls_string_utils.h>
#include <sysutils/sysutils.h>

using namespace gls;

// prototypes for internal helper functions ..
static int TokenEqualsTo (const Tokenizer<wchar_t>::Token &token, const sys_wchar *str);
static sys_wchar *GetTokenString (const Tokenizer<wchar_t>::Token &token);

// PreprocessorBlock class definition...

///////////////////////////////////////////////////////////////////////////////
//
PreprocessorBlock::PreprocessorBlock (const sys_wchar *block_start,
                                        const sys_wchar *block_end, 
                                        ScriptSource *pScriptSource,
                                        ScriptPreprocessor *pPrep) 
{
    m_pBlockStart = block_start;
    m_pBlockEnd = block_end;
    m_language = L"";
    m_pScriptSource = pScriptSource; // script source object is not addref'ed
    m_pPreprocessor = pPrep; // script preprocessor (not addref'ed)
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
PreprocessorBlock::~PreprocessorBlock () {
    Cleanup ();
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
size_t PreprocessorBlock::GetExpandedLength () const {
    std::vector<ScriptSource *>::const_iterator 
        it = m_inc_sources.begin(),
        it_end = m_inc_sources.end();

    size_t size = 0;

    for (; it != it_end; it++) {
        ScriptSource *pIncludeSource = *it;
        size+= pIncludeSource->GetLength ();
    }

    return size;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
const tstring PreprocessorBlock::GetLanguage () const {
#ifdef UNICODE
    return m_language;
#else
    return tstring(WS2MBS(m_language.c_str()));
#endif
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ParseBlock () {
    int ret = kPrepErrorNone;

    // clear all commands before we parse the new block
    m_commands.clear ();
    
    Tokenizer<wchar_t> tokenizer;
    Tokenizer<wchar_t>::Token tokens[10]; // max tokens per preprocessor line

    // set tokenizer flags
    tokenizer.SetFlags (
        Tokenizer<wchar_t>::TerminateAtNewLine | 
        Tokenizer<wchar_t>::TokenizeSymbols | 
        Tokenizer<wchar_t>::KeepWhiteToken |
        Tokenizer<wchar_t>::UnquoteString
        );

    tokenizer.SetSymbols(L"~~!@#$%^&*()_+-={}[]:\";'<>?,./|\\");
    tokenizer.SetWhiteChars(L"\r\n\f\t ");

    // input begins at the start of the block
    sys_wchar *input = (sys_wchar *)(m_pBlockStart + 2);

    // terminate the block temporarily so that we don't tokenize reset of the block #>
    sys_wchar temp = *(m_pBlockEnd - 1);
    *((sys_wchar *)m_pBlockEnd - 1) = 0;

    // loop until we pass the end of the block
    while (input <= (m_pBlockEnd - 1)) {
        // tokenize the current line
        size_t count_tokens;
        count_tokens = tokenizer.Tokenize(&input, tokens, sizeof(tokens)/sizeof(tokens[0]));
        
        // skip all leading white tokens
        size_t index = 0;
        size_t num_tokens = count_tokens;

        while (index < count_tokens && 
                Tokenizer<wchar_t>::IsWhitespaceToken(tokens[index])) 
        {
            ++index;
            --num_tokens;
        }
        if (num_tokens== 0) {
            continue;
        }

        // parse command
        ret = ParseCommand (&tokens[index], num_tokens);
        if ( ret != kPrepErrorNone ) {
            return ret;
        }
    }

    // reset the character after the block
    *((sys_wchar *)m_pBlockEnd - 1) = temp;

    return ret;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ProcessBlock () {    
    std::vector<PreprocessorCommand>::iterator it, it_end;

    for (it = m_commands.begin(); it != m_commands.end(); it++) {
        PreprocessorCommand &cmd = (*it);
        int status;

        switch (cmd.type) {
        case kPrepCommandTypeInclude:
            status = ProcessCommand_Include (cmd);
            break;
        
        case kPrepCommandTypeLanguage:
            status = ProcessCommand_Language (cmd);
            break;
        }

        if (status != kPrepErrorNone) {
            return status;
        }

    } // for

    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ExpandBlock (sys_wchar **p_pCodeBuffer) {
    sys_wchar *pCodeBuffer = *p_pCodeBuffer;

    std::vector<ScriptSource *>::const_iterator 
        it = m_inc_sources.begin(),
        it_end = m_inc_sources.end();

    size_t size = 0;

    for (; it != it_end; it++) {
        ScriptSource *pIncludeSource = *it;
        size_t codeLength = pIncludeSource->GetLength();

        memcpy (pCodeBuffer, pIncludeSource->GetCode(), codeLength * sizeof(sys_wchar));
        pCodeBuffer+= codeLength;
    }

    *p_pCodeBuffer = pCodeBuffer;
    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ParseCommand (const Tokenizer<wchar_t>::Token *tokens, size_t num_tokens) {
    int ret;
    
    if ( TokenEqualsTo(tokens[0], L"include") ) {
        ret = ParseCommand_Include (tokens, num_tokens);
    }
    else if ( TokenEqualsTo(tokens[0], L"language") ) {
        ret = ParseCommand_Language (tokens, num_tokens);
    } 
    else {
        ret = kPrepErrorInvalidCommand;
    }

    return ret;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ParseCommand_Include (const Tokenizer<wchar_t>::Token *tokens, size_t count_tokens) {
    // include "url"
    if (count_tokens < 3) {
        return kPrepErrorSyntaxParse; 
    }   

    if ( tokens[1].type != Tokenizer<wchar_t>::WhiteToken || tokens[2].type != Tokenizer<wchar_t>::StringToken ) {
        return kPrepErrorSyntaxParse;
    }

    PreprocessorCommand command;
    command.type = kPrepCommandTypeInclude;
    memcpy (&command.token, &tokens[2], sizeof(Tokenizer<wchar_t>::Token));

    m_commands.push_back (command);
    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ParseCommand_Language (const Tokenizer<wchar_t>::Token *tokens, size_t count_tokens) {
    // language "lang"
    if (count_tokens < 3) {
        return kPrepErrorSyntaxParse; 
    }

    if ( tokens[1].type != Tokenizer<wchar_t>::WhiteToken || tokens[2].type != Tokenizer<wchar_t>::StringToken ) {
        return kPrepErrorSyntaxParse;
    }

    PreprocessorCommand command;
    command.type = kPrepCommandTypeLanguage;
    memcpy (&command.token, &tokens[2], sizeof(Tokenizer<wchar_t>::Token));

    m_commands.push_back (command);
    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ProcessCommand_Language (PreprocessorCommand &cmd) {
    sys_wchar *buff = GetTokenString (cmd.token);
    m_language = buff;
    delete buff;

    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int PreprocessorBlock::ProcessCommand_Include (PreprocessorCommand &cmd) {      
    // get token ULR    
    const wchar_t *urlToken = GetTokenString(cmd.token);
#ifdef UNICODE
    tstring strUrlToken = urlToken;
#else
    tstring strUrlToken = WS2MBS(urlToken);
#endif

    // get all url forms    
    std::vector<tstring> url_forms;

    if ( sysutils_path_is_absolute(strUrlToken.c_str()) ) 
    {
        // token URL is an absolute URL path so no path resolution
        url_forms.push_back ( strUrlToken );
    } 
    else
    {
        // make full URL path to file to preprocess
        tstring strTempURL;
        strTempURL = m_pScriptSource->GetBaseURL();     // relative to current source's base URL
        strTempURL+= strUrlToken;                       // append relative token URL path

        url_forms.push_back ( strTempURL );             // relative to current source's base URL

        std::vector<tstring>::iterator 
            it = m_pPreprocessor->m_search_paths.begin(),
            it_end = m_pPreprocessor->m_search_paths.end();
        for (; it != it_end; it++) {
            strTempURL = *it;
            // append path separator if required
            const sys_tchar kPathSep [] = { SYSUTILS_PATH_SEPARATOR, _tx('\0') };
            if ( strTempURL.substr(strTempURL.length () - 1, 1) != kPathSep ) {
                strTempURL+= kPathSep;
            }
            strTempURL+= strUrlToken;
            url_forms.push_back ( strTempURL );
        }
    }
    delete urlToken; // free the URL token when done

    // try to preprocess the included file...
    std::vector<tstring>::iterator it = url_forms.begin(), it_end = url_forms.end();
    int preproces_status;

    for (; it != it_end; it++) {
        const sys_tchar *url = (*it).c_str ();
        ScriptSource *pIncludeSource;

        pIncludeSource = ScriptPreprocessor::PreprocessScript (url, preproces_status);
        if (preproces_status == kPrepErrorNone) {
            m_inc_sources.push_back (pIncludeSource);
            return kPrepErrorNone; // include file was successfully preprpocessed
        }
    }

    return preproces_status;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// cleanup block
void PreprocessorBlock::Cleanup () {
    std::vector<ScriptSource *>::iterator 
        it = m_inc_sources.begin(),
        it_end = m_inc_sources.end();

    for (; it != it_end; it++) {
        ScriptSource *pIncludeSource = *it;
        pIncludeSource->Release ();
    }

    m_inc_sources.clear (); 
}
///////////////////////////////////////////////////////////////////////////////


// internal helper functions...


///////////////////////////////////////////////////////////////////////////////
//
static int TokenEqualsTo (const Tokenizer<wchar_t>::Token &token, const sys_wchar *str) {
    size_t i = 0;
    while (i < token.length && *str) {
        if (token.string[i++] != *str)
            return false;
        ++str;
    }
    return (i == token.length && *str == L'\0');
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
static sys_wchar *GetTokenString (const Tokenizer<wchar_t>::Token &token) {
    sys_wchar *temp;
    if (token.length == 0) {
        temp = new sys_wchar[ 2 ];
    } else {
        temp = new sys_wchar[ token.length + 1 ];
    }
    
    if (token.length == 0) {
        // whitespace token is trimmed to 0 length string
        temp[0] = Tokenizer<wchar_t>::IsWhitespaceToken(token) ? L' ' : L'\0';
        temp[1] = _tx('\0');
    } else {
        wcsncpy(temp, token.string, token.length);
        temp[token.length] = _tx('\0');
    }

    return temp;
}
///////////////////////////////////////////////////////////////////////////////

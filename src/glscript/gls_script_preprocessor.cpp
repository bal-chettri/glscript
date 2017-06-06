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
#include <sysutils/sysutils.h>

using namespace gls;

///////////////////////////////////////////////////////////////////////////////
//
#ifdef WIN32
    #define MAX_FILE_PATH                       MAX_PATH
#else
    #define MAX_FILE_PATH                       260
#endif
///////////////////////////////////////////////////////////////////////////////


// ScriptPreprocessor class definition...


///////////////////////////////////////////////////////////////////////////////
//
ScriptPreprocessor::ScriptPreprocessor (ScriptSource *pSourceScript) {
    m_pScriptSource = pSourceScript;
    m_pScriptSource->AddRef ();

    m_language = _tx("");
    m_pFlattenedScriptSource = NULL;

    m_parent_preprocessor = NULL;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptPreprocessor::~ScriptPreprocessor () {
    m_pScriptSource->Release ();

    if (m_pFlattenedScriptSource != NULL) {
        m_pFlattenedScriptSource->Release ();
    }
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptSource *ScriptPreprocessor::GetSourceScript () {
    m_pScriptSource->AddRef ();
    return m_pScriptSource;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int ScriptPreprocessor::Preprocess () {
    int ret;
    
    // scan all prep blocks 
    if ( (ret = FindBlocks ()) != kPrepErrorNone ) {
        return ret;
    }

    // process all the blocks scanned above
    if ( (ret = ProcessBlocks ()) != kPrepErrorNone ) {
        return ret;
    }

    // flatten all blocks
    ret = FlattenBlocks ();
    return ret;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptSource *ScriptPreprocessor::GetFlattenedScriptSource () { 
    if (m_pFlattenedScriptSource) {
        m_pFlattenedScriptSource->AddRef ();
        return m_pFlattenedScriptSource;
    }

    return NULL;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int ScriptPreprocessor::FindBlocks () {
    // clear all prep blocks first
    m_blocks.clear ();

    const sys_tchar *pCode = m_pScriptSource->GetCode ();
    const sys_wchar *pBlockStart, *pBlockEnd;

    // find all preprocessor blocks in the script
    do {
        // find the start of the block
        if ( (pBlockStart = FindBlockStart(pCode)) != NULL ) {
            
            // find the end of the block
            if ( (pBlockEnd = FindBlockEnd(pBlockStart + 2)) == NULL ) {
                return kPrepErrorUnterminatedBlock;
            }
            
            // create a block object with block tags removed and add to the list
            PreprocessorBlock block (pBlockStart, pBlockEnd, m_pScriptSource, this);
            m_blocks.push_back (block);

            pCode = pBlockEnd + 1;
        }
    } while (pBlockStart != NULL);

    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
const sys_wchar *ScriptPreprocessor::FindBlockStart (const sys_wchar *pCode) {
    const sys_wchar *ptr = pCode;

    while (*ptr) {
        if ( *ptr == _tx('<') && *(ptr + 1) == _tx('#') ) {
            return ptr;
        }
        ++ptr;
    }

    return NULL;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
const sys_wchar *ScriptPreprocessor::FindBlockEnd (const sys_wchar *pCode) {
    const sys_wchar *ptr = pCode;

    while (*ptr) {
        if ( *ptr == _tx('#') && *(ptr + 1) == _tx('>') ) {
            return ptr + 1;
        }
        ++ptr;
    }

    return NULL;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// ProcessBlocks(). Parses each block found and processes it.
int ScriptPreprocessor::ProcessBlocks () {
    // initialize iterator
    std::vector<PreprocessorBlock>::iterator 
        it = m_blocks.begin(),
        it_end = m_blocks.end();

    int ret = kPrepErrorNone;

    bool flag_language_set = false;

    for (; it != it_end; it++) {
        // get the preprocessor block
        PreprocessorBlock &block = *(it);       

        // parse block
        ret = block.ParseBlock ();
        if (ret != kPrepErrorNone) {
            break;
        }

        // process block
        ret = block.ProcessBlock ();
        if (ret != kPrepErrorNone) {
            break;
        }

        // get block language
        const tstring &block_language = block.GetLanguage();
        if (block_language.length() > 0) {
            // check if language is already set
            if (flag_language_set) {
                return kPrepErrorLanguageRedefined;
            }

            flag_language_set = true;

            // save the script language, which we'll later set in the 
            // flattened script source
            m_language = block_language;
        }
    }

    return ret;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
int ScriptPreprocessor::FlattenBlocks () {
    // release current flattend script source object
    if (m_pFlattenedScriptSource != NULL) {
        m_pFlattenedScriptSource->Release ();
        m_pFlattenedScriptSource = NULL;
    }

    // if no blocks return the unmodified script source
    if (m_blocks.size() == 0) {
        m_pFlattenedScriptSource = m_pScriptSource;
        m_pFlattenedScriptSource->AddRef ();
        return kPrepErrorNone;
    }

    // calculate maximum size of the expanded file
    size_t expandedCodeLength = GetScriptLength ();

    // pointer to the end of the script
    const sys_wchar *pCodeEnd = m_pScriptSource->GetCode() + m_pScriptSource->GetLength();

    // calculate the length of expanded code
    std::vector<PreprocessorBlock>::iterator 
        it = m_blocks.begin(),
        it_end = m_blocks.end();

    for (; it != it_end; it++) {
        PreprocessorBlock &block = (*it);
        expandedCodeLength+= block.GetExpandedLength ();
    }

    // allocate buffer for flattened / expanded code.
    sys_wchar *pFlattenedCode = new sys_wchar [expandedCodeLength + 1];
    if (pFlattenedCode == NULL) {
        return kPrepErrorOutOfMemory;
    }
    memset (pFlattenedCode, 0, expandedCodeLength * sizeof(sys_wchar));

    // flatten / expand code
    const sys_char *pCode = (const sys_char *)m_pScriptSource->GetCode ();
    sys_char *pFlattenedCodeHead = (sys_char *)pFlattenedCode;

    it = m_blocks.begin();
    it_end = m_blocks.end();
    for (; it != it_end; it++) {
        PreprocessorBlock &block = (*it);

        const sys_char *pBlockStart = (const sys_char *)block.GetBlockStart ();

        // copy code from source script
        memcpy (pFlattenedCodeHead, pCode, (pBlockStart - pCode) * sizeof(sys_wchar));
        pFlattenedCodeHead+= (pBlockStart - pCode);

        // expand block script
        block.ExpandBlock ( (sys_wchar **) &pFlattenedCodeHead );

        // point to the next script segment i.e. character after the block
        pCode = (const sys_char *) (block.GetBlockEnd () + 1);
    }
    
    // copy remaining code from source script   
    memcpy (
        pFlattenedCodeHead, pCode, 
        (pCodeEnd - (const sys_wchar *)pCode) * sizeof(sys_wchar)
        );

    // null terminate the flattened code
    pFlattenedCode[expandedCodeLength] = L'\0';

    // create a flattened script source
    m_pFlattenedScriptSource = new ScriptSource (
                m_pScriptSource->GetBaseURL().c_str(), 
                m_pScriptSource->GetFileName().c_str(), 
                pFlattenedCode, expandedCodeLength
                );

    if (m_pFlattenedScriptSource == NULL) {
        return kPrepErrorOutOfMemory;
    }

    // set the script language in flattened script object
    m_pFlattenedScriptSource->SetLanguage (m_language);

    return kPrepErrorNone;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
size_t ScriptPreprocessor::GetBlocksLength () const {
    std::vector<PreprocessorBlock>::const_iterator it, it_end;

    it = m_blocks.begin();
    it_end = m_blocks.end();

    size_t length = 0;

    for (; it != it_end; it++) {
        const PreprocessorBlock &block = (*it);
        length+= block.GetLength ();
    }

    return length;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
size_t ScriptPreprocessor::GetScriptLength () const {
    return m_pScriptSource->GetLength () - GetBlocksLength ();
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
void ScriptPreprocessor::SetIncludeSearchPaths (const std::vector<tstring> &search_paths) {
    m_search_paths = search_paths;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
void ScriptPreprocessor::SetParentPreprocessor (ScriptPreprocessor *pPrep) {
    m_parent_preprocessor = pPrep; // not addref'ed
}
///////////////////////////////////////////////////////////////////////////////

// static functions...

///////////////////////////////////////////////////////////////////////////////
//
ScriptPreprocessor *ScriptPreprocessor::CreatePreprocessor (
                                            const sys_tchar *url, 
                                            ScriptPreprocessor *parent,
                                            const std::vector<tstring> &search_paths,
                                            int &ret) 
{
    ret = kPrepErrorNone;

    // check for invalid path
    if (sys_tstrlen(url) > MAX_FILE_PATH) {
        ret = kPrepErrorInvalidPathSpec;
        return NULL;
    }

    // load the script source code using synchronous script source loader
    ScriptFileSourceLoader *script_loader = new ScriptFileSourceLoader ();
    sys_wchar *script_code = script_loader->LoadScriptSource (url);
    script_loader->Release ();

    if (script_code == NULL) {
        ret = kPrepErrorLoadScriptFailed;
        return NULL;
    }   

    // get URL base path and file name
    sys_tchar url_base [MAX_FILE_PATH + 1];
    sys_tchar url_file_name [MAX_FILE_PATH + 1];

    sysutils_path_get_base (
            url, url_base, 
            sizeof(url_base) / sizeof(url_base[0])
            );
    sysutils_path_get_filename (
            url, url_file_name, 
            sizeof(url_file_name) / sizeof(url_file_name[0])
            );

    // create script source object passing the script source path information
    // and script code. Note that the script source object automatically frees
    // the script code buffer when it is destroyed.
    ScriptSource *script_source;
    script_source = new ScriptSource (url_base, url_file_name, 
                                        script_code, 
                                         sys_tstrlen(script_code), 
                                         true /* auto_free_code */
                                         );
    
    // create preprocessor object to preprocess the from script source
    ScriptPreprocessor *script_preprocessor;
    script_preprocessor = new ScriptPreprocessor (script_source);

    // configure the preprocessor
    script_preprocessor->SetParentPreprocessor (parent);
    script_preprocessor->SetIncludeSearchPaths (search_paths);

    script_source->Release ();

    return script_preprocessor;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptSource *ScriptPreprocessor::PreprocessScript (const sys_tchar *url, int &ret) {   
    std::vector<tstring> search_paths;
    return PreprocessScript (url, NULL, search_paths, ret);
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptSource *ScriptPreprocessor::PreprocessScript (const sys_tchar *url, 
                                                        ScriptPreprocessor *parent,
                                                        const std::vector<tstring> &search_paths, 
                                                        int &ret) 
{
    ScriptPreprocessor *script_preprocessor;

    script_preprocessor = CreatePreprocessor (url, parent, search_paths, ret);
    if (ret != kPrepErrorNone) {
        return NULL;
    }

    // preprocess the script source
    ret = script_preprocessor->Preprocess ();
    if (ret != kPrepErrorNone) {
        script_preprocessor->Release ();
        return NULL;
    }

    // Get the preprocessed / flattened script source object and return it.
    // The caller needs to free this object.
    ScriptSource *flattened_script_source;
    flattened_script_source = script_preprocessor->GetFlattenedScriptSource ();
    script_preprocessor->Release ();

    return flattened_script_source;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
const sys_tchar *ScriptPreprocessor::TranslateErrorCode (int err_code) {
    struct PrepErrorEntry {
        int errCode;
        const sys_tchar *lpszErrorMsg;
    };

    static PrepErrorEntry prepErroTable[] = {
        {
            kPrepErrorOutOfMemory,
            _tx("Out of memory."),
        },      
        {
            kPrepErrorSyntaxParse,
            _tx("Syntax error while parsing.")
        },
        {
            kPrepErrorInvalidCommand,
            _tx("Invalid preprocessor command.")
        },
        {
            kPrepErrorLanguageRedefined,
            _tx("Language name redefined.")
        },
        {
            kPrepErrorTooManyTokens,
            _tx("Parse Error: Too many tokens.")
        },
        {
            kPrepErrorTooLongToken,
            _tx("Parse Error: Too long token.")
        },
        {
            kPrepErrorInvalidPathSpec,
            _tx("Invalid path specification.")
        },
        {
            kPrepErrorUnterminatedBlock,
            _tx("Parse Error: Unterminated preprocessor block.")
        },
        {
            kPrepErrorLoadScriptFailed,
            _tx("Failed to load the script for preprocessing.")
        },
        {
            kPrepErrorPreprocessFailed,
            _tx("Preprocessing failed.")
        }
    };

    for (int i=0; i < sizeof(prepErroTable) / sizeof(prepErroTable[0]); i++) {
        if (err_code == prepErroTable [i].errCode) {
            return prepErroTable[i].lpszErrorMsg;
        }
    }

    static const sys_tchar *lpszGenericError = 
        _tx("Preprocessing failed: Unknown error.");

    return lpszGenericError;
}
///////////////////////////////////////////////////////////////////////////////

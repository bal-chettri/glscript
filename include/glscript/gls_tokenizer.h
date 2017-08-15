//
// gls_scripthost_driver.h  glscript script host driver.
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
#ifndef __GLSCRIPT_TOKENIZER_H__
#define __GLSCRIPT_TOKENIZER_H__

namespace gls
{

#include <stdio.h>
#include <string.h>
#include <sysport/sysport.h>

/* class Tokenizer */
template <typename _CharType>
class Tokenizer
{
public:
    /* Flags */
    enum Flags
    {
        TokenizeSymbols = 1,
        KeepWhiteToken = 2,
        UnquoteString = 4,
        TerminateAtNewLine = 8
    }; /* Flags */

    /* enum StringQuote */
    enum StringQuote
    {
        SingleQuote,
        DoubleQuote
    }; /* enum StringQuote */

    /* enum NewlinePair */
    enum NewlinePair
    {
        NewlineCRLF,
        NewlineLFCR,
    }; /* enum NewlinePair */

    /* enum TokenType */
    enum TokenType
    {
        InvalidToken,
        WordToken,
        SymbolToken,
        WhiteToken,
        StringToken
    }; /* enum TokenType */

    /* struct Token */
    struct Token
    {
        const _CharType *string;            /* pointer to actual string (not 0 terminated) */
        size_t length;                      /* length of string */
        TokenType type;                     /* type of token */
    }; /* struct Token */

public:
    /* Tokenizer class definition */
    Tokenizer::Tokenizer()
    {
        /* set default flags */
        m_flags = 0;
        m_flags|= TokenizeSymbols;
        m_flags|= KeepWhiteToken;
        m_flags|= UnquoteString;
        m_flags|= TerminateAtNewLine;

        /* set defaults */
        m_string_quote = DoubleQuote;
        m_newline_pair = NewlineCRLF;
    }

    Tokenizer::~Tokenizer()
    { }

    int Tokenizer::GetFlags() const { return m_flags; }
    void Tokenizer::SetFlags (int flags) { m_flags = flags; }
    void Tokenizer::SetSymbols (const _CharType *symbols) { m_symbols = symbols; }
    void Tokenizer::SetWhiteChars (const _CharType *white_chars) { m_white_chars = white_chars; }
    void Tokenizer::SetStringQuote (StringQuote quote) { m_string_quote = (quote == SingleQuote ? SingleQuote : DoubleQuote); }
    void Tokenizer::SetNewlinePair (NewlinePair newline_pair) { m_newline_pair = newline_pair; }
    
    static bool Tokenizer::IsWhitespaceToken (const Token &token) 
    { return token.length == 0 && token.string[0] != _tx('\''); }

    size_t Tokenizer::Tokenize (_CharType **pinput, Token *token_buffer, size_t max_tokens)
    {
        _CharType *head, *tail;
        bool flag_sym;
        bool flag_white;
        bool flag_quote;
        bool flag_tokenize_symbol;
        bool flag_keep_white_token;
        _CharType ch;
        _CharType quote_char;
        _CharType newline_chars[2];
        size_t num_tokens;
        TokenType token_type;

        /* init vars */
        num_tokens = 0;
        flag_sym = false;
        flag_quote = false;
        flag_tokenize_symbol = (m_flags & TokenizeSymbols) ? true : false;
        flag_keep_white_token = (m_flags & KeepWhiteToken) ? true : false;
        quote_char = (m_string_quote == SingleQuote ? _CharType('\'') : _CharType('\"'));

        if (m_newline_pair == NewlineCRLF) {
            newline_chars[0] = _CharType('\r');
            newline_chars[1] = _CharType('\n');
        } else /*if (m_newline_pair == NewlineCRLF)*/ {
            newline_chars[0] = _CharType('\n');
            newline_chars[1] = _CharType('\r');
        }

        head = *pinput;

        while (true) {
            /* skip white space */
            if (!flag_keep_white_token) {
                while ( *head &&  IsWhite(*head) ) {
                    ++head;
                }
            }
            /* passed the line? */  
            if ( *head == _CharType('\0') ) {
                ++head;
                break;
            }

            /* if TerminateAtNewLine flag is set, break at newline */
            if (m_flags & TerminateAtNewLine) {
                if (*head == newline_chars[0] && *(head + 1) == newline_chars[1]) {
                    head+= 2;
                    break;
                }
            }
        
            /* check for token limit */
            if (num_tokens == max_tokens ) {
                break;
            }

            /* set tail pointer to the next character after head */
            tail = head + 1;    

            /* check for symbol */
            flag_sym = IsSymbol(*head);
            /* cehck for white space */
            flag_white = IsWhite(*head);
            /* check for string quote '"' character */
            flag_quote = (*head == quote_char);

            /* determine token type */
            if (flag_quote)
                token_type = StringToken;
            else if (flag_white)
                token_type = WhiteToken;
            else if (flag_sym)
                token_type = SymbolToken;
            else
                token_type = WordToken;

            /* find the end of token */
            while (*tail) {
                /* get the character in buffer */
                ch = *tail;

                /* check for a string quote */          
                if (ch == quote_char) {
                    /* if the quote flag is already set, this marks the end of quoted string. */
                    if (flag_quote) {
                        /* reset the quote flag */
                        flag_quote = false;
                        /* skip tail to the next character after the end quote */
                        ++tail;
                        break;
                    }
                    /* we have a new quoted string ahead, set the quote flag. */
                    flag_quote = true;              
                    /* token ends before the quote */
                    break;
                }

                if (!flag_quote) {
                    /* token ends at non white character if preceded by a white space */
                    if (flag_keep_white_token && !IsWhite(ch) && flag_white) {
                        break;
                    }

                    /* token ends at white space or a symbol if not within a quoted string */
                    if ( (IsWhite(ch) && !flag_white) || (IsSymbol(ch) && flag_tokenize_symbol) ) {
                        break;
                    }

                    /* token ends at non-white character if the last token was a symbol if not 
                    within a quoted string */
                    if ( (flag_sym && !IsWhite(ch) && flag_tokenize_symbol) ) {
                        break;
                    }
                }
            
                ++tail; /* point to next character */

            } /* !flag_quote */
        
            /* add the token */
            token_buffer[num_tokens].string = head;

            if (flag_keep_white_token && flag_white) {
                token_buffer[num_tokens].length = 0;
            } else {
                token_buffer[num_tokens].length = tail - head;
            }       

            token_buffer[num_tokens].type = token_type;

            /* unquote string token if required */
            if ( (token_type == StringToken) && (m_flags & UnquoteString)) {
                /* points to the terminating quote char if token is an empty string */
                ++token_buffer[num_tokens].string;
                /* length is 0 if token is an empty string, so check for 
                string[0] == '\'' to differentiate from a white space token */
                token_buffer[num_tokens].length-= 2;
            }       

            /* increment the token counter */
            ++num_tokens;
    
            /* move the head pointer to beginning of the next token */
            head = tail;
        }

        /* check if string quote is open */
        if (flag_quote) {
            throw _tx("unterminated string.");
        }

        /* return address of the next character in the input string */
        *pinput = head;

        /* return number of tokens parsed */
        return num_tokens;
    }

private:
    inline bool Tokenizer::IsWhite(_CharType ch) const;
    inline bool Tokenizer::IsSymbol(_CharType ch) const;    

private:
    int                 m_flags;                /* tokenizer flags */
    const _CharType *   m_symbols;              /* pointer to recognized symbols */
    const _CharType *   m_white_chars;          /* pointer to recognized white characters */
    StringQuote         m_string_quote;         /* string quote type */
    NewlinePair         m_newline_pair;         /* newline character pair */

}; /* class Tokenizer */

template <> bool Tokenizer<char>::IsWhite(char ch) const
{
    return (strchr(m_white_chars, ch) != NULL);
}
template <> bool Tokenizer<wchar_t>::IsWhite(wchar_t ch) const
{
    return (wcschr(m_white_chars, ch) != NULL);
}

template <> bool Tokenizer<char>::IsSymbol(char ch) const 
{
    return (strchr(m_symbols, ch) != NULL); 
}
template <> bool Tokenizer<wchar_t>::IsSymbol(wchar_t ch) const 
{
    return (wcschr(m_symbols, ch) != NULL); 
}

}; // gls namespace

#endif // !__GLSCRIPT_TOKENIZER_H__

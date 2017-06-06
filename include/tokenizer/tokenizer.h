/**
 * tokenizer.h      Simple and fast string tokenizer for C++
 *
 * Version:         1.0
 *
 * Author:          Bal Bahadur Chettri (balu.chettri@gmail.com)
 *
 * Copyright (c) 2011 Bal Bahadur Chettri
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit 
 * persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __TOKENIZER_H
 #define __TOKENIZER_H

#include <stdio.h>
#include <string.h>
//#include <tchar.h>

#include <sysport/sysport.h>

#ifndef __cplusplus
#error "This file requires C++."
#endif

/* class Tokenizer */
class Tokenizer {
public:
    enum { /* Flags */
        TokenizeSymbols = 1,
        KeepWhiteToken = 2,
        UnquoteString = 4,
        TerminateAtNewLine = 8
    }; /* Flags */

    /* enum StringQuote */
    enum StringQuote {
        SingleQuote,
        DoubleQuote
    }; /* enum StringQuote */

    /* enum NewlinePair */
    enum NewlinePair {
        NewlineCRLF,
        NewlineLFCR,
    }; /* enum NewlinePair */

    /* enum TokenType */
    enum TokenType {
        InvalidToken,
        WordToken,
        SymbolToken,
        WhiteToken,
        StringToken
    }; /* enum TokenType */

    /* struct Token */
    struct Token {
        const sys_tchar *string;            /* pointer to actual string (not 0 terminated) */
        size_t length;                      /* length of string */
        TokenType type;                     /* type of token */
    }; /* struct Token */

public:
    /* ctor */
    Tokenizer ();

    /* dtor */
    virtual ~Tokenizer ();

    int GetFlags() const;
    void SetFlags (int flags);
    void SetSymbols (const sys_tchar *symbols);
    void SetWhiteChars (const sys_tchar *white_chars);
    void SetStringQuote (StringQuote quote);
    void SetNewlinePair (NewlinePair newline_pair);

    static bool IsWhitespaceToken (const Token &token);

    /* tokenizes the input string */
    size_t Tokenize (sys_tchar **pinput, Token *token_buffer, size_t max_tokens);

#if _DEBUG
    static void DumpToken (const Token &token);
    static void DumpTokens (const Token *tokens, size_t length);
#endif

private:
    inline bool IsWhite (sys_tchar ch) const;
    inline bool IsSymbol (sys_tchar ch) const;

private:
    int m_flags;                            /* tokenizer flags */
    const sys_tchar *m_symbols;             /* pointer to recognized symbols */
    const sys_tchar *m_white_chars;         /* pointer to recognized white characters */
    StringQuote m_string_quote;             /* string quote type */
    NewlinePair m_newline_pair;             /* newline character pair */
    static const sys_tchar *_def_symbols;
    static const sys_tchar *_def_white_chars;

}; /* class Tokenizer */

#endif /* __TOKENIZER_H */

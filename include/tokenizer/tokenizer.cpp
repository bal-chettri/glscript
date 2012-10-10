/**
 * tokenizer.cpp	Simple and fast string tokenizer for C++
 *
 * Version:			1.0
 *
 * Author:			Bal Bahadur Chettri (balu.chettri@gmail.com)
 *
 * Copyright (c) 2011 Bal Bahadur Chettri
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit 
 * persons to whom the Software is furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <tokenizer/tokenizer.h>

/* static */
const sys_tchar *Tokenizer::_def_symbols = 
_tx("~~!@#$%^&*()_+-={}[]:\";'<>?,./|\\");

const sys_tchar *Tokenizer::_def_white_chars = 
_tx("\r\n\f\t ");

/* Tokenizer class definition */
Tokenizer::Tokenizer () {
	/* set default flags */
	m_flags = 0;
	m_flags|= TokenizeSymbols;
	m_flags|= KeepWhiteToken;
	m_flags|= UnquoteString;
	m_flags|= TerminateAtNewLine;

	/* set defaults */
	m_symbols = _def_symbols;
	m_white_chars = _def_white_chars;
	m_string_quote = DoubleQuote;
	m_newline_pair = NewlineCRLF;
}

Tokenizer::~Tokenizer () {
}

int Tokenizer::GetFlags() const {
	return m_flags;
}

void Tokenizer::SetFlags (int flags) {
	m_flags = flags;
}

void Tokenizer::SetSymbols (const sys_tchar *symbols) {
	m_symbols = symbols;
}

void Tokenizer::SetWhiteChars (const sys_tchar *white_chars) {
	m_white_chars = white_chars;
}

void Tokenizer::SetStringQuote (StringQuote quote) {
	m_string_quote = (quote == SingleQuote ? SingleQuote : DoubleQuote);
}

void Tokenizer::SetNewlinePair (NewlinePair newline_pair) {
	m_newline_pair = newline_pair;
}

bool Tokenizer::IsWhitespaceToken (const Token &token) {
	return token.length == 0 && token.string[0] != _tx('\'');
}

size_t Tokenizer::Tokenize (sys_tchar **pinput, Token *token_buffer, size_t max_tokens) {
    sys_tchar *head, *tail;
    bool flag_sym;
	bool flag_white;
	bool flag_quote;
	bool flag_tokenize_symbol;
	bool flag_keep_white_token;
	sys_tchar ch;
	sys_tchar quote_char;
	sys_tchar newline_chars[2];
	size_t num_tokens;
	TokenType token_type;

	/* init vars */
    num_tokens = 0;
	flag_sym = false;
	flag_quote = false;
	flag_tokenize_symbol = m_flags & TokenizeSymbols;
	flag_keep_white_token = m_flags & KeepWhiteToken;
	quote_char = (m_string_quote == SingleQuote ? _tx('\'') : _tx('\"'));

	if (m_newline_pair == NewlineCRLF) {
		newline_chars[0] = _tx('\r');
		newline_chars[1] = _tx('\n');
	} else /*if (m_newline_pair == NewlineCRLF)*/ {
		newline_chars[0] = _tx('\n');
		newline_chars[1] = _tx('\r');
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
		if ( *head == _tx('\0') ) {
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

#if _DEBUG
void Tokenizer::DumpToken (const Tokenizer::Token &token) {
	sys_tchar *temp;
	if (token.length == 0) {
		temp = new sys_tchar [ 2 ];
	} else {
		temp = new sys_tchar [ token.length + 1 ];
	}
	
	if (token.length == 0) {
		temp[0] = token.type == WhiteToken ? _tx(' ') : _tx('\0');
		temp[1] = _tx('\0');
	} else {
		sys_tstrncpy (temp, token.string, token.length);		
		temp[token.length] = 0;
	}
	switch (token.type) {
	case StringToken:
		sys_tprintf (_tx("STRING"), temp);
		break;
	case SymbolToken:
		sys_tprintf (_tx("SYMBOL"), temp);
		break;
	case WhiteToken:
		sys_tprintf (_tx("WHITE "), temp);
		break;
	default:
		sys_tprintf (_tx("WORD  "), temp);
		break;
	}
	sys_tprintf (_tx("  ~%s~  "), temp);
	sys_tprintf (_tx("%lu"), token.length);
	delete temp;
}

void Tokenizer::DumpTokens (const Tokenizer::Token *tokens, size_t length) {
	for (size_t i=0; i < length; i++) {
		DumpToken (tokens[i]);
		sys_tprintf (_tx("\n"));
	}
}
#endif

inline bool Tokenizer::IsWhite (sys_tchar ch) const {
	return (sys_tstrchr (m_white_chars, ch) != NULL);
}

inline bool Tokenizer::IsSymbol (sys_tchar ch) const {
	return (sys_tstrchr (m_symbols, ch) != NULL);
}

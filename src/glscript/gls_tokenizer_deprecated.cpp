/**
 * tokenizer.cpp    Simple and fast string tokenizer for C++
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

 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "stdafx.h"
#include <glscript/gls_tokenizer.h>

namespace gls
{

/* static */
template <typename _CharType>
const _CharType *Tokenizer<_CharType>::_def_symbols = 
_tx("~~!@#$%^&*()_+-={}[]:\";'<>?,./|\\");

template <typename _CharType>
const _CharType *Tokenizer<_CharType>::_def_white_chars = 
_tx("\r\n\f\t ");


} // gls namespace


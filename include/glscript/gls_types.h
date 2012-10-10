//
// gls_types.h  glscript basic type definitions.
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
#ifndef __GLSCRIPT_TYPES_H__
#define __GLSCRIPT_TYPES_H__

#include <glscript/gls_macros.h>

// define current glscript version
#define GLS_VERSION		GLS_VERSION_MAKE_LONG(0,0,0,8)

// define calling convention for dynamic extension modules
#if defined (WIN32)
#define GLS_API_CALL __stdcall
#else
#define GLS_API_CALL
#endif

// define universal string 
#if defined(UNICODE) || defined(_UNICODE)
typedef std::wstring tstring;
#else
typedef std::string tstring; 
#endif

// define interface macros
#define GLS_BEGIN_INTERFACE(_I) \
class _I { public:

#define GLS_END_INTERFACE };

#endif /* !__GLSCRIPT_TYPES_H__ */

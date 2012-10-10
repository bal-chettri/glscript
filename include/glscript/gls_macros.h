//
// gls_macros.h  glscript library macros.
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
#ifndef __GLSCRIPT_MACROS_H__
#define __GLSCRIPT_MACROS_H__

// define version encoding / decoding macros

#define GLS_VERSION_MAKE_SHORT(M,N) \
((unsigned short)N<<8|(unsigned short)M)

#define GLS_VERSION_MAKE_LONG(M,N,R,B) \
((unsigned long)B<<24|(unsigned long)R<<16| \
 (unsigned long)N<<8|(unsigned long)M)

#define GLS_VERSION_MAKE_TINY(M) \
((unsigned char)M)

#define GLS_VERSION_GET_MAJOR(Ver) \
((unsigned char)Ver)

#define GLS_VERSION_GET_MINOR(Ver) \
(unsigned char)((unsigned short)Ver >> 8 & 0x00FF)

#define GLS_VERSION_GET_REVISION(Ver) \
(unsigned char)((unsigned long)Ver >> 16 & 0x000000FF)

#define GLS_VERSION_GET_BUILD(Ver) \
(unsigned char)((unsigned long)Ver >> 24 & 0x000000FF)

#endif /* !__GLSCRIPT_MACROS_H__ */

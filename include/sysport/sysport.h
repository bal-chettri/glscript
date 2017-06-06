/**
 * sysport.h        Portable type definitions and macros for universal string manipulation.
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
 *
 * Last Updated: Nov 02 2011
 */
#ifndef __SYSPORT_H
#define __SYSPORT_H

/* portable types */
typedef char sys_char;
typedef wchar_t sys_wchar;

/* define sys_tchar */
#if defined(UNICODE) || defined(_UNICODE)
 typedef sys_wchar sys_tchar;
#else
 typedef sys_char sys_tchar;
#endif

/* This macro constructs a generic universal string */
#ifndef _tx
 #if defined(UNICODE) || defined(_UNICODE)
  #define _tx(S) L##S
 #else
  #define _tx(S) S
 #endif
#endif

/* unsigned types  */
typedef unsigned char sys_byte;
typedef unsigned short sys_ushort;
typedef unsigned long sys_ulong;

/* fixed sized typed */
typedef char sys_int8;
typedef short sys_int16;
typedef long sys_int32;
typedef unsigned char sys_uint8;
typedef unsigned short sys_uint16;
typedef unsigned long sys_uint32;

/* universal portable string functions */
#if defined(UNICODE) || defined(_UNIDODE)

/* string */
#define sys_tstrcpy wcscpy
#define sys_tstrncpy wcsncpy
#define sys_tstrlen wcslen
#define sys_tstrcmp wcscmp
#define sys_tstrstr wcsstr
#define sys_tstrchr wcschr

/* I/O */
#define sys_tprintf wprintf
#define sys_tsprintf wsprintf
#define sys_tscanf wscanf

#else /* UNICODE */

/* string */
#define sys_tstrcpy strcpy
#define sys_tstrncpy strncpy
#define sys_tstrlen strlen
#define sys_tstrcmp strcmp
#define sys_tstrstr strstr
#define sys_tstrchr strchr

/* I/O */
#define sys_tprintf printf
#define sys_tsprintf sprintf
#define sys_tscanf scanf

#endif /* !UNICODE */

#endif /* __SYSPORT_H */

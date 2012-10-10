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
#ifndef __GLSCRIPT_RUN_CONFIG_H
 #define __GLSCRIPT_RUN_CONFIG_H

/* App title */
#define GLSRUN_APP_TITLE						_T("glsrun")

/* App version */
#define GLSRUN_APP_VER_MAJ						0
#define GLSRUN_APP_VER_MIN						0
#define GLSRUN_APP_VER_REV						0
#define GLSRUN_APP_VER_BUILD					8

// obfuscate strings
#define GLSRUN_APP_OBFUSCATE

#ifdef UNICODE
#define GLSRUN_APP_OBFUSCATOR_KEY				0x91f7
#else
#define GLSRUN_APP_OBFUSCATOR_KEY				0x7c
#endif

/* define obfuscated string maker */
#ifdef GLSRUN_APP_OBFUSCATE
#define _OT(_C)									_T(_C ^ GLSRUN_APP_OBFUSCATOR_KEY)
#else
#define _OT(_C)									_T(_C)
#endif

/* obfuscated strings */

#define GLSRUN_APP_VER_STRING \
{ \
_OT('0'), _OT('.'), _OT('0'), _OT('.'), _OT('0'), _OT('.'), _OT('8'), _T('\0') \
};

#define GLSRUN_DEV_NAME \
{ \
_OT('B'), _OT('a'), _OT('l'), _OT(' '), \
_OT('B'), _OT('a'), _OT('h'), _OT('a'), _OT('d'), _OT('u'), _OT('r'), _OT(' '), \
_OT('C'), _OT('h'), _OT('e'), _OT('t'), _OT('t'), _OT('r'), _OT('i'), \
_T('\0') \
};

#define GLSRUN_ABOUT_TITLE \
{ \
_OT('g'),_OT('l'),_OT('s'),_OT('r'),_OT('u'),_OT('n'), _T('\0') \
};

#define GLSRUN_ABOUT_DESC \
{ \
_OT('T'), _OT('h'), _OT('i'), _OT('s'), _OT(' '), _OT('p'), _OT('r'), _OT('o'), \
_OT('g'), _OT('r'), _OT('a'), _OT('m'), _OT(' '), _OT('i'), _OT('s'), _OT(' '), \
_OT('a'), _OT(' '), _OT('p'), _OT('a'), _OT('r'), _OT('t'), _OT(' '), _OT('o'), \
_OT('f'), _OT(' '), _OT('t'), _OT('h'), _OT('e'), _OT(' '), _OT('g'), _OT('l'), \
_OT('S'), _OT('c'), _OT('r'), _OT('i'), _OT('p'), _OT('t'), _OT(' '), _OT('s'), \
_OT('o'), _OT('f'), _OT('t'), _OT('w'), _OT('a'), _OT('r'), _OT('e'), _OT('.'), \
_T('\0') \
};

/* Common dialog constants */
#define GLSRUN_APP_CMNDLG_FILTERS				_T("glScript Files (*.gls)\0") \
												_T("*.gls\0") \
												_T("gls JavaScript Files (*.js)\0") \
												_T("*.js\0") \
												_T("gls VBScript Files (*.vbs)\0") \
												_T("*.vbs\0") \
												_T("All Files (*.*)\0") \
												_T("*.*\0") \
												_T("\0")

#define GLSRUN_APP_CMNDLG_DEFEXT				_T("gls")

/* b2code API Constants */
#ifdef _DEBUG
	#define WEBSITE_URL_BASE					_T("http://code.google.com/p/glscript")
#else
	#define WEBSITE_URL_BASE					_T("http://code.google.com/p/glscript")
#endif

#define SUPPORT_WEBSITE_URL						_T("v=synopsis")
#define CHECK_FOR_UPDATES_URL					_T("v=download&show_updates=1&client_ver=%s")
#define SUPPORT_SHARE_APP_URL					_T("v=share")

// default GL view size
#define DEF_GLS_VIEW_WIDTH						480
#define DEF_GLS_VIEW_HEIGHT						320

#endif /* __GLSCRIPT_RUN_CONFIG_H */

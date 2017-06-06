//
// gls_activescript_console.h  glscript Console class.
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
#ifndef __GLSCRIPT_ACTIVESCRIPT_CONSOLE_H__
#define __GLSCRIPT_ACTIVESCRIPT_CONSOLE_H__

// prevent direct inclusion of this header file.
#ifndef __GLSCRIPT_ACTIVESCRIPT_HOST_H__
#error "Do not include this header directly. Include gls_activescript_host.h instead."
#endif

// externs...
extern const IID *GLScript_Console_IIDs[];

// GLScript_Console class...
class GLScript_Console : public AutomationContainedComObject<
                                    _GLScript_Console, 
                                    GLScript_Console_IIDs, 
                                    &IID__GLScript_Console> 
{
public:
    // ctor
    GLScript_Console (IUnknown *pParent) 
        : AutomationContainedComObject (pParent) 
    { }

public:
    // _GLScript_Conole methods...
    HRESULT STDMETHODCALLTYPE log (VARIANT msg);
    HRESULT STDMETHODCALLTYPE warn (VARIANT msg);
    HRESULT STDMETHODCALLTYPE error (VARIANT msg);
    HRESULT STDMETHODCALLTYPE clear ();

private:
    HRESULT _log (const VARIANT &msg, gls::GLSCRIPT_LOGTYPE log_type);
};

#endif /* __GLSCRIPT_ACTIVESCRIPT_CONSOLE_H__ */

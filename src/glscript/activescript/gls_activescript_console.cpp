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

#if defined(WIN32)
#include <glscript/activescript/gls_activescript_host.h>
#include <glscript/activescript/gls_activescript_marshal.h>

using namespace gls;

// define externs...
const IID *GLScript_Console_IIDs[] = {
    &IID_IUnknown,
    &IID_IDispatch,
    &IID__GLScript_Console,
    NULL
};

// GLScript_Console class definition...

HRESULT STDMETHODCALLTYPE GLScript_Console::log (VARIANT msg) {
    return _log (msg, GLScriptLogTypeMessage);
}

HRESULT STDMETHODCALLTYPE GLScript_Console::warn (VARIANT msg) {
    return _log (msg, GLScriptLogTypeWarning);
}

HRESULT STDMETHODCALLTYPE GLScript_Console::error (VARIANT msg) {
    return _log (msg, GLScriptLogTypeError);
}

HRESULT STDMETHODCALLTYPE GLScript_Console::clear () {
    GLScriptHost_Win32 *pHost = reinterpret_cast<GLScriptHost_Win32 *>(GetParent());
    if (pHost->m_pEventListener != NULL) {
        pHost->m_pEventListener->ScriptHost_OnLogClear ();
    }
    return NOERROR;
}

HRESULT GLScript_Console::_log (const VARIANT &msg, GLSCRIPT_LOGTYPE log_type) {
    if (msg.vt == VT_BSTR) {
        GLScriptHost_Win32 *pHost = reinterpret_cast<GLScriptHost_Win32 *>(GetParent());

        if (pHost->m_pEventListener != NULL) {
            sys_tchar *message;

            #if defined(_UNICODE) || defined(UNICODE)
                message = msg.bstrVal;
            #else
                UINT length = SysStringLen(msg.bstrVal);
                message = new sys_char [length + 1];
                wcstombs(message, msg.bstrVal, length);
                message [length] = '\0';
            #endif
            
            pHost->m_pEventListener->ScriptHost_OnLogMessage (message, log_type);

            #if !defined(_UNICODE) && !defined(UNICODE)
                delete message;
            #endif
        }

        return NOERROR;
    } else {
        return E_INVALIDARG;
    }
}

#endif // WIN32

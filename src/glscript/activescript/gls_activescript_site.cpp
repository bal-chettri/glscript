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
#include <assert.h>

#ifdef _DEBUG
 #define ASSERT assert
#else
 #define ASSERT
#endif

// define externs...
const IID *GLScript_ActiveScriptSite_IIDs[] = {
    &IID_IUnknown,
    &IID_IActiveScriptSite,
    NULL
};

// GLScript_ActiveScriptSite class definition...

// IActiveScriptSite methods...
HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::GetLCID (LCID *plcid) {
    if (plcid == NULL) {
        return E_POINTER;
    }

    // return the system default locale
    *plcid = LOCALE_SYSTEM_DEFAULT;

    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::GetItemInfo (LPCOLESTR pstrName, DWORD dwReturnMask, 
                                                                IUnknown **ppiunkItem, ITypeInfo **ppti)
{
    if (!ppiunkItem) {
        return E_POINTER;
    }
    
    *ppiunkItem = NULL;
    
    // check for invalid mask
    if (
        !(dwReturnMask & SCRIPTINFO_IUNKNOWN) && 
        !(dwReturnMask & SCRIPTINFO_ITYPEINFO)
        )
        return E_INVALIDARG;

    // find the named object in the map and return the IUnknwon interface if found
    if (dwReturnMask & SCRIPTINFO_IUNKNOWN) {
        std::map<std::wstring, IUnknown *>::iterator pos = m_host_objects.find (pstrName);        
        if ( pos != m_host_objects.end() ) {
            *ppiunkItem = pos->second;
        }
    }

    // AddRef the interface being returned
    if (*ppiunkItem != NULL) {
        (*ppiunkItem)->AddRef ();
    } else {
        return TYPE_E_ELEMENTNOTFOUND;
    }

    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::GetDocVersionString (BSTR *pbstrVersion) {
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::OnScriptTerminate (const VARIANT *pvarResult, 
                                                                        const EXCEPINFO *pexcepinfo) 
{
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::OnStateChange (SCRIPTSTATE ssScriptState) {
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::OnScriptError (IActiveScriptError *pscripterror) {     
    // get parent script host object
    GLScriptHost_Win32 *pHost = GetHostObject ();
    
    // stop the animation on error
    pHost->m_engine.StopAnimation ();   

    if (pHost->m_pEventListener != NULL) {
        LPCTSTR lpszMsg = ProcessExceptionInfo (pscripterror);      
        if (lpszMsg) {
            // notify the host's event listener about the error
            pHost->m_pEventListener->ScriptHost_OnError (pHost, lpszMsg);
            delete lpszMsg;
        } else {
            // notify the host's event listener about the error
            pHost->m_pEventListener->ScriptHost_OnError (pHost, _tx("Unknown exception occured."));
        }
    }

    // set the error flag
    pHost->m_error = true;

    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::OnEnterScript (void) {
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_ActiveScriptSite::OnLeaveScript (void) {
    return NOERROR;
}

// public methods...

void GLScript_ActiveScriptSite::AddHostObject (LPCOLESTR name, IUnknown *p_com_object) {
    ASSERT (p_com_object != NULL);

    std::map<std::wstring, IUnknown *>::iterator pos = m_host_objects.find (name);
    ASSERT (pos == m_host_objects.end ());

    p_com_object->AddRef ();
    m_host_objects[name] = p_com_object;
}

void GLScript_ActiveScriptSite::RemoveHostObject (LPCOLESTR name) {
    std::map<std::wstring, IUnknown *>::iterator pos = m_host_objects.find (name);
    ASSERT (pos != m_host_objects.end ());

    IUnknown *p_com_object = pos->second;
    
    m_host_objects.erase (pos);

    p_com_object->Release ();
}

void GLScript_ActiveScriptSite::RemoveAllHostObjects () {
    std::map<std::wstring, IUnknown *>::iterator 
        pos = m_host_objects.begin (),
        pos_end = m_host_objects.end ();

    // release all objects in the map first
    for (; pos != pos_end; pos++) {
        IUnknown *p_com_object = pos->second;
        p_com_object->Release ();
    }

    // clear the map
    m_host_objects.clear ();
}

// private methods...

LPCTSTR GLScript_ActiveScriptSite::ProcessExceptionInfo (IActiveScriptError *pScriptError) {    
    // get exception info
    EXCEPINFO excepInfo;
    const EXCEPINFO *pExcepInfo = &excepInfo;   
    HRESULT hr = pScriptError->GetExceptionInfo (&excepInfo);
    if (FAILED(hr)) {
        return NULL; // no exception info to return
    }

    // get source line script where error occured
    BSTR bstrErrorText;
    BOOL bHasErrorText;
    hr = pScriptError->GetSourceLineText (&bstrErrorText);
    bHasErrorText = (!FAILED(hr));

    // get source error position information
    DWORD source_context;
    ULONG line_pos;
    LONG char_pos;
    BOOL bHasSourcePosInfo;
    hr = pScriptError->GetSourcePosition (&source_context, &line_pos, &char_pos);
    bHasSourcePosInfo = (!FAILED(hr));

    // calculate the rough length of error message buffer in wide chracters
    size_t length = 0;
    const size_t LEN_BUFF_EXTRA = 512;  

    if (pExcepInfo->bstrSource) {
        length+= SysStringLen(pExcepInfo->bstrSource);
    }
    if (pExcepInfo->bstrDescription) {
        length+= SysStringLen(pExcepInfo->bstrDescription);
    }
    if (bHasErrorText) {
        length+= SysStringLen(bstrErrorText);
    }
    // keep enough space for newline characters and title strings
    length+= (LEN_BUFF_EXTRA);

    // allocate wide character buffer for the error message
    sys_wchar *wide_buffer = new sys_tchar [length + 1];
    if (wide_buffer == NULL) {
        return NULL; // failed to allocate memory
    }

    // format the error message
    wsprintf (wide_buffer, L"Error: %u", pExcepInfo->wCode);
    if (bHasSourcePosInfo) {
        wsprintf (wide_buffer + wcslen(wide_buffer), L", Line: %u, Char: %d\r\n", 
                    line_pos, char_pos);
    } else {
        wsprintf (wide_buffer + wcslen(wide_buffer), L"\r\n");
    }
    if (pExcepInfo->bstrSource) {
        wsprintf (wide_buffer + wcslen(wide_buffer), L"%s\r\n", pExcepInfo->bstrSource);
    }
    if (pExcepInfo->bstrDescription) {
        wsprintf (wide_buffer + wcslen(wide_buffer), L"%s\r\n", pExcepInfo->bstrDescription);
    }
    if (bHasErrorText) {
        wsprintf (wide_buffer + wcslen(wide_buffer), L"%s\r\n", bstrErrorText);
        // free error source text when done
        ::SysFreeString (bstrErrorText);
    }
    
    #if defined(_UNICODE) || defined(UNICODE)
        return wide_buffer;
    #else
        // get the exact length of string required in ASCII
        length = wcslen (wide_buffer);

        // allocate ascii buffer
        sys_char *ascii_buffer = new sys_char [ length + 1 ];
        if (ascii_buffer == NULL) {
            delete wide_buffer;
            return NULL;
        }

        // convert to ascii format
        wcstombs (ascii_buffer, wide_buffer, wcslen(length);
        ascii_buffer [length] = '\0';

        // delete the wide buffer
        delete wide_buffer;

        return ascii_buffer;
    #endif
}

#endif // WIN32

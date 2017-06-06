//
// gls_activescript_site.h  glscript IActiveScriptSite implementation class.
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
/**
 * gls_activescript_site.h
 * 
 * Implements the IActiveScriptSite interface for GLScriptHost_Win32 class.
 * This header is included by gls_activescript_host.h header file. Please do
 * not include it directly.
 *
 * Author:      Bal Bahadur Chettri
 */
#ifndef __GLSCRIPT_ACTIVESCRIPT_SITE_H__
#define __GLSCRIPT_ACTIVESCRIPT_SITE_H__

// prevent direct inclusion of this header file.
#ifndef __GLSCRIPT_ACTIVESCRIPT_HOST_H__
#error "Do not include this header directly. Include gls_activescript_host.h instead."
#endif

// externs...
extern const IID *GLScript_ActiveScriptSite_IIDs [];

// GLScript_ActiveScriptSite class...
class GLScript_ActiveScriptSite : 
    public AutomationContainedComObject<IActiveScriptSite, GLScript_ActiveScriptSite_IIDs>
{
public:
    // Constructor
    GLScript_ActiveScriptSite (IUnknown *parent) 
        : AutomationContainedComObject(parent) 
    { }

    // Destructor
    virtual ~GLScript_ActiveScriptSite () {
        RemoveAllHostObjects ();
    }

    // IActiveScriptSite methods...
public:
    virtual HRESULT STDMETHODCALLTYPE GetLCID (LCID *plcid);
    virtual HRESULT STDMETHODCALLTYPE GetItemInfo (LPCOLESTR pstrName, DWORD dwReturnMask, 
                                                    IUnknown **ppiunkItem, ITypeInfo **ppti);        
    virtual HRESULT STDMETHODCALLTYPE GetDocVersionString (BSTR *pbstrVersion);        
    virtual HRESULT STDMETHODCALLTYPE OnScriptTerminate (const VARIANT *pvarResult, 
                                                         const EXCEPINFO *pexcepinfo);
    virtual HRESULT STDMETHODCALLTYPE OnStateChange (SCRIPTSTATE ssScriptState);        
    virtual HRESULT STDMETHODCALLTYPE OnScriptError (IActiveScriptError *pscripterror);        
    virtual HRESULT STDMETHODCALLTYPE OnEnterScript (void);        
    virtual HRESULT STDMETHODCALLTYPE OnLeaveScript (void);

    // public operations ...
public:
    void AddHostObject (LPCOLESTR name, IUnknown *p_com_object);
    void RemoveHostObject (LPCOLESTR name);
    void RemoveAllHostObjects ();

private:
    inline GLScriptHost_Win32 *GetHostObject () {
        return reinterpret_cast<GLScriptHost_Win32 *>(GetParent());
    }
    
    /** Processes the generic COM exception info and return an error message appropriate 
    to be displayed in a UI. */
    LPCTSTR ProcessExceptionInfo (IActiveScriptError *pScriptError);

private:
    std::map<std::wstring,IUnknown *>     m_host_objects;     // host defined COM objects
};

#endif /* __GLSCRIPT_ACTIVESCRIPT_SITE_H__ */

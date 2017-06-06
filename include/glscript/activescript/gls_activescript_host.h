//
// gls_activescript_host.h  glscript ScriptHost implementation class.
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
#ifndef __GLSCRIPT_ACTIVESCRIPT_HOST_H__
#define __GLSCRIPT_ACTIVESCRIPT_HOST_H__

#ifndef WIN32
#error This header requires WIN32 platform.
#endif

#include <com/dispatch.h>
#include <com/class_factory.h>
#include <glscript/gls_obj.h>
#include <glscript/gls_scripthost.h>
#include <glscript/gls_extension.h>

// common activescript headers...
#include "gls_activescript_interfaces.h"
#include "gls_activescript_array.h"

/* forward declarations */
class GLScriptHost_Win32;

// contained COM objects...
#include "gls_activescript_site.h"
#include "gls_activescript_ext_host.h"
#include "gls_activescript_engine.h"
#include "gls_activescript_context.h"
#include "gls_activescript_console.h"

// externs...
extern const IID *GLScriptHost_Win32_IIDs[];
extern ClassFactory<GLScriptHost_Win32> GLScriptHost_Win32_Factory;

// GLScriptHost_Win32 class...
class GLScriptHost_Win32 :
        public AutomationComObject<IUnknown, GLScriptHost_Win32_IIDs>,
        public gls::ScriptHost
{
    // ScriptHost functions...
public: 
    void SetEventListener (gls::ScriptHostEvents *pEventListener);
    void RemoveEventListener ();
    gls::GLSCRIPT_HOST_STATE GetState ();
    bool SetWindowContext (gls::GLSCRIPT_WINDOW_CONTEXT *context);
    bool SetScriptSource (gls::ScriptSource *pScriptSource);
    bool ExecuteScriptConfigurationPhase ();
    bool ExecuteScriptRenderPhase ();
    bool PauseRenderLoop ();
    bool ResumeRenderLoop ();
    bool InvokeScriptMethod (const sys_tchar *method_name, gls::GLSCRIPT_PARAM *arr_params, 
                                int count_params);
    void UnloadScript ();

protected:
    /* ctor */
    GLScriptHost_Win32();
    virtual ~GLScriptHost_Win32 ();

protected:
    // protected internal functions 

    /** Loads the active scripting engine object */
    bool LoadScriptEngine ();

    /** Unloads the active scripting engine object */
    void UnloadScriptEngine ();

    /** Initializes the script engine and script site objects to their default state */
    bool InitScriptEngine ();

    /** Sets the internal state of the host object */
    void SetState (gls::GLSCRIPT_HOST_STATE state);

    /** Generates a host error message to the event listener */
    inline void RaiseHostError (LPCTSTR lpszErrorMessage);

    /** Retursn the CLSID of script engine to use for the current script source */
    BOOL GetScriptEngineCLSID (LPCLSID pclsid);

    /** Returns the script engine CLSID from the language name */
    BOOL GetScriptEngineCLSIDFromProgID (LPCTSTR language, LPCLSID clsid);

    /** Returns the script engine CLSID from the file extension */
    BOOL GetScriptEngineCLSIDFromFileExtension (LPCTSTR lpszExtension, LPCLSID clsid);  

private:
    // current script source object
    gls::ScriptSource               *m_pScriptSource;   // script source object
    
    // script engine and context info
    IActiveScript                   *m_pScriptEngine;   // scripting engine
    gls::ScriptHostEvents   *m_pEventListener;  // host event listener
    gls::GLSCRIPT_HOST_STATE        m_state;            // host state
    gls::GLSCRIPT_WINDOW_CONTEXT    m_windowContext;    // GL window context
    bool                            m_error;            // error flag
    
    GLScript_ActiveScriptSite       m_site;             // IActiveScriptSite object
    GLScript_ExtensionHost          m_ext_host;         // ExtensionHost object

    // glScript scripting objects
    GLScript_Engine                 m_engine;           // gls
    GLScript_Context                m_glContext;        // gl
    GLScript_Console                m_console;          // console

    // all sub objects are friend classes
    friend class GLScript_ActiveScriptSite;
    friend class GLScript_ExtensionHost;
    friend class GLScript_Context;
    friend class GLScript_Engine;
    friend class GLScript_Console;
    friend class ClassFactory<GLScriptHost_Win32>;
};

#endif /* __GLSCRIPT_ACTIVESCRIPT_HOST_H__ */

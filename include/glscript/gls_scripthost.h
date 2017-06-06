//
// gls_scripthost.h  glscript script host interfaces.
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
#ifndef __GLSCRIPT_SCRIPTHOST_H__
#define __GLSCRIPT_SCRIPTHOST_H__

#include <glscript/gls_types.h>
#include <glscript/gls_obj.h>
#include <glscript/gls_script_source.h>
#include <sysport/sysport.h>

namespace gls {

/* constants */
#define GLSCRIPT_WINDOW_TITLE_MAX_LEN               255

/** GLScriptHostState enum */
enum GLSCRIPT_HOST_STATE {
    kScriptHostStateReady,                          /** host is ready */
    kScriptHostStateLoading,                        /** host is loading */
    kScriptHostStateLoaded,                         /** host has finished loading */
    kScriptHostStateRunningConfigPhase,             /** host is configuring the engine */
    kScriptHostStateConfigured,                     /** host is done configuring the engine */
    kScriptHostStateConfigError,                    /** host is in configuration error state */
    kScriptHostStateRunningRenderPhase,             /** host is rendering */
    kScriptHostStatePausedRenderPhase,              /** host has paused rendering */
    kScriptHostStateBusy,                           /** host is busy */
    kScriptHostStateError                           /** host is error state */
};

/** GLSCRIPT_PARAM struct */
#ifdef WIN32
 typedef VARIANTARG GLSCRIPT_PARAM;
#else
 struct GLSCRIPT_PARAM {
 };
#endif

typedef GLSCRIPT_PARAM *GLSCRIPT_PARAMS;

/** GLSCRIPT_WINDOW_CONTEXT struct */
struct GLSCRIPT_WINDOW_CONTEXT {
    /* OS specific window handle */
    void *hWnd;
#ifdef WIN32
    HDC hdc;
    HGLRC hglrc;
#endif
};

/** GLSCRIPT_WINDOW_CONFIG struct */
struct GLSCRIPT_WINDOW_CONFIG {
    /* win size */
    GLsizei wincx;                                  /** window width */
    GLsizei wincy;                                  /** window height */
    /* viewport */
    GLint vpx;                                      /** viewport left */
    GLint vpy;                                      /** viewport top */
    GLint vpcx;                                     /** viewport width */
    GLint vpcy;                                     /** viewport height */
    /* view type */
    bool ortho;                                     /** orthographic mode */
    /* win other attributes */
    sys_tchar title                                 /** window title text */
    [GLSCRIPT_WINDOW_TITLE_MAX_LEN + 1];
};

/** GLSCRIPT_LOGTYPE enum */
enum GLSCRIPT_LOGTYPE {
    GLScriptLogTypeMessage,                         /** general log message */
    GLScriptLogTypeWarning,                         /** warning log message */
    GLScriptLogTypeError                            /** error log message */
};

// forward declarations...
class ScriptHost;

/** ScriptHostEvents interface */
class ScriptHostEvents {
public:
    /** Script host encountered an error */
    virtual void ScriptHost_OnError (ScriptHost *pHost, const sys_tchar *error_message) = 0;
    
    /** Script host changed its state */
    virtual void ScriptHost_OnChangeState (ScriptHost *pHost, GLSCRIPT_HOST_STATE from_state, 
                                            GLSCRIPT_HOST_STATE to_state) = 0;

    /** Script host needs to configure the OpenGL window */
    virtual void ScriptHost_OnConfigureWindow (const GLSCRIPT_WINDOW_CONFIG &config) = 0;

    /** Script host want to log a message to a console */
    virtual void ScriptHost_OnLogMessage (const sys_tchar *message, GLSCRIPT_LOGTYPE log_type) = 0;

    /** Script host wants to clear the console log */
    virtual void ScriptHost_OnLogClear () = 0;

}; /* ScriptHostEvents */ 

/** ScriptHost interface */
GLS_BEGIN_INTERFACE (ScriptHost)
    /** sets the event listener */
    virtual void SetEventListener (ScriptHostEvents *pEventListener) = 0;

    /** removes the event listener */
    virtual void RemoveEventListener () = 0;

    /** returns the current state of the host */
    virtual GLSCRIPT_HOST_STATE GetState () = 0;

    /** sets the window context for the underlying script engine */
    virtual bool SetWindowContext (GLSCRIPT_WINDOW_CONTEXT *context) = 0;
    
    /** sets the script source to run */
    virtual bool SetScriptSource (ScriptSource *pScriptSource) = 0;
        
    /** parses and execute the script as configuration phase */
    virtual bool ExecuteScriptConfigurationPhase () = 0;

    /** executes the script as render phase */
    virtual bool ExecuteScriptRenderPhase () = 0;

    /** pauses the render loop */
    virtual bool PauseRenderLoop () = 0;

    /** resumes the render loop */
    virtual bool ResumeRenderLoop () = 0;

    /** Invoke a method in the script */
    virtual bool InvokeScriptMethod (const sys_tchar *method_name, GLSCRIPT_PARAM *arr_params, 
                                     int count_params) = 0;

    /* Unload the script */
    virtual void UnloadScript () = 0;
GLS_END_INTERFACE /* ScriptHost */ 

}; // gls namespace 

#endif /* __GLSCRIPT_SCRIPTHOST_H__ */

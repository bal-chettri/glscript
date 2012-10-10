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

using namespace gls;

// define externs...
const IID *GLScriptHost_Win32_IIDs[] = {
	&IID_IUnknown,
	NULL
};

ClassFactory<GLScriptHost_Win32> GLScriptHost_Win32_Factory;

// GLScriptHost_Win32 class definition...

GLScriptHost_Win32::GLScriptHost_Win32() : 
	m_site (this),
	m_ext_host (this),
	m_engine (this),
	m_glContext (this),
	m_console (this)
{	
	// init vars to defaults
	m_pScriptSource = NULL;
	
	m_pScriptEngine = NULL;
	m_pEventListener = NULL;
	m_state = kScriptHostStateReady;

	// initialize window context to known state	
	memset (&m_windowContext, 0, sizeof(m_windowContext));

	m_error = false;
}

GLScriptHost_Win32::~GLScriptHost_Win32 () {
	// unload current script
	UnloadScript ();
}

// ScriptHost interface implementation...

void GLScriptHost_Win32::SetEventListener (ScriptHostEvents *pEventListener) {
	m_pEventListener = pEventListener;
}

void GLScriptHost_Win32::RemoveEventListener () {
	m_pEventListener = NULL;
}

// returns the current state of the script host
GLSCRIPT_HOST_STATE GLScriptHost_Win32::GetState () {
	return m_state;
}

// sets the window context in ready state
bool GLScriptHost_Win32::SetWindowContext (GLSCRIPT_WINDOW_CONTEXT *context) {
	// window context may be set only in the ready state
	if (m_state != kScriptHostStateReady) {
		return false;
	}

	if (context == NULL) {
		return false;
	}

	// copy window context data
	memcpy (&m_windowContext, context, sizeof(m_windowContext));
	return true;
}

// sets the script source to run
bool GLScriptHost_Win32::SetScriptSource (ScriptSource *pScriptSource) {
	// script source may not be changed in these states
	if (m_state == kScriptHostStateLoading ||
		m_state == kScriptHostStateRunningConfigPhase ||
		m_state == kScriptHostStateBusy)
	{
		// invalid state to set script source!
		return false;
	}

	// check if script source is NULL before we set it
	if (pScriptSource == NULL) {
		return false;
	}

	// unload current script and script engine first
	UnloadScript ();

	// save reference to the script source
	m_pScriptSource = pScriptSource;
	m_pScriptSource->AddRef ();

	// load the scripting engine
	if (LoadScriptEngine()) {
		SetState (kScriptHostStateLoaded);
		return true;
	}	

	return false;
}

// Executes the script in configuration phase
bool GLScriptHost_Win32::ExecuteScriptConfigurationPhase () {
	// check if script was successfully loaded
	if (m_state != kScriptHostStateLoaded) {
		return false;
	}

	IActiveScriptParse *pScriptParse;
	HRESULT hr;

	// reset variables and flags
	m_error = false;

	// query for IActiveScriptParse interface
	hr = m_pScriptEngine->QueryInterface (IID_IActiveScriptParse, (LPVOID *) &pScriptParse);
	if (FAILED(hr)) {
		RaiseHostError (_T("GLScriptHost_Win32: QueryInterface for IActiveScriptParse failed on script engine."));
		return false;
	}	

	// set script site
	IActiveScriptSite *pSite = reinterpret_cast <IActiveScriptSite *> (&m_site);
	hr = m_pScriptEngine->SetScriptSite (pSite);
	if (FAILED(hr)) {
		RaiseHostError (_T("GLScriptHost_Win32: SetScriptSite failed on script engine."));
		return false;
	}

	// initilize the script parser
	hr = pScriptParse->InitNew ();
	if (FAILED(hr)) {
		pScriptParse->Release ();
		RaiseHostError (_T("GLScriptHost_Win32: InitNew failed on engine's IActiveScriptParse."));
		return false;
	}

	// Now we've got everything we need, try to initialize the script engine
	// This will add all named items to the script engine's namespace
	if (!InitScriptEngine()) {
		pScriptParse->Release ();
		RaiseHostError (_T("GLScriptHost_Win32: InitScriptEngine failed."));
		return false;
	}

	// Hand over the script code from the script source object that was set previously using 
	// SetScriptSource () method for parsing by the script engine. Syntax errors / compile time
	// errors can occur at this stage and the script engine may call OnScriptError () method
	// on our site, which will process the error and notify the event listener.
	EXCEPINFO exceptionInfo;
	hr = pScriptParse->ParseScriptText (m_pScriptSource->GetCode(), NULL, NULL, NULL, 
										0, 0, SCRIPTTEXT_ISVISIBLE, NULL, &exceptionInfo); 
	if (FAILED(hr)) {
		// failed to parse the script code. Note that we don't notify the event listener
		// here since OnScriptError() does this.
		pScriptParse->Release ();
		return false;
	}

	// Since the script code was successfully parsed, it is ready for being executed so
	// tell the script engine that we are done with our stuff and it can start to execute the
	// code. So, put the script engine to STARTED and then RUNNING state so it begins executing 
	// the code. 
	// Run time errors can happen when the script is executed and the script engine may call 
	// OnScriptError () method on our site, which will process the error and notify the 
	// event listener. Note that we don't notify the event listener here too.

	// set our internal state first
	SetState (kScriptHostStateRunningConfigPhase);

	// set script state for the script engine
	hr = m_pScriptEngine->SetScriptState (SCRIPTSTATE_STARTED);
	hr = m_pScriptEngine->SetScriptState (SCRIPTSTATE_CONNECTED);
	
	// release the ActiveScriptParse interface when done
	pScriptParse->Release ();
	
	if (FAILED(hr)) {
		// run time error occured when executing the script!
		return false;
	}

	// m_error may be set by OnScriptError () if any errors occur during script execution
	// In such case, ExecuteScriptRenderPhase () should not be called.
	if (m_error) {
		SetState (kScriptHostStateConfigError);
		return false;
	}

	// build configuration info for the GL surface window
	GLSCRIPT_WINDOW_CONFIG windowConfig;
	memset (&windowConfig, 0, sizeof(windowConfig));

	BSTR window_title;
	m_engine.get_windowTitle (&window_title);
	::_tcsncpy (windowConfig.title, window_title, ::SysStringLen(window_title));
	::SysFreeString (window_title);

	m_engine.get_windowWidth (&windowConfig.wincx);
	m_engine.get_windowHeight (&windowConfig.wincy);
	m_engine.get_viewPortLeft (&windowConfig.vpx);
	m_engine.get_viewPortTop (&windowConfig.vpy);
	m_engine.get_viewPortWidth (&windowConfig.vpcx);
	m_engine.get_viewPortHeight (&windowConfig.vpcy);
	
	VARIANT_BOOL ortho;
	m_engine.get_ortho (&ortho);
	windowConfig.ortho = (ortho == VARIANT_TRUE ? true : false);

	// notify the event listener that host needs to configure the OpenGL window
	if (m_pEventListener) {
		m_pEventListener->ScriptHost_OnConfigureWindow (windowConfig);
	}

	// set internal stagte to configured.
	SetState (kScriptHostStateConfigured);
	return true;
}

// executes the script in render phase
bool GLScriptHost_Win32::ExecuteScriptRenderPhase () {
	// check if script engine was successfully configured
	if (m_state != kScriptHostStateConfigured) {
		return false;
	}

	// set internal state to render phase
	SetState (kScriptHostStateRunningRenderPhase);

	// call gls_init()
	if (!InvokeScriptMethod (_tx("gls_init"), NULL, 0) ) {
		SetState (kScriptHostStateError);
		return false;
	}

	// get the animation flag
	VARIANT_BOOL flagAnimation;
	m_engine.get_animation (&flagAnimation);

	if (flagAnimation == VARIANT_TRUE) {
		// stay in kScriptHostStateRunningRenderPhase and start rendering the scene
		m_engine.StartAnimation ();
	} else {
		// call gls_renderScene() once to render the scene
		if (!InvokeScriptMethod (_tx("gls_renderScene"), NULL, 0) ) {
			SetState (kScriptHostStateError);
			return false;
		}
		// reset state to loaded
		SetState (kScriptHostStateLoaded);
	}

	return true;
}

bool GLScriptHost_Win32::PauseRenderLoop () {
	if (m_state != kScriptHostStateRunningRenderPhase) {
		return false;
	}

	// pause the render timer
	m_engine.StopAnimation ();

	SetState (kScriptHostStatePausedRenderPhase);
	return true;
}

bool GLScriptHost_Win32::ResumeRenderLoop () {
	if (m_state != kScriptHostStatePausedRenderPhase) {
		return false;
	}

	// resume the render timer
	m_engine.StartAnimation ();

	SetState (kScriptHostStateRunningRenderPhase);
	return true;
}

bool GLScriptHost_Win32::InvokeScriptMethod (const sys_tchar *method_name, GLSCRIPT_PARAM *arr_params, 
											 int count_params) 
{
	// check for invalid state before we invoke the script method 
	if (m_state != kScriptHostStateConfigured && 
		m_state != kScriptHostStateLoaded &&
		m_state != kScriptHostStateRunningRenderPhase &&
		m_state != kScriptHostStatePausedRenderPhase) {		
		return false; // script host is in invalid state!
	}

	// check for invalid arguments
	if (!method_name || count_params < 0 || (count_params && !arr_params)) {
		return false; // invalid argument!
	}

	IDispatch *pScriptDispatch;
	HRESULT hr;	

	// get the script's IDispatch	interface
	hr = m_pScriptEngine->GetScriptDispatch (NULL, &pScriptDispatch);
	if (FAILED(hr)) {
		return false;
	}
	
	// convert method name to wide string format
	OLECHAR *oleszMethod;
	#if defined(UNICODE) || defined(_UNICODE)
		oleszMethod = (OLECHAR *)method_name;
	#else
		wchar_t wMethod[255]; // #TODO: use proper array size
		::mbstowcs (wMethod, method_name, sys_strlen(method_name));
		wMethod [sys_strlen(method_name)] = '\0';
		oleszMethod = wMethod;
	#endif

	// get DISPID of the method to invoke
	DISPID dispid;
	hr = pScriptDispatch->GetIDsOfNames (IID_NULL, &oleszMethod, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
	if (hr == DISP_E_UNKNOWNNAME) {
		pScriptDispatch->Release ();
		return true; // method was not defined the the script
	}
	
	// init dispparmas
	DISPPARAMS disp_params;
	memset (&disp_params, 0, sizeof(disp_params));
	disp_params.cArgs = count_params;
	disp_params.rgvarg = disp_params.cArgs > 0 ? new VARIANTARG [disp_params.cArgs] : NULL;
	if (disp_params.rgvarg == NULL && disp_params.cArgs > 0) {
		pScriptDispatch->Release ();
		return false; // failed to allocate VARIANTARG array
	}

	// fill in VARIANTARGs in DISPPARAMS structure
	if (disp_params.cArgs > 0) {
		for (int i = disp_params.cArgs-1; i >= 0; i--) {
			VARIANTARG *pArg = disp_params.rgvarg + i;
			*pArg = arr_params[i];
		}
	}

	// invoke the method
	UINT nArgErr = (UINT)-1;
	WORD wInvokeFlags = DISPATCH_METHOD;
	EXCEPINFO excepInfo;
	EXCEPINFO *pExcepInfo = &excepInfo;

	memset (pExcepInfo, 0, sizeof(EXCEPINFO));
	hr = pScriptDispatch->Invoke (dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, wInvokeFlags, 
									&disp_params, NULL, &excepInfo, &nArgErr);

	// release pScriptDispatch when done
	pScriptDispatch->Release ();

	// free dynamically allocated VARIANTARGs
	if (disp_params.rgvarg != NULL) {
		delete [] disp_params.rgvarg;
	}
	
	// Invoke() failed
	if (FAILED(hr)) {
		if (pExcepInfo != NULL && pExcepInfo->pfnDeferredFillIn != NULL) {
			pExcepInfo->pfnDeferredFillIn (pExcepInfo);
		}
		return false;
	}

	return true;
}

void GLScriptHost_Win32::UnloadScript () {
	// release the script source object if required
	if (m_pScriptSource != NULL) {
		m_pScriptSource->Release ();
		m_pScriptSource = NULL;
	}	

	// unload the current script engine
	UnloadScriptEngine ();	

	// unload all extensions
	m_ext_host.UnloadAllExtensions ();

	// remove all host defined objects from our ActiveScript site
	m_site.RemoveAllHostObjects ();	

	// reset the 'gls' engine
	m_engine.Reset ();

	// set host's internal state to READY
	SetState (kScriptHostStateReady);
}

// protected internal functions...

// loads scripting engine associated with the script extension
// must unload the current script engine first
bool GLScriptHost_Win32::LoadScriptEngine () {
	if (m_pScriptEngine != NULL) {
		return false; // script engine is already loaded...
	}	
	
	// get the CLSID of script engine to be loaded
	CLSID clsid;
	if ( !GetScriptEngineCLSID(&clsid) ) {
		RaiseHostError (
		_T("GLScriptHost_Win32: LoadScriptEngine: Failed to get script engine CLSID.")
		);
		// failed to get script engine info
		return false;
	}

	// create the script engine instance
	HRESULT hr;
	hr = ::CoCreateInstance (clsid, NULL, CLSCTX_INPROC, IID_IActiveScript, 
								(LPVOID *)&m_pScriptEngine);
	if (FAILED(hr)) {
		RaiseHostError (
		_T("GLScriptHost_Win32: LoadScriptEngine: CoCreateInstance failed.")
		);
		// failed to load the script engine
		return false;
	}

	// script engine loaded!
	return true;
}

// unlods the current script engiene 
void GLScriptHost_Win32::UnloadScriptEngine () {
	if (m_pScriptEngine != NULL) {

		// call gls_terminate before we close the script
		InvokeScriptMethod ( _tx("gls_terminate"), NULL, 0 );

		// close the script engine
		m_pScriptEngine->Close ();

		// wait for the script engine to be closed really
		SCRIPTSTATE ss;
		do {			
			m_pScriptEngine->GetScriptState(&ss);
		} while (ss != SCRIPTSTATE_CLOSED);

		// release the script engine interface
		m_pScriptEngine->Release ();
		m_pScriptEngine = NULL;
	}
}

// initializes the current script engine for the first time after it is loaded
bool GLScriptHost_Win32::InitScriptEngine () {
	// register all host defined objects with the site
	m_site.AddHostObject (L"gls", &m_engine);
	m_site.AddHostObject (L"gl", &m_glContext);
	m_site.AddHostObject (L"console", &m_console);

	// table of named items to add to the script engine's namespace
	static struct {
		LPCOLESTR name;
		DWORD flags;
	} NAMED_OBJS [] =
	{
		{ L"gls",			SCRIPTITEM_ISVISIBLE },
		{ L"gl",			SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS},
		{ L"console",		SCRIPTITEM_ISVISIBLE }
	};

	// add all named items in the above table to the script engine namesapce
	HRESULT hr;
	for (int i = 0; i < sizeof(NAMED_OBJS) / sizeof(NAMED_OBJS[0]); i++) {
		hr = m_pScriptEngine->AddNamedItem ( NAMED_OBJS[i].name, NAMED_OBJS[i].flags );
		if (FAILED(hr)) {
			return false; // AddNamedItem failed!
		}
	}

	// all named items were successfully registered with the script engine
	return true;
}

void GLScriptHost_Win32::SetState (GLSCRIPT_HOST_STATE state) {
	GLSCRIPT_HOST_STATE from_state = m_state;
	m_state = state;

	// notify the host about the state transition
	if (m_pEventListener != NULL) {
		m_pEventListener->ScriptHost_OnChangeState (this, from_state, m_state);
	}
}

inline void GLScriptHost_Win32::RaiseHostError (LPCTSTR lpszErrorMessage) {
	// notify host about the error
	if (m_pEventListener != NULL) {
		m_pEventListener->ScriptHost_OnError ( this, lpszErrorMessage );
	}
}

BOOL GLScriptHost_Win32::GetScriptEngineCLSID (LPCLSID pclsid) {
	// script engine info status
	BOOL status;

	// get the script source's language set using 'language' directive
	const tstring &script_language = m_pScriptSource->GetLanguage();
	
	// If the language is set, use it to get the script engine's CLSID
	if (script_language.length() > 0) {
		// try to get the script engine's CLSID using language name as engine's PROGID		
		status = GetScriptEngineCLSIDFromProgID (script_language.c_str(), pclsid);

		if (!status) {
			// assume language name to be a file extension and get the script engine CLSID 
			// from registry
			tstring script_file_extension = _T(".");
			script_file_extension.append (script_language);

			// get the script engine CLSID from registry manually
			status = GetScriptEngineCLSIDFromFileExtension (script_file_extension.c_str(),
															pclsid);
		}
	} else {
		// language is not set so use script's file name extension to get the script engine's
		// CLSID
		tstring script_file_extension = _T(".");
		script_file_extension.append (m_pScriptSource->GetFileExtensionName ());

		// get the script engine CLSID from registry manually
		status = GetScriptEngineCLSIDFromFileExtension (script_file_extension.c_str(), pclsid);
	}

	return status;
}

// Returns script engine's CLSID from language name e.g. vbscript or javascript
BOOL GLScriptHost_Win32::GetScriptEngineCLSIDFromProgID (LPCTSTR lpszExtension, LPCLSID clsid) {
	HRESULT hr;

	// get the CLSID using extension name as PROGID
	#ifdef UNICODE
		hr = ::CLSIDFromProgID (lpszExtension, clsid);
	#else
		OLECHAR olesz_buff[255];
		::mbstowcs (olesz_buff, lpszExtension, lstrlen(lpszExtension);
		hr = ::CLSIDFromProgID (olesz_buff, clsid);
	#endif
	
	return SUCCEEDED(hr);
}

// Returns script engine's CLSID from file extension name like .js, .vbs
BOOL GLScriptHost_Win32::GetScriptEngineCLSIDFromFileExtension (LPCTSTR lpszExtension, LPCLSID clsid) {
	// local vars
	HKEY key;
	TCHAR data[255];
	#if !defined(_UNICODE) && !defined(UNICODE)
	WCHAR wcsdata[255];
	#endif
	DWORD data_len;
	DWORD data_type;
	tstring language_name;
	wstring clsid_name;

	// get language_name for .extension
	if (RegOpenKeyEx (HKEY_CLASSES_ROOT, lpszExtension, 0, KEY_READ, &key) == ERROR_SUCCESS) {
		data_len = sizeof(data);
		if (RegQueryValueEx (key, NULL, NULL, &data_type, (LPBYTE)&data[0], &data_len) == ERROR_SUCCESS) {
			language_name = data;
		}
		RegCloseKey (key);
	}
	if (language_name.empty()) {
		// language name not found in the registry
		return FALSE;
	}

	// get CLSID of script engine from the language_name
	// Note that the language_name we got in above step may not be the real language name
	// of the script, so we loop inorder get the CLSID from the real language name
	do {
		// try to get the CLSID for the current language name from the registry key
		// HKEY_CLASSES_ROOT\\$language_name\\CLSID
		tstring str_sub_key = language_name;
		str_sub_key.append (_T("\\CLSID"));

		if (RegOpenKeyEx (HKEY_CLASSES_ROOT, str_sub_key.c_str(), 0, KEY_READ, &key) == ERROR_SUCCESS) {
			data_len = sizeof(data);
			if (RegQueryValueEx (key, NULL, NULL, &data_type, (LPBYTE)&data[0], &data_len) == ERROR_SUCCESS) {
			#ifdef _UNICODE
				clsid_name = data;
			#else
				::mbstowcs (wcsdata, data, sizeof(wcsdata));
				clsid_name = wcsdata;
			#endif
			}
			RegCloseKey (key);
		}

		if (clsid_name.empty()) {
			// CLSID could not be read so try the real langugage name from 
			// HKEY_CLASSES_ROOT\\$language_name\\ScriptEngine key
			tstring str_sub_key = language_name;
			str_sub_key.append (_T("\\ScriptEngine"));
			language_name.clear ();

			if (RegOpenKeyEx (HKEY_CLASSES_ROOT, str_sub_key.c_str(), 0, KEY_READ, &key) == ERROR_SUCCESS) {
				data_len = sizeof(data);
				if (RegQueryValueEx (key, NULL, NULL, &data_type, (LPBYTE)&data[0], &data_len) == ERROR_SUCCESS) {
					language_name = data;
				}
				RegCloseKey (key);
			}
		} else {
			// break out of loop
			language_name.clear ();
		}
	} while (!language_name.empty());

	// CLSID name empty?
	if (clsid_name.empty()) {
		return FALSE;
	}

	// get CLSID from string
	HRESULT hr = CLSIDFromString ((OLECHAR *)clsid_name.c_str(), clsid);
	return (SUCCEEDED(hr));
}

#endif // WIN32

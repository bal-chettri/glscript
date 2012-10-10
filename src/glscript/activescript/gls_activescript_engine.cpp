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
#include <glscript/gls_macros.h>
#include <glscript/activescript/gls_activescript_host.h>
#include <glscript/activescript/gls_activescript_marshal.h>
#include <math.h>

using namespace gls;

// externs...
extern HINSTANCE _hAppInstance;

// constatns...
#define ANIMATION_TIMER_ID				0x0001
#define FPS_TIMER_ID					0x0002
#define GLS_DEF_WINDOW_WIDTH			480
#define GLS_DEF_WINDOW_HEIGHT			320
#define GLS_DEF_ORTHO					FALSE
#define GLS_DEF_ANIMATION				FALSE
#define GLS_DEF_FRAME_RATE				12

// define externs...
const IID *GLScript_Engine_IIDs[] = {
	&IID_IUnknown,
	&IID_IDispatch,
	&IID__GLScript_Engine,
	NULL
};

// GLScript_Engine class definition...

GLScript_Engine::GLScript_Engine (IUnknown *pParent) : AutomationContainedComObject (pParent) 
{
	// init with defaults...
	m_title = NULL;
	m_shader = NULL;
	m_flagAnimating = FALSE;

	// Register a window class for animation timer window. Animation timer window serves as 
	// a context in the timer callback procedure.
	WNDCLASS wcex, dummyClassInfo;
	memset (&wcex, 0, sizeof(wcex));
	wcex.lpszClassName = _T("_gls_timer_window");
	wcex.lpfnWndProc = _AnimationWindowProc;
	wcex.hInstance = _hAppInstance;	

	// register only if rquired
	if (!::GetClassInfo (_hAppInstance, wcex.lpszClassName, &dummyClassInfo)) {
		RegisterClass (&wcex);
	}

	// create the animation timer window
	m_hWndAnimationTimer = ::CreateWindow (wcex.lpszClassName, _T(""), WS_POPUP, 
											0, 0, 1, 1, NULL, NULL, _hAppInstance, 
											NULL);
	if (m_hWndAnimationTimer != NULL) {
		// map the timer window handle to this object
		::SetWindowLongPtr (m_hWndAnimationTimer, GWLP_USERDATA, (__int3264)(LONG_PTR)this);
	}

	// reset the engine to default state
	Reset ();
}

GLScript_Engine::~GLScript_Engine () {
	// resetting the engine also stops the animation timer
	Reset ();

	// destroy the animation timer window
	DestroyWindow (m_hWndAnimationTimer);
}

/* GLScript_Engine implementation */

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_version (short *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	*pValue = GLS_VERSION;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_native (VARIANT_BOOL *pValue) {
	*pValue = m_native ? VARIANT_TRUE : VARIANT_FALSE;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_native (VARIANT_BOOL value) {
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_gles (VARIANT_BOOL *pValue) {
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_gles (VARIANT_BOOL value) {
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_glver (VARIANT_BOOL *pValue) {
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_shader (BSTR *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	if (m_shader) {
		*pValue = ::SysAllocString (m_shader);
	} else {
		*pValue = ::SysAllocString (L"");
	}

	if (*pValue == NULL) {
		return E_OUTOFMEMORY;
	}

	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_shader (BSTR value) {
	if (value == NULL) {
		return E_INVALIDARG;
	}

	if (m_shader) {
		::SysFreeString (m_shader);
	}

	m_shader = ::SysAllocString (value);
	if (m_shader == NULL) {
		return E_OUTOFMEMORY;
	}

	return NOERROR;
}
	
HRESULT STDMETHODCALLTYPE GLScript_Engine::get_windowTitle (BSTR *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	if (m_title) {
		*pValue = ::SysAllocString (m_title);
	} else {
		*pValue = ::SysAllocString (L"");
	}

	if (*pValue == NULL) {
		return E_OUTOFMEMORY;
	}

	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_windowTitle (BSTR value) {
	if (value == NULL) {
		return E_INVALIDARG;
	}

	UINT length = ::SysStringLen (value);
	if (length > GLSCRIPT_WINDOW_TITLE_MAX_LEN) {
		return E_INVALIDARG;
	}

	if (m_title) {
		::SysFreeString (m_title);
	}

	m_title = ::SysAllocString (value);
	if (m_title == NULL) {
		return E_OUTOFMEMORY;
	}

	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_windowWidth (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}

	*pValue = m_windowWidth;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_windowWidth (int value) {
	m_windowWidth = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_windowHeight (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}

	*pValue = m_windowHeight;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_windowHeight (int value) {
	m_windowHeight = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_viewPortLeft (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_viewPortLeft;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_viewPortLeft (int value) {
	m_viewPortLeft = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_viewPortTop (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_viewPortTop;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_viewPortTop (int value) {
	m_viewPortTop = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_viewPortWidth (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_viewPortWidth;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_viewPortWidth (int value) {
	m_viewPortWidth = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_viewPortHeight (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_viewPortHeight;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_viewPortHeight (int value) {
	m_viewPortHeight = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_ortho (VARIANT_BOOL *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_ortho ? VARIANT_TRUE : VARIANT_FALSE;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_ortho (VARIANT_BOOL value) {
	m_ortho = value == VARIANT_TRUE ? TRUE : FALSE;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_animation (VARIANT_BOOL *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_animation;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_animation (VARIANT_BOOL value) {
	m_animation = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_frameRate (short *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_frameRate;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::put_frameRate (short value) {
	m_frameRate = value;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::get_fps (short *pValue) {
	if (!pValue) {
		return E_POINTER;
	}
	
	*pValue = m_fps;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::require (BSTR bstr_path, VARIANT var_options, 
													IDispatch **ppDispatchExtLib) 
{
	// default loading options to use for the 'require' call for loading extensions
	const long DEF_LOAD_OPTIONS = GLS_EXTENSION_LIBRARY;

	// supported loading options
	const long SUPPORTED_LOAD_OPTIONS = (GLS_EXTENSION_RENDERER | 
										GLS_EXTENSION_LIBRARY);

	// check for invalud arguments
	if (bstr_path == NULL || ppDispatchExtLib == NULL) {
		return E_POINTER;
	}
	*ppDispatchExtLib = NULL;

	// parse the variant options argument for the loading options. The loading options
	// can be specified as a string encoded options or as a long interger bitmask. the
	// loading options is optional, in which case default loading options is used.
	long load_options;	
	
	if (var_options.vt == VT_ERROR) {
		// use default loading options variant's internal type is VT_ERROR, which means
		// no value was supplied for this parameter.
		load_options = DEF_LOAD_OPTIONS;
	} else if (var_options.vt == VT_BSTR) {
		// parse load options from string encoded options
		if (!ParseExtensionLoadOptions (var_options.bstrVal, load_options)) {
			return E_INVALIDARG;
		}
	} else {
		// assume load options as a long type and fetch the value from the variant
		if (!gls_comvariant_get_long_value (&var_options, &load_options)) {
			return E_INVALIDARG;
		}
	}

	// check for any option that is not supported in the current environment
	if ( (load_options & SUPPORTED_LOAD_OPTIONS) != load_options ) {
		return E_INVALIDARG;
	}
	
	GLScriptHost_Win32 *pHost = reinterpret_cast<GLScriptHost_Win32 *>(GetParent());
	
	// extension load options has been successfully parsed so next task is to build the 
	// extension path to load it
	UINT path_length = ::SysStringLen(bstr_path);
	char *ascii_path_buff = new char [path_length + 1];
	::wcstombs (ascii_path_buff, bstr_path, path_length);
	ascii_path_buff [path_length] = '\0';

	// load the extension using the extension host object
	Extension *pExtension = pHost->m_ext_host.LoadExtension (ascii_path_buff, load_options);

	delete ascii_path_buff;

	// check if extension failed to load
	if (pExtension == NULL) {
		// failed to load the extension. notify the host about the error.
		if (pHost->m_pEventListener != NULL) {
			tstring str_error (_T("Failed to load the extension '"));
			str_error+= bstr_path;
			str_error+= _T("'.");

			pHost->RaiseHostError (str_error.c_str());
		}
		// #TODO: return error only if strict mode is set
		return E_FAIL;
	}

	// hook render proc if "renderer" option is specified
	if (load_options & GLS_EXTENSION_RENDERER) {
		pHost->m_ext_host.HookRenderProc (pExtension->GetRenderProc(), pExtension);
	}
	
	// Return the lib interface if required
	if (load_options & GLS_EXTENSION_LIBRARY) {
		// return the IDispatch interface
		*ppDispatchExtLib = reinterpret_cast<IDispatch *>(pExtension->GetLibInterface());
		(*ppDispatchExtLib)->AddRef ();
	}

	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::byteArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_BYTE);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::ubyteArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_UNSIGNED_BYTE);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::shortArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_SHORT);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::ushortArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_UNSIGNED_SHORT);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::intArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_INT);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::uintArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_UNSIGNED_INT);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::floatArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_FLOAT);
}

HRESULT STDMETHODCALLTYPE GLScript_Engine::doubleArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray) {
	return CreateArrayInternal (varArrayConfig, pOutArray, GL_DOUBLE);
}

void GLScript_Engine::Reset () {
	// stop animation
	StopAnimation ();

	// cleanup BSTR strings and reset to defaults
	if (m_title) {
		::SysFreeString (m_title);
		m_title = NULL;
	}
	if (m_shader) {
		::SysFreeString (m_shader);
		m_shader = NULL;
	}

	// reset vars
	m_windowWidth = GLS_DEF_WINDOW_WIDTH;
	m_windowHeight = GLS_DEF_WINDOW_HEIGHT;
	m_viewPortLeft = 0;
	m_viewPortTop = 0;
	m_viewPortWidth = m_windowWidth;
	m_viewPortHeight = m_windowHeight;
	m_ortho = GLS_DEF_ORTHO;
	m_animation = GLS_DEF_ANIMATION;
	m_frameRate = GLS_DEF_FRAME_RATE;
	m_fps = 0;
	m_native = FALSE;
	m_framesCounter = 0;
}

void GLScript_Engine::StartAnimation () {
	float delay = 1000.0f / (float)m_frameRate;
	int delayms = (int)floor(delay);

	// start the animation timer
	UINT_PTR status = ::SetTimer (m_hWndAnimationTimer, ANIMATION_TIMER_ID, (UINT)delayms, 
									_AnimationTimerProc);
	if (status != 0) {
		m_flagAnimating = TRUE;

		// start the fps timer
		m_framesCounter = 0;
		::SetTimer (m_hWndAnimationTimer, FPS_TIMER_ID, 1000, _FPSTimerProc);

		// first crack
		GLScriptHost_Win32 *pHost = reinterpret_cast<GLScriptHost_Win32 *>(GetParent());
		bool ret = pHost->InvokeScriptMethod (_tx("gls_renderScene"), NULL, 0);
	}
}

void GLScript_Engine::StopAnimation () {
	if (m_flagAnimating) {
		KillTimer (m_hWndAnimationTimer, FPS_TIMER_ID);
		KillTimer (m_hWndAnimationTimer, ANIMATION_TIMER_ID);
		m_flagAnimating = FALSE;
	}
}

// internal private member function...

bool GLScript_Engine::ParseExtensionLoadOptions (BSTR bstrOptions, long &options) {
	// format: lib,renderer
	const wchar_t *DELIMETER = L",";

	wchar_t *token = wcstok (bstrOptions, DELIMETER);
	options = 0;

	while (token != NULL) {
		// process token to build options
		if ( ::wcscmp (token, L"renderer") == 0 ) {
			options|= GLS_EXTENSION_RENDERER;
		} 
		else if ( ::wcscmp (token, L"lib") == 0 ) {
			options|= GLS_EXTENSION_LIBRARY;
		} 
		else if ( ::wcscmp (token, L"guiplugin") == 0 ) {
			options|= GLS_EXTENSION_GUIPLUGIN;
		} else {
			return false;
		}

		// get next token
		token = wcstok (NULL, DELIMETER);
	}

	return true;
}

HRESULT GLScript_Engine::CreateArrayInternal (VARIANT varArrayConfig, _GLScript_Array **pOutArray, int type) {
	HRESULT hr;

	hr = GLScriptArray_Factory.CreateInstance (NULL, IID__GLScript_Array, (LPVOID *)pOutArray);
	if (FAILED(hr)) {
		return hr;
	}

	GLScript_Array *pInternalArray = reinterpret_cast<GLScript_Array *> (*pOutArray);
	
	if (varArrayConfig.vt == VT_BSTR) {
		BSTR pArrayConfig = varArrayConfig.bstrVal;
		hr = pInternalArray->CreateWithTypeAndElements (type, pArrayConfig);
	} else {
		int length;
		if (!gls_comvariant_get_int_value (&varArrayConfig, &length)) {
			return E_INVALIDARG;
		}
		hr = pInternalArray->CreateWithTypeAndLength (type, length);
	}

	if (FAILED(hr)) {
		// release array if initialization failed
		(*pOutArray)->Release ();
		(*pOutArray) = NULL;

		return hr;
	}

	return NOERROR;
}

// callbacks
LRESULT CALLBACK GLScript_Engine::_AnimationWindowProc (HWND hwnd, UINT uMsg, WPARAM wp, LPARAM lp) {
	return ::DefWindowProc (hwnd, uMsg, wp, lp);
}

void CALLBACK GLScript_Engine::_AnimationTimerProc (HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	// get engine object from window handle
	GLScript_Engine *pEngine = (GLScript_Engine *)::GetWindowLongPtr(hWnd, GWLP_USERDATA);

	// get the parent script host object
	GLScriptHost_Win32 *pScriptHost = (GLScriptHost_Win32 *)pEngine->GetParent();

	// animation timer event; increment frame counter
	++pEngine->m_framesCounter;

	// call the render proc if it is setup to draw the scene
	void *render_proc_context;
	GLS_RENDER_PROC render_proc;
	render_proc = pScriptHost->m_ext_host.GetHookedRenderProc (&render_proc_context);

	if (render_proc != NULL) {
		render_proc (render_proc_context);
	} else {
		// call the renderScene event on script to draw the scene
		pScriptHost->InvokeScriptMethod (_tx("gls_renderScene"), NULL, 0);
	}
}

void CALLBACK GLScript_Engine::_FPSTimerProc (HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	GLScript_Engine *pEngine = (GLScript_Engine *)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
	
	// FPS timer event; compute actual FPS
	pEngine->m_fps = (pEngine->m_framesCounter + pEngine->m_fps) / 2;
	pEngine->m_framesCounter = 0;
}

#endif // WIN32

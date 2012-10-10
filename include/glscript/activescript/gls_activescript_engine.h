//
// gls_activescript_engine.h  glscript Engine class.
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
#ifndef __GLSCRIPT_ACTIVESCRIPT_ENGINE_H__
 #define __GLSCRIPT_ACTIVESCRIPT_ENGINE_H__

// prevent direct inclusion of this header file.
#ifndef __GLSCRIPT_ACTIVESCRIPT_HOST_H__
#error "Do not include this header directly. Include gls_activescript_host.h instead."
#endif

// externs...
extern const IID *GLScript_Engine_IIDs[];

// GLScript_Engine class...
class GLScript_Engine : 
	public AutomationContainedComObject<_GLScript_Engine, GLScript_Engine_IIDs, &IID__GLScript_Engine>
{
public:
	/* _GLScript_Engine functions */

	/* properties */
	HRESULT STDMETHODCALLTYPE get_version (short *pValue);
	HRESULT STDMETHODCALLTYPE get_native (VARIANT_BOOL *pValue);
	HRESULT STDMETHODCALLTYPE put_native (VARIANT_BOOL value);
	HRESULT STDMETHODCALLTYPE get_gles (VARIANT_BOOL *pValue);
	HRESULT STDMETHODCALLTYPE put_gles (VARIANT_BOOL value);
	HRESULT STDMETHODCALLTYPE get_glver (VARIANT_BOOL *pValue);
	HRESULT STDMETHODCALLTYPE get_shader (BSTR *pValue);
	HRESULT STDMETHODCALLTYPE put_shader (BSTR value);
	HRESULT STDMETHODCALLTYPE get_windowTitle (BSTR *pValue);
	HRESULT STDMETHODCALLTYPE put_windowTitle (BSTR value);
	HRESULT STDMETHODCALLTYPE get_windowWidth (int *pValue);
	HRESULT STDMETHODCALLTYPE put_windowWidth (int value);
	HRESULT STDMETHODCALLTYPE get_windowHeight (int *pValue);
	HRESULT STDMETHODCALLTYPE put_windowHeight (int value);
	HRESULT STDMETHODCALLTYPE get_viewPortLeft (int *pValue);
	HRESULT STDMETHODCALLTYPE put_viewPortLeft (int value);
	HRESULT STDMETHODCALLTYPE get_viewPortTop (int *pValue);
	HRESULT STDMETHODCALLTYPE put_viewPortTop (int value);
	HRESULT STDMETHODCALLTYPE get_viewPortWidth (int *pValue);
	HRESULT STDMETHODCALLTYPE put_viewPortWidth (int value);
	HRESULT STDMETHODCALLTYPE get_viewPortHeight (int *pValue);
	HRESULT STDMETHODCALLTYPE put_viewPortHeight (int value);
	HRESULT STDMETHODCALLTYPE get_ortho (VARIANT_BOOL *pValue);
	HRESULT STDMETHODCALLTYPE put_ortho (VARIANT_BOOL value);
	HRESULT STDMETHODCALLTYPE get_animation (VARIANT_BOOL *pValue);
	HRESULT STDMETHODCALLTYPE put_animation (VARIANT_BOOL value);
	HRESULT STDMETHODCALLTYPE get_frameRate (short *pValue);
	HRESULT STDMETHODCALLTYPE put_frameRate (short value);
	HRESULT STDMETHODCALLTYPE get_fps (short *pValue);	

	/* methods */
	HRESULT STDMETHODCALLTYPE require (BSTR path, VARIANT options, IDispatch **ppDispatch);

	HRESULT STDMETHODCALLTYPE byteArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE ubyteArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE shortArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE ushortArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE intArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE uintArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE floatArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);
	HRESULT STDMETHODCALLTYPE doubleArray (VARIANT varArrayConfig, _GLScript_Array **pOutArray);

public:
	void Reset ();
	void StartAnimation ();
	void StopAnimation ();

private:
	bool ParseExtensionLoadOptions (BSTR bstrOptions, long &options);
	HRESULT CreateArrayInternal (VARIANT varArrayConfig, _GLScript_Array **pOutArray, int type);

	static LRESULT CALLBACK _AnimationWindowProc (HWND hwnd, UINT uMsg, WPARAM, LPARAM);
	static void CALLBACK _AnimationTimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	static void CALLBACK _FPSTimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

public:
	/* ctor */
	GLScript_Engine (IUnknown *pParent);

	/* dtor */
	virtual ~GLScript_Engine ();

private:
	BSTR	m_shader;
	BSTR	m_title;
	int		m_windowWidth;
	int		m_windowHeight;
	int		m_viewPortLeft;
	int		m_viewPortTop;
	int		m_viewPortWidth;
	int		m_viewPortHeight;
	BOOL	m_ortho;
	BOOL	m_animation;
	BOOL	m_native;
	short	m_frameRate;
	short	m_fps;
	short	m_framesCounter;
	BOOL	m_flagAnimating;
	HWND	m_hWndAnimationTimer;
};

#endif /* __GLSCRIPT_ACTIVESCRIPT_ENGINE_H__ */

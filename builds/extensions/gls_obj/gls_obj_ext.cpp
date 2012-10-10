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
#include "gls_obj_ext.h"
#include "gls_obj_lib.h"
#include <gls_sdk/glscript/gls_macros.h>

//
// class GLSExtensionImp definition
//

/* get version number of the interface */
unsigned short GLSExtensionImp::GetInterfaceVersion () {
	return GLS_VERSION_MAKE_SHORT(0,1);
}

/* get full version number of the extension */
unsigned long GLSExtensionImp::GetExtensionVersion () {
	return GLS_VERSION_MAKE_LONG(0,0,0,1);
}

/* get capabilities of the extension */
unsigned long GLSExtensionImp::GetCapabilities (void) {	
	return GLS_EXTENSION_LIBRARY;
}

/* get the author's name */
const wchar_t *GLSExtensionImp::GetAuthorName (void) {
	return L"Bal Bahadur Chettri";
}

/* get vendor's name */
const wchar_t *GLSExtensionImp::GetVendorName (void) {
	return L"Bal Bahadur Chettri";
}

/* create the plugin window */
void *GLSExtensionImp::CreatePluginWindow (void) {
	return NULL;
}

/* handle the glScript event */
long GLSExtensionImp::HandleEvent (gls::GLS_EVENT *p_event) {
	return 0;
}

/* get extension library info */
void GLSExtensionImp::GetLibInfo (gls::GLS_EXTENSION_LIB_INFO *p_lib_info) {
	strcpy (p_lib_info->name, "obj");
	p_lib_info->version = GLS_VERSION_MAKE_SHORT(0,1);
}

/* get interface to the extension library. In Win platforms this should return 
_GLScriptExtLib interface for the library. */
void *GLSExtensionImp::GetLibInterface () {
	GLSExtensionLib *libInt = NULL;
	_GLScriptExtLib *pScriptLib = NULL;
	HRESULT hr;

	hr = GLS_OBJ_Lib_Factory.CreateInstance (NULL, IID__GLScriptExtLib, (LPVOID *)&libInt);

	if (FAILED(hr)) {
		return NULL;
	}

	pScriptLib = libInt;

	return pScriptLib;
}

/** Return the timer callback procedure. @see GetRenderProc */
gls::GLS_TIMER_PROC GLSExtensionImp::GetTimerProc () {
	return NULL;
}

/** Returns the render callback procedure. @see GetTimerProc */
gls::GLS_RENDER_PROC GLSExtensionImp::GetRenderProc () {
	return NULL;
}

/* } GLS_EXTENSION_INTERFACE ver 1 */

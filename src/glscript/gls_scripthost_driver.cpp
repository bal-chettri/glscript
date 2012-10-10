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
#include <glscript/gls_scripthost_driver.h>

#include <glscript/activescript/gls_activescript_host.h>

using namespace gls;

// ScriptHostDriver class definition...

///////////////////////////////////////////////////////////////////////////////
//
ScriptHostDriver::ScriptHostDriver () {
	m_pGLScriptHost = NULL;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptHostDriver::~ScriptHostDriver () {
#if defined(WIN32)
	if (m_pGLScriptHost) {
		
		// #NOTE: reinterpret_cast to GLScriptHost_Win32 does not map to correct vtable,
		// but C cast do
		// GLScriptHost_Win32 *pScriptHostWin32 = reinterpret_cast<GLScriptHost_Win32 *>(m_pGLScriptHost);

		GLScriptHost_Win32 *pScriptHostWin32 = (GLScriptHost_Win32 *)m_pGLScriptHost;
		pScriptHostWin32->Release ();
	}
#else
	// #TODO: cleanup script host on other platforms
#endif
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptHost *ScriptHostDriver::GetScriptHost () {
	if (!m_pGLScriptHost) {
		LoadScriptHost ();
	}

	return m_pGLScriptHost;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
bool ScriptHostDriver::LoadScriptHost () {
#if defined(WIN32)
	HRESULT hr;
	GLScriptHost_Win32 *pScriptHostWin32;
	hr = GLScriptHost_Win32_Factory.CreateInstance (
			NULL, 
			IID_IUnknown, 
			(LPVOID *)&pScriptHostWin32
			);
	if (SUCCEEDED(hr)) {
		m_pGLScriptHost = pScriptHostWin32;
	}
#else
	m_pGLScriptHost = NULL; // #TODO: load and init internal script host
#endif

	return (m_pGLScriptHost != NULL);
}
///////////////////////////////////////////////////////////////////////////////

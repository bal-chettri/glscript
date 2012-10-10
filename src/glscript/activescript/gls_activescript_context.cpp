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

// define externs...
const IID *GLScript_Context_IIDs[] = {
	&IID_IUnknown,
	&IID_IDispatch,
	&IID__GLScript_Context,
	NULL
};

// GLScript_GlContext implementation...

HRESULT STDMETHODCALLTYPE GLScript_Context::flush () {
	GLScriptHost_Win32 *pHost = reinterpret_cast<GLScriptHost_Win32 *>(GetParent());
	::SwapBuffers (pHost->m_windowContext.hdc);
	return NOERROR;
}

#endif // WIN32

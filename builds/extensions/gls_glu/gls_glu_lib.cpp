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
#include <tchar.h>
#include <assert.h>
#include "gls_glu_lib.h"

// GLSExtensionLib constructor.
GLSExtensionLib::GLSExtensionLib () {
}

// GLSExtensionLib destructor.
GLSExtensionLib::~GLSExtensionLib () {
}

/* _GLScript_ExtLib implementation */

HRESULT STDMETHODCALLTYPE GLSExtensionLib::get_name (BSTR *pValue) {
    *pValue = ::SysAllocString (L"glu");
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLSExtensionLib::get_version (short *pValue) {
    *pValue = GLS_VERSION_MAKE_SHORT(GLS_GLU_LIB_VER_MAJ,GLS_GLU_LIB_VER_MIN);
    return NOERROR;
}

/* _GLS_GLU_Lib implementation */

/* externs */
const IID *_GLSExtensionLib_IIDs[] = 
{
    &IID_IUnknown,
    &IID_IDispatch,
    &IID__GLScriptExtLib,
    &IID__GLS_GLU_Lib,
    NULL
};

ClassFactory<GLSExtensionLib> GLSExtensionLib_Factory;

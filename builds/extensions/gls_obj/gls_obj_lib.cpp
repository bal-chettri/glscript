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
#include "gls_obj_lib.h"
#include "gls_obj_model.h"
#include <gls_sdk/glscript/gls_macros.h>

// GLSExtensionLib constructor.
GLSExtensionLib::GLSExtensionLib () {
}

// GLS_OBJ_Lib destructor.
GLSExtensionLib::~GLSExtensionLib () {
}

/* _GLScript_ExtLib implementation */

HRESULT STDMETHODCALLTYPE GLSExtensionLib::get_name (BSTR *pValue) {
    *pValue = ::SysAllocString (L"obj");
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLSExtensionLib::get_version (short *pValue) {
    *pValue = GLS_VERSION_MAKE_SHORT(0,1);
    return NOERROR;
}

/* _GLS_OBJ_Lib implementation */

HRESULT STDMETHODCALLTYPE GLSExtensionLib::load (BSTR path, _ObjModel **model) {
    HRESULT hr;
    
    hr = GLS_OBJ_Model_Factory.CreateInstance (NULL, IID__ObjModel, (LPVOID *)model);

    if (SUCCEEDED(hr)) {
        GLS_OBJ_Model *model_obj = reinterpret_cast<GLS_OBJ_Model *>(*model);

        UINT length = ::SysStringLen(path);
        char *szmbs_path = new char [ length + 1];
        ::wcstombs (szmbs_path, path, length);
        szmbs_path [length] = '\0';

        // initialize the model from the model file. On failure, free the object.
        if (!model_obj->_InitModel (szmbs_path)) {
            (*model)->Release ();
            *model = NULL;
            hr = E_FAIL;
        }

        delete szmbs_path;
    }

    return hr;
}

/* externs */
const IID *_GLSExtensionLib_IIDs[] = 
{
    &IID_IUnknown,
    &IID_IDispatch,
    &IID__GLScriptExtLib,
    &IID__GLS_OBJ_Lib,
    NULL
};

ClassFactory<GLSExtensionLib> GLS_OBJ_Lib_Factory;

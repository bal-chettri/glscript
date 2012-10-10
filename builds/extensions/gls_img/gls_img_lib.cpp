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
#include "gls_img_lib.h"
#include "gls_img_image.h"
#include "SOIL/soil.h"
#include <gls_sdk/glscript/gls_macros.h>

// GLSExtensionLib constructor.
GLSExtensionLib::GLSExtensionLib () {
}

// GLSExtensionLib destructor.
GLSExtensionLib::~GLSExtensionLib () {
}

/* _GLScript_ExtLib implementation */

HRESULT STDMETHODCALLTYPE GLSExtensionLib::get_name (BSTR *pValue) {
	*pValue = ::SysAllocString (L"img");
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLSExtensionLib::get_version (short *pValue) {
	*pValue = GLS_VERSION_MAKE_SHORT(GLS_IMG_LIB_VER_MAJ,GLS_IMG_LIB_VER_MIN);
	return NOERROR;
}

/* _GLSExtensionLib implementation */

HRESULT STDMETHODCALLTYPE GLSExtensionLib::load (BSTR path, _Image **image) {
	HRESULT hr;
	
	hr = GLS_IMG_Image_Factory.CreateInstance (NULL, IID__Image, (LPVOID *)image);

	if (SUCCEEDED(hr)) {
		GLS_IMG_Image *image_obj = reinterpret_cast<GLS_IMG_Image *>(*image);

		UINT length = ::SysStringLen(path);
		char *szmbs_path = new char [ length + 1];
		::wcstombs (szmbs_path, path, length);
		szmbs_path [length] = '\0';

		// initialize the model from the model file. On failure, free the object.
		if (!image_obj->_Init (szmbs_path)) {
			(*image)->Release ();
			*image = NULL;
			hr = E_FAIL;
		}

		delete szmbs_path;
	}

	return hr;
}

HRESULT STDMETHODCALLTYPE GLSExtensionLib::loadTexture (BSTR path, long *texid) {
	UINT length = ::SysStringLen(path);
	char *szmbs_path = new char [length + 1];
	::wcstombs (szmbs_path, path, length);
	szmbs_path [length] = '\0';

	GLuint textid = SOIL_load_OGL_texture (
		szmbs_path,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	delete szmbs_path;

	/* check for an error during the load process */
	if( 0 == textid ) {
		printf ( "SOIL loading error: '%s'\n", SOIL_last_result() );
		return E_FAIL;
	}

	*texid = (long)texid;

	return NOERROR;	
}

HRESULT STDMETHODCALLTYPE GLSExtensionLib::freeTexture (long texid) {
	GLuint textid = (GLuint)texid;

	::glDeleteTextures (1, &textid);

	return NOERROR;
}

/* externs */
const IID *_GLSExtensionLib_IIDs[] = 
{
	&IID_IUnknown,
	&IID_IDispatch,
	&IID__GLScriptExtLib,
	&IID__GLS_IMG_Lib,
	NULL
};

ClassFactory<GLSExtensionLib> GLSExtensionLib_Factory;

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
/** gls_img_lib.h */
#ifndef __GLS_IMG_LIB_H
 #define __GLS_IMG_LIB_H

/* includes */
#include <gls_sdk/glscript/gls_types.h>
#include <gls_sdk/com/dispatch.h>
#include <gls_sdk/com/class_factory.h>
#include "gls_img_lib_interfaces.h"

/** forward declarations */
class GLSExtensionLib;

/** externs */
extern const IID *_GLSExtensionLib_IIDs[];
extern ClassFactory<GLSExtensionLib> GLSExtensionLib_Factory;
 
/** GLSExtensionLib class. */
class GLSExtensionLib : 
	public AutomationComObject<_GLS_IMG_Lib, _GLSExtensionLib_IIDs, &IID__GLS_IMG_Lib>
{
public:
	GLSExtensionLib ();
	virtual ~GLSExtensionLib ();

	/* _GLScriptExtLib methods */
	HRESULT STDMETHODCALLTYPE get_name (BSTR *pValue);
	HRESULT STDMETHODCALLTYPE get_version (short *pValue);

	/* _GLS_OBJ_Lib methods */
	// 0.1
	HRESULT STDMETHODCALLTYPE load (BSTR path, _Image **image);
	// 0.3
	HRESULT STDMETHODCALLTYPE loadTexture (BSTR path, long *texid);
	HRESULT STDMETHODCALLTYPE freeTexture (long texid);

	// private data members...
private:
};

#endif /* __GLS_IMG_LIB_H */

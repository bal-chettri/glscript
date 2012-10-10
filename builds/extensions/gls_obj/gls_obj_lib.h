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
/** gls_obj_lib.h */
#ifndef __GLS_OBJ_LIB_H
 #define __GLS_OBJ_LIB_H

/* includes */
#include <gls_sdk/glscript/gls_types.h>
#include <gls_sdk/com/dispatch.h>
#include <gls_sdk/com/class_factory.h>
#include "gls_obj_lib_interfaces.h"

/** forward declarations */
class GLSExtensionLib;

/** externs */
extern const IID *_GLSExtensionLib_IIDs[];
extern ClassFactory<GLSExtensionLib> GLS_OBJ_Lib_Factory;

/** GLS_OBJ_Lib class. */
class GLSExtensionLib : 
	public AutomationComObject<_GLS_OBJ_Lib, _GLSExtensionLib_IIDs, &IID__GLS_OBJ_Lib>
{
public:
	GLSExtensionLib ();
	virtual ~GLSExtensionLib ();

	/* _GLScriptExtLib methods */
	HRESULT STDMETHODCALLTYPE get_name (BSTR *pValue);
	HRESULT STDMETHODCALLTYPE get_version (short *pValue);

	/* _GLS_OBJ_Lib methods */
	HRESULT STDMETHODCALLTYPE load (BSTR path, _ObjModel **model);

	// private data members...
private:
};

#endif /* __GLS_OBJ_LIB_H */

//
// gls_activescript_array.h    glscript Array class.
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
#ifndef __GLSCRIPT_SCRIPTING_ARRAY_H
#define __GLSCRIPT_SCRIPTING_ARRAY_H

#ifndef WIN32
#error This header requires WIN32 platform.
#endif

// include required headers... 
#include <com/dispatch.h>
#include <com/class_factory.h>
#include "gls_core.h"

// forward declarations...
class GLScript_Array;

// externs...
extern const IID *GLScript_Array_IIDs[];
extern ClassFactory<GLScript_Array> GLScriptArray_Factory;
 
// GLScript_Array class...
class GLScript_Array : public AutomationComObject<
								_GLScript_Array, 
								GLScript_Array_IIDs, 
								&IID__GLScript_Array> 
{
public:
	/* _GLScript_Array methods */
	HRESULT STDMETHODCALLTYPE get_type (int *pValue);
	HRESULT STDMETHODCALLTYPE get_length (int *pValue);

	HRESULT STDMETHODCALLTYPE get (int index, VARIANT *pValue);
	HRESULT STDMETHODCALLTYPE put (int index, VARIANT value);

public:
	/* ctor */
	GLScript_Array ();

	/* dtor */
	virtual ~GLScript_Array ();

public:
	/* These are internal public functions called only by the implementation. */

	HRESULT CreateWithTypeAndLength (int type, int size);
	HRESULT CreateWithTypeAndElements (int type, BSTR pArrayConfig);	

	inline const void *GetInternalData () const { 
		return m_data; 
	}

	inline int GetInternalType () const { 
		return m_type; 
	}

	// Define OP_CAST macro for type cast operator overloading. This enables implicit type 
	// casts to appropriate types when object is passed as a parameter to OpenGL functions. 
	// Note that type checking is not done here.
	#define OP_CAST(_T) inline operator _T *() { return reinterpret_cast<_T *>(m_data); }

	OP_CAST(GLvoid);
	OP_CAST(GLbyte);
	OP_CAST(GLubyte);
	OP_CAST(GLshort);
	OP_CAST(GLushort);
	OP_CAST(GLint);
	OP_CAST(GLuint);
	OP_CAST(GLfloat);
	OP_CAST(GLdouble);
	// GLboolean is same as GLubyte. Enabling this results in function redefinition error.
	// OP_CAST(GLboolean)

	#undef OP_CAST

private:
	BOOL CheckArrayType (int type);
	void FreeArray ();
	void *AllocArray (int type, int length);
	HRESULT ScanArray (int type, BSTR pArrayConfig);	
	BOOL ConvertArrayElements (int type, wchar_t *ptr, int length, void *buff);

private:
	/* array data */
	int m_type;
	void *m_data;
	int m_length;
};

#endif /* __GLSCRIPT_SCRIPTING_ARRAY_H */

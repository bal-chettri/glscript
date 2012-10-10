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
/** gls_glu_lib.h */
#ifndef __GLS_GLU_LIB_H
 #define __GLS_GLU_LIB_H

/* includes */
#include <gls_sdk/glscript/gls_types.h>
#include <gls_sdk/glscript/gls_macros.h>
#include <gls_sdk/glscript/gls_extension.h>
#include <gls_sdk/com/dispatch.h>
#include <gls_sdk/com/class_factory.h>

#include "gls_glu_lib_interfaces.h"

/** forward declarations */
class GLSExtensionLib;

/** externs */
extern const IID *_GLSExtensionLib_IIDs[];
extern ClassFactory<GLSExtensionLib> GLSExtensionLib_Factory;

/** GLSExtensionLib class. */
class GLSExtensionLib : 
	public AutomationComObject<_GLS_GLU_Lib, _GLSExtensionLib_IIDs, &IID__GLS_GLU_Lib>
{
public:
	GLSExtensionLib ();	
	virtual ~GLSExtensionLib ();

	// internal public methods
	void _SetExtensionHost (gls::ExtensionHost *pHost) {
		m_pHost = pHost;
	}

public:
	/* _GLScriptExtLib methods */
	HRESULT STDMETHODCALLTYPE get_name (BSTR *pValue);
	HRESULT STDMETHODCALLTYPE get_version (short *pValue);

public:
	/* _GLS_GLU_Lib methods */
	HRESULT STDMETHODCALLTYPE gluNewQuadric (long *retVal) {
		*retVal = (long)::gluNewQuadric ();
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluDeleteQuadric (long qobj) {
		::gluDeleteQuadric ((GLUquadric *)qobj);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluQuadricNormals (long quadObject, unsigned int normals) {
		::gluQuadricNormals ((GLUquadric *)quadObject, normals);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluQuadricTexture (long qobj, unsigned char textureCoords) {
		::gluQuadricTexture ((GLUquadric *)qobj, textureCoords);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluQuadricOrientation (long quadObject, unsigned int orientation) {
		::gluQuadricOrientation ((GLUquadric *)quadObject, orientation);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluQuadricDrawStyle (long quadObject, unsigned int drawStyle) {
		::gluQuadricDrawStyle ((GLUquadric *)quadObject, drawStyle);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluCylinder (long qobj, double baseRadius, double topRadius,
											double height, int slices, int stacks) {
		::gluCylinder ((GLUquadric *)qobj, baseRadius, topRadius, height, slices, stacks);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluDisk (long qobj, double innerRadius, double outerRadius, 
										int slices, int loops) {
		::gluDisk ((GLUquadric *)qobj, innerRadius, outerRadius, slices, loops);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluPartialDisk (long qobj, double innerRadius, double outerRadius, 
												int slices, int loops, double startAngle, 
												double sweepAngle) {
		::gluPartialDisk ((GLUquadric *)qobj, innerRadius, outerRadius, slices, 
							loops, startAngle, sweepAngle);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluSphere (long qobj, double radius, int slices, int stacks) {
		::gluSphere ((GLUquadric *)qobj, radius, slices, stacks);
		return NOERROR;
	}

	// ver 0.2
	HRESULT STDMETHODCALLTYPE gluNewNurbsRenderer (long *retVal) {
		*retVal = reinterpret_cast<long>(::gluNewNurbsRenderer());
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluDeleteNurbsRenderer (long nobj) {
		::gluDeleteNurbsRenderer (reinterpret_cast<GLUnurbs *>(nobj));
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluNurbsProperty (long nobj, unsigned int prop, float value) {
		::gluNurbsProperty (reinterpret_cast<GLUnurbs *>(nobj), prop, value);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluBeginSurface (long nobj) {
		::gluBeginSurface (reinterpret_cast<GLUnurbs *>(nobj));
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluNurbsSurface (long nobj, 
								int sknot_count, _GLScript_Array *sknot, 
								int tknot_count, _GLScript_Array *tknot, 
								int s_stride, int t_stride, 
								_GLScript_Array *ctlarray, 
								int sorder, int torder, 
								unsigned int type)
	{
		::gluNurbsSurface (reinterpret_cast<GLUnurbs *>(nobj), 
			sknot_count, reinterpret_cast<float *>(m_pHost->GetArrayRawData(sknot)),
			tknot_count, reinterpret_cast<GLfloat *>(m_pHost->GetArrayRawData(tknot)),
			s_stride, t_stride,
			reinterpret_cast<GLfloat *>(m_pHost->GetArrayRawData(ctlarray)),
			sorder, torder,
			type);
		return NOERROR;
	}

	HRESULT STDMETHODCALLTYPE gluEndSurface (long nobj) {
		::gluEndSurface (reinterpret_cast<GLUnurbs *>(nobj));
		return NOERROR;
	}

	// private data members...
private:
	gls::ExtensionHost *m_pHost;
};

#endif /* __GLS_GLU_LIB_H */

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
/** gls_obj_model.h */
#ifndef __GLS_OBJ_MODEL_H
 #define __GLS_OBJ_MODEL_H

/* includes */
#include <gls_sdk/glscript/gls_types.h>
#include <gls_sdk/com/dispatch.h>
#include <gls_sdk/com/class_factory.h>
#include "gls_obj_lib_interfaces.h"

#include "objparser/objparser.h"

/** forward declarations */
class BoundingBox;
class GLS_OBJ_Model;

/** externs */
extern const IID *_BoundingBox_IIDs[];
extern ClassFactory<BoundingBox> BoundingBox_Factory;

extern const IID *_GLS_OBJ_Model_IIDs[];
extern ClassFactory<GLS_OBJ_Model> GLS_OBJ_Model_Factory;

/** GLS_OBJ_BoundingBox class. */
class BoundingBox : 
	public AutomationComObject<_BoundingBox, _BoundingBox_IIDs, &IID__BoundingBox>
{
	float m_width, m_height, m_depth;
public:
	HRESULT STDMETHODCALLTYPE get_width (float *retVal) {
		*retVal = m_width;
		return NOERROR;
	}
	HRESULT STDMETHODCALLTYPE get_height (float *retVal) {
		*retVal = m_height;
		return NOERROR;
	}
	HRESULT STDMETHODCALLTYPE get_depth (float *retVal) {
		*retVal = m_depth;
		return NOERROR;
	}
public:
	void _SetBoundingBox (float width, float height, float depth) {
		m_width = width;
		m_height = height;
		m_depth = depth;
	}
};

/** GLS_OBJ_Model class. */
class GLS_OBJ_Model : 
	public AutomationComObject<_ObjModel, _GLS_OBJ_Model_IIDs, &IID__ObjModel>
{
public:
	GLS_OBJ_Model ();
	virtual ~GLS_OBJ_Model ();

	/* _ObjModel methods */
	HRESULT STDMETHODCALLTYPE get_boundingBox (_BoundingBox **ppbb);
	HRESULT STDMETHODCALLTYPE render ();

	// internal public methods
public:
	BOOL _InitModel (const char *lpsz_model_path);

private:
	void CalcBoundingBox ();

	// private data members...
private:
	objparser::Parser *m_obj_parser;
	float m_width, m_height, m_depth;
	BOOL m_model_initialized;
};

#endif /* __GLS_OBJ_MODEL_H */

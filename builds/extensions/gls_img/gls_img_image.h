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
/** gls_img_image.h */
#ifndef __GLS_IMG_IMAGE_H
 #define __GLS_IMG_IMAGE_H

/* includes */
#include <gls_sdk/glscript/gls_types.h>
#include <gls_sdk/com/dispatch.h>
#include <gls_sdk/com/class_factory.h>
#include "gls_img_lib_interfaces.h"

/** forward declarations */
class GLS_IMG_Image;

/** externs */
extern const IID *_GLS_IMG_Image_IIDs[];
extern ClassFactory<GLS_IMG_Image> GLS_IMG_Image_Factory;

/** GLS_IMG_Image class. */
class GLS_IMG_Image : 
	public AutomationComObject<_Image, _GLS_IMG_Image_IIDs, &IID__Image>
{
public:
	GLS_IMG_Image ();
	virtual ~GLS_IMG_Image ();

	/* _ObjModel methods */
	HRESULT STDMETHODCALLTYPE get_x (float *retVal);
	HRESULT STDMETHODCALLTYPE put_x (float val);
	HRESULT STDMETHODCALLTYPE get_y (float *retVal);
	HRESULT STDMETHODCALLTYPE put_y (float val);
	
	HRESULT STDMETHODCALLTYPE get_width (float *retVal);
	HRESULT STDMETHODCALLTYPE put_width (float val);
	HRESULT STDMETHODCALLTYPE get_height (float *retVal);
	HRESULT STDMETHODCALLTYPE put_height (float val);
	
	HRESULT STDMETHODCALLTYPE render ();

	// internal public methods
public:
	bool _Init (const char *lpszImagePath);
	void SetupVertices ();
	void SetupTextureVertices ();
	void FixBMPUpDown (BYTE *pBits, short width, short height);

	// private data members...
private:
	GLuint m_textid;
	// short m_bmp_width, m_bmp_height;
	GLfloat m_x, m_y, m_width, m_height;
	bool m_initialized;
	GLfloat m_vertices[4 * 2];
	GLfloat m_texture_vertices[4 * 2];
};

#endif /* __GLS_IMG_IMAGE_H */

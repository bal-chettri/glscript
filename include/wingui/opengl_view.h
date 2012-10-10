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
#ifndef __wingui_opengl_view_h
  #define __wingui_opengl_view_h

#include "generic_view.h"

/* A view supporting open gl rendering */
class OpenGLView : public GenericView {
public:
	/* constructors */

	// default construction
	OpenGLView ();	

	// dtor
	~OpenGLView ();

public:
	// operations	

protected:
	/**
	 * SetupPixelFormat ()
	 * Setups the pixel format that suuports OpenGL.
	 */
	BOOL SetupPixelFormat ();

	/**
	 * CreateGLContext ()
	 * Creates OpenGL context to be used with this view.
	 */
	BOOL CreateGLContext ();

	/**
	 * DestroyGLContext ()
	 * Destroys the OpenGL context.
	 */
	void DestroyGLContext ();

	/**
	 * InitGL ()
	 * Initializes the defaults for OpenGL.
	 */
	virtual void InitGL ();

public:
	/**
	 * SetupGLView ()
	 * Setups the OpenGL view port and matrices.
	 */
	virtual void SetupGLView (int cx, int cy);

	/**
	 * SetPerspectiveViewingMode ()
	 * Sets the viewing mode to perspective.
	 */
	void SetPerspectiveViewingMode ();

	/**
	 * SetOrthographicViewingMode ()
	 * Sets the viewing mode to orthographic mode.
	 */
	void SetOrthographicViewingMode ();

	BOOL GetOrtho () const {
		return m_ortho;
	}
	
	void SetOrtho (BOOL flag) {
		m_ortho = flag;
	}
	
	/**
	 * RenderScene ()
	 * Renders the scene. The default implementation will erase the screen with 
	 * current clear color. Override to render / draw the models.
	 */
	virtual void RenderScene ();	
		
	////////////////////////////////// overrides //////////////////////////////////

protected:
	virtual void GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle);
	virtual void GetClassStyle (WNDCLASSEX &wcex);	

public:
	void ResetView ();
	void SetViewPort (GLint vpx, GLint vpy, GLsizei vpcx, GLsizei vpcy);

protected:
	// message handlers
	virtual void OnCreate ();
	virtual void OnPreDestroy ();
	virtual void OnEraseBackground (HDC hdc, PAINTSTRUCT &ps);
	virtual void OnResize (int cx, int cy);

protected:
	// data members
	HGLRC m_hGLRC;	
	GLdouble m_orthographicMatrix[16];
	GLdouble m_perspectiveMatrix[16];
	GLint m_vpLeft;
	GLint m_vpTop;
	GLsizei m_vpWidth;
	GLsizei m_vpHeight;
	BOOL m_ortho;
};

#endif /* __wingui_opengl_view_h */

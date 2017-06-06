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
#include <assert.h>

#include <wingui/opengl_view.h>

OpenGLView::OpenGLView () {
    m_hGLRC = NULL;
    m_vpLeft = 0;
    m_vpTop = 0;
    m_vpWidth = 0; // default use same as window width
    m_vpHeight = 0; // default use same as window height
    m_ortho = FALSE;
}

OpenGLView::~OpenGLView () {
}

BOOL OpenGLView::SetupPixelFormat () {
    WINGUI_ASSERT (m_hDC != NULL);

    PIXELFORMATDESCRIPTOR pfd;
    memset (&pfd, 0, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.iLayerType = PFD_MAIN_PLANE;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 32;
    
    int format = ::ChoosePixelFormat (m_hDC, &pfd); 

    if ( format > 0 && ::SetPixelFormat (m_hDC, format, &pfd) )
        return TRUE;

    return FALSE;
}

BOOL OpenGLView::CreateGLContext () {
    WINGUI_ASSERT (m_hDC != NULL && m_hGLRC == NULL);

    m_hGLRC = ::wglCreateContext (m_hDC);

    if (m_hGLRC != NULL) {

        // make the GL context current
        ::wglMakeCurrent (m_hDC, m_hGLRC);

        return TRUE;
    }

    return FALSE;
}

void OpenGLView::DestroyGLContext () {
    WINGUI_ASSERT (m_hDC != NULL && m_hGLRC != NULL);

    // detach GL context from the window's DC
    ::wglMakeCurrent (m_hDC, NULL);

    // delete the GL context and release it
    ::wglDeleteContext (m_hGLRC);

    m_hGLRC = NULL;
}

void OpenGLView::InitGL () {
    /* initialzie open gl */

    //glPolygonMode     (GL_FRONT, GL_FILL);
    //glPolygonMode     (GL_BACK, GL_LINE);
    
    //glShadeModel      (GL_SMOOTH);
    
    //glEnable          (GL_DEPTH_TEST);
    //glEnable          (GL_BLEND); 
    //glEnable          (GL_FOG);
    //glEnable          (GL_POLYGON_SMOOTH);    
    //glEnable          (GL_LINE_SMOOTH);
    
    //glBlendFunc       (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //glHint            (GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    //glHint            (GL_LINE_SMOOTH_HINT, GL_NICEST);
    
    //glClearColor      (0.0f, 0.0f, 0.0f, 1.0f);
    //glColor4f (1.0f, 1.0f, 1.0f, 1.0f);
}

// public

void OpenGLView::SetupGLView (int cx, int cy) {
    ::glViewport (m_vpLeft, m_vpTop, 
                    m_vpWidth == 0 ? (GLsizei)cx : m_vpWidth, 
                    m_vpHeight == 0 ? (GLsizei)cy : m_vpHeight
                    );

    GLdouble left, right, top, bottom;
    
    // compute 2d/3d viewing matrices
    glMatrixMode (GL_PROJECTION);

    if (m_ortho) {
        left = 0;
        right = cx;
        bottom = cy;
        top = 0;
    
        // compute 2d viewing matrix
        glLoadIdentity ();
        glOrtho (left, right, bottom, top, 0.0, 0.1); 
        glGetDoublev (GL_PROJECTION_MATRIX, m_orthographicMatrix);
    } 
    else 
    {
        // find aspect ratio
        GLdouble aspectRatio = (cx > cy 
                                ? (GLdouble)cx / (GLdouble)cy 
                                : (GLdouble)cy / (GLdouble)cx);

        GLdouble halfAspectRatio = aspectRatio / 2.0;       

        if (cx > cy) {
            left = -halfAspectRatio;
            right = halfAspectRatio;
            top = 0.5f;
            bottom = -0.5f;;
        } else {
            left = -0.5f;
            right = 0.5f;
            top = halfAspectRatio;
            bottom = -halfAspectRatio;
        }

        // compute 3d viewing matrix
        glLoadIdentity ();
        glFrustum (left, right, bottom, top, 0.5, 1.5); 
        glTranslatef (0.0f, 0.0f, -1.0);
        glGetDoublev (GL_PROJECTION_MATRIX, m_perspectiveMatrix);
    }

    if (m_ortho) {
        SetOrthographicViewingMode ();
    } else {
        SetPerspectiveViewingMode ();
    }

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void OpenGLView::SetPerspectiveViewingMode () {
    glMatrixMode (GL_PROJECTION);

    ::glLoadIdentity ();
    ::glMultMatrixd (m_perspectiveMatrix);
}

void OpenGLView::SetOrthographicViewingMode () {
    glMatrixMode (GL_PROJECTION);

    ::glLoadIdentity ();
    ::glMultMatrixd (m_orthographicMatrix);
}

void OpenGLView::RenderScene () {
    ::glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ::SwapBuffers (m_hDC);
}

/* overrides */
void OpenGLView::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) {
    dwStyle = WS_OVERLAPPED; //WS_POPUP;//;
    dwExStyle = 0;
}

void OpenGLView::GetClassStyle (WNDCLASSEX &wcex) {
    wcex.lpszClassName = _T("_gls_opengl_view");
    wcex.cbSize = sizeof(wcex);
    wcex.style = CS_OWNDC;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor (NULL, IDC_ARROW);
    wcex.hbrBackground =  NULL;
    wcex.lpszMenuName = NULL;
}

void OpenGLView::ResetView () {
    DestroyGLContext ();
    WINGUI_ASSERT (CreateGLContext ());
    InitGL ();
}

void OpenGLView::SetViewPort (GLint vpx, GLint vpy, GLsizei vpcx, GLsizei vpcy) {
    m_vpLeft = vpx;
    m_vpTop = vpy;
    m_vpWidth = vpcx;
    m_vpHeight = vpcy;
}

/* message handlers */
void OpenGLView::OnCreate () {
    GenericView::OnCreate ();

    WINGUI_ASSERT (
        SetupPixelFormat () &&
        CreateGLContext ()
        );

    InitGL ();
}

void OpenGLView::OnPreDestroy () {
    if (m_hGLRC != NULL)
        DestroyGLContext ();
    
    GenericView::OnPreDestroy ();
}

void OpenGLView::OnEraseBackground (HDC hdc, PAINTSTRUCT &ps) {
    // override OnEraseBackground to render the scene
    // instead of erasing the background
    
    RenderScene ();
}

void OpenGLView::OnResize (int cx, int cy) {
    GenericView::OnResize (cx, cy);

    SetupGLView (cx, cy);
}

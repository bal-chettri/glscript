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
#include <glsrun/glview.h>

GLView::GLView (gls::ScriptHostDriver *pScriptHostDriver) {
    m_pScriptHostDriver = pScriptHostDriver;
}

GLView::~GLView () {
}

void GLView::PostRenderSceneEvent () {
    m_pScriptHostDriver->GetScriptHost()->InvokeScriptMethod ( 
        _T("gls_renderScene"), 
        NULL, 
        0
        );
}

void GLView::PostMouseEvent (LPCTSTR lpszEventName, int button, int x, int y) {
    VARIANTARG params[3];
    int i;

    // init params
    for (i = 0; i < 3; i++) {
        ::VariantInit (params + i);
    }

    params[2].vt = VT_INT;
    params[2].intVal = button;

    params[1].vt = VT_INT;
    params[1].intVal = x;

    params[0].vt = VT_INT;
    params[0].intVal = y;

    // invoke script method for the event
    m_pScriptHostDriver->GetScriptHost()->InvokeScriptMethod ( 
        lpszEventName, 
        params, 
        sizeof(params)/sizeof(params[0]) 
        );

    // cleanup
    for (i = 0; i < 3; i++) {
        ::VariantClear (params + i);
    }
}

/* message handlers */

void GLView::OnEraseBackground (HDC hdc, PAINTSTRUCT &ps) {
    OpenGLView::OnEraseBackground (hdc, ps);

    // Note: PostRenderSceneEvent() is can cause an effect such that gls_renderScene is called at 
    // very higher rate different than its current frame rate. This usually happens when the window 
    // is uncovered from an overlapping window or from the edge of the desktop screen.

    PostRenderSceneEvent ();
}

void GLView::OnMouseDown (int shift, int button, int x, int y) {
    PostMouseEvent (_tx("gls_mouseDown"), button, x, y);
}

void GLView::OnMouseUp (int shift, int button, int x, int y) {
    PostMouseEvent (_tx("gls_mouseUp"), button, x, y);
}

void GLView::OnMouseMove (int shift, int button, int x, int y) {
    PostMouseEvent (_tx("gls_mouseMove"), button, x, y);
}

void GLView::OnKeyUp (int virtKey) {
    // #TODO: enable this
    return;

    VARIANTARG params[1];

    ::VariantInit (params + 0);
    params[0].vt = VT_INT;
    params[0].intVal = virtKey;

    // invoke script method for the event
    m_pScriptHostDriver->GetScriptHost()->InvokeScriptMethod ( 
        _tx("gls_keyUp"), 
        params, 
        sizeof(params)/sizeof(params[0]) 
        );
}

void GLView::OnKeyDown (int virtKey) {
    return;

    VARIANTARG params[1];

    ::VariantInit (params + 0);
    params[0].vt = VT_INT;
    params[0].intVal = virtKey;

    // invoke script method for the event
    m_pScriptHostDriver->GetScriptHost()->InvokeScriptMethod ( 
        _tx("gls_keyDown"), 
        params, 
        sizeof(params)/sizeof(params[0]) 
        );
}

void GLView::OnKeyPress (int virtKey, int repeatCount) {
    return;

    VARIANTARG params[1];

    ::VariantInit (params + 0);
    params[0].vt = VT_INT;
    params[0].intVal = virtKey;

    // invoke script method for the event
    m_pScriptHostDriver->GetScriptHost()->InvokeScriptMethod ( 
        _tx("gls_keyPress"), 
        params, 
        sizeof(params)/sizeof(params[0]) 
        );
}

void GLView::OnResize (int cx, int cy) {
    OpenGLView::OnResize (cx, cy);

    PostRenderSceneEvent ();
}

void GLView::OnCommand (int cmdid) {
    OpenGLView::OnCommand (cmdid);  
}

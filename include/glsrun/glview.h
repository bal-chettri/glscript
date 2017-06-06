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
#ifndef __GLSCRIPT_GUI_GLVIEW_H
 #define __GLSCRIPT_GUI_GLVIEW_H

#include <wingui/opengl_view.h>
#include <glscript/gls_scripthost_driver.h>

class GLView : public OpenGLView {
public:
    GLView (gls::ScriptHostDriver *pScriptHostDriver);
    virtual ~GLView ();

protected:
    /* message handlers */
    virtual void OnEraseBackground (HDC hdc, PAINTSTRUCT &ps);

    virtual void OnMouseDown (int shift, int button, int x, int y);
    virtual void OnMouseUp (int shift, int button, int x, int y);
    virtual void OnMouseMove (int shift, int button, int x, int y);
    virtual void OnKeyDown (int virtkey);
    virtual void OnKeyUp (int virtkey);
    virtual void OnKeyPress (int virtkey, int repeatCount);
    virtual void OnResize (int cx, int cy);
    virtual void OnCommand (int cmdid);

public:
    void PostRenderSceneEvent ();
    void PostMouseEvent (LPCTSTR lpszEventName, int button, int x, int y);

protected:
    gls::ScriptHostDriver *m_pScriptHostDriver;
};

#endif /* __GLSCRIPT_GUI_GLVIEW_H */

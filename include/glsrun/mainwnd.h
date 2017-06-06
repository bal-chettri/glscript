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
#ifndef __GLSCRIPT_GUI_MAINWND_H
#define __GLSCRIPT_GUI_MAINWND_H

#include <glscript/gls_scripthost_driver.h>
#include <wingui/main_window.h>
#include <glsrun/glview.h>
#include <glsrun/consolewnd.h>

class MainWnd;

/**
 * FullScreenContainerWnd class.
 * Implements the full screen container window class.
 */
class FullScreenContainerWnd : public GenericWindow {
public:
    FullScreenContainerWnd(MainWnd &mainWindow) : mainWnd(mainWindow) {
    }

    BOOL Create ();
    void GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle);
    void OnKeyPress (int virtkey, int repeatCount);

private:
    MainWnd &mainWnd;
};

/**
 * MainWnd class.
 * Implements the main window of the application.
 */
class MainWnd : public MainWindow, public gls::ScriptHostEvents {
public:
    // ctor
    MainWnd ();

    // dtor
    ~MainWnd ();

public:
    // operations
    void OpenScript (LPCTSTR lpszScriptPath);
    void CloseScript ();
    bool RunScript ();
    void UpdateUI ();
    void EnterFullScreenMode (BOOL flag = TRUE);
    void ToggleConsoleWindowView ();

protected:
    // GLScriptHostEvents
    void ScriptHost_OnError (gls::ScriptHost *pHost, const sys_tchar *errorMessage);
    void ScriptHost_OnChangeState (gls::ScriptHost *pHost, gls::GLSCRIPT_HOST_STATE from_state,
                                    gls::GLSCRIPT_HOST_STATE to_state);
    void ScriptHost_OnConfigureWindow (const gls::GLSCRIPT_WINDOW_CONFIG &config);
    void ScriptHost_OnLogMessage (const sys_wchar *message, gls::GLSCRIPT_LOGTYPE log_type);
    void ScriptHost_OnLogClear ();

    // message handlers...
protected:
    virtual void OnCreate ();
    virtual void OnPreDestroy ();
    virtual void OnResize (int cx, int cy);
    virtual void OnGotFocus ();
    virtual void OnDropFiles (HDROP hDrop);
    virtual void OnCommand (int cmdId); 
    
protected:
    // data members
    GLView *m_pGLView;                                  // open gl view renders scene
    gls::ScriptHostDriver *m_pScriptHostDriver;     // script host driver loads script host
    BOOL m_scriptLoaded;                                // script loaded flag
    tstring m_scriptPath;                               // path of the currently loaded script
    BOOL m_paused;                                      // animation is puased?
    tstring m_windowTitle;                              // window's title

    FullScreenContainerWnd m_fullScreenContWnd;         // full screen container window
    ConsoleWnd m_consoleWnd;                            // console window
};

#endif /* __GLSCRIPT_GUI_MAINWND_H */

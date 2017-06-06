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
#ifndef __GLSCRIPT_RUN_CONSOLE_WND_H
 #define __GLSCRIPT_RUN_CONSOLE_WND_H

#include <wingui/generic_window.h>
#include <wingui/wingui_gdi.h>

class ConsoleWnd : public GenericWindow {
public:
    enum LogType {
        logMessage,
        logWarning,
        logError
    };
public:
    ConsoleWnd ();
    virtual ~ConsoleWnd ();

public:
    BOOL Create ();

    void Log (LPCTSTR lpszText, LogType type);
    void LogMessage (LPCTSTR lpszText) {
        Log (lpszText, logMessage);
    }
    void LogWarning (LPCTSTR lpszText) {
        Log (lpszText, logWarning);
    }
    void LogError (LPCTSTR lpszText) {
        Log (lpszText, logError);
    }

    void Clear ();
    void CopyToClipboard (BOOL copyAll = TRUE); 

protected:
    // internal helper methods
    void SetOutputTextAttributes (LogType logType);
    void Output (LPCTSTR lpszText);
    void OutputEnd ();
    void ScrollMessages ();
    void PositionCursorAtEnd ();
    void SelectAll ();

protected:
    // overrides
    void GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle);

    // message handlers
    virtual void OnCreate ();
    virtual void OnPreDestroy ();
    virtual void OnResize (int cx, int cy);
    virtual void OnGotFocus ();
    virtual void OnClose (BOOL &cancel);
    virtual void OnCommand (int cmdId); 

private:
    HMENU m_hContextMenu;
    Font m_hFont;
    HWND m_hWndEdit;
    WNDPROC m_prevEditWndProc;
    static LRESULT CALLBACK EditWindowProc (HWND hWnd, UINT msg, WPARAM, LPARAM);
    
protected:
    size_t m_lineCount;
};

#endif /* __GLSCRIPT_RUN_CONSOLE_WND_H */

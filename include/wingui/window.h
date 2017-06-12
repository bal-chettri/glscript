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
#ifndef __wingui_generic_window_h
  #define __wingui_generic_window_h

#include "Object.h"

namespace wingui {

struct MBS2WST
{
    explicit MBS2WST (LPCSTR lpszText)
    {
        size_t count = strlen(lpszText);
        lpwszText = new WCHAR[count + 1];
        mbstowcs(lpwszText, lpszText, count);
        lpwszText[count] = L'\0';
    }
    ~MBS2WST ()
    {
        delete lpwszText;
    }

    inline operator LPWSTR() { return lpwszText; }
    inline operator LPCWSTR() const { return lpwszText; }

    LPWSTR lpwszText;
};

enum MouseButton
{
    kMouseButtonLeft,
    kMouseButtonRight,
    kMouseButtonMiddle
};

/* A base genreic version of win32 window */
class Window : public Object
{
public:
    // ctor
    Window ();

    // dtor
    virtual ~Window ();

public:
    /* operations */
    virtual BOOL Create (int x, int y, int cx, int cy, LPCTSTR title, Window *pParent = NULL);
    virtual BOOL Create (const RECT &rect, LPCTSTR title);
    virtual void Destroy ();

    HWND GetHandle () const;
    void AttachHandle (HWND hWnd);
    HWND DetachHandle ();
    void AttachHandleEx (HWND hWnd, BOOL mapHandle);
    HWND DetachHandleEx (BOOL unmapHandle);
    void MapProc ();
    void UnmapProc ();

    void Show (int cmd_chow = SW_SHOW);
    void Hide ();
    BOOL IsValid () const;
    BOOL IsVisible () const;
    LONG GetData () const;
    void SetData (LONG data);
    void AddChild (Window *childWnd);
    void RemoveChild (Window *childWnd);
    HWND GetParent ();
    void GetWindowRect (RECT &rt);
    void GetClientRect (RECT &rt);
    void Move (int x, int y,  int cx, int cy, bool repaint = true);
    void CenterWindow (Window *pParent = NULL);
    void SetTitleText (LPCTSTR lpszText) {
        ::SetWindowText (m_hWnd, lpszText);
    }

    // drag and drop support
    void EnableDropTarget (BOOL flag_enable = TRUE);

protected:
    /* helpers */
    void MapHandle ();
    void UnmapHandle ();    

    /* overridables */
    virtual void GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle);
    virtual void GetClassStyle (WNDCLASSEX &wcex);
    virtual LRESULT HandleMessage (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    virtual INT_PTR HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam);

    // window procedure callback
    static LRESULT CALLBACK _wndProc (HWND, UINT, WPARAM, LPARAM);
    // dialog box window procedure callback
    static INT_PTR _dlgProc (HWND hWndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
    // message handlers
    virtual void OnCreate () { }
    virtual void OnPreDestroy () { }
    virtual void OnDestroy () { }
    virtual void OnEraseBackground (HDC hdc, PAINTSTRUCT &ps) { }
    virtual void OnMouseDown (int shift, int button, int x, int y) { }
    virtual void OnMouseUp (int shift, int button, int x, int y) { }
    virtual void OnMouseMove (int shift, int button, int x, int y) { }
    virtual void OnMouseLeave () { }
    virtual void OnKeyPress (int virtkey, int repeatCount) { }
    virtual void OnKeyDown (int virtkey) { }
    virtual void OnKeyUp (int virtkey) { }
    virtual void OnPaint (HDC hdc, PAINTSTRUCT &ps) { }
    virtual void OnResize (int cx, int cy) { }
    virtual void OnGotFocus () { }
    virtual void OnLostFocus () { }
    virtual void OnContextMenu () { }
    virtual void OnCommand (int cmdId, int notifMsg);
    virtual void OnDropFiles (HDROP hdrop);
    virtual void OnClose (BOOL &cancel) { };
    virtual LRESULT OnNotify (LPNMHDR lpNotificHdr, WPARAM wParam, LPARAM lParam) 
    { 
        return ::DefWindowProc (lpNotificHdr->hwndFrom, WM_NOTIFY, wParam, lParam);
    }
    virtual void OnHScroll (int scrollPos) { }
    virtual void OnVScroll (int scrollPos) { }

protected:
    // data members
    HWND m_hWnd;                                // the actual window handle 
    BOOL m_isMainWnd;                           // is main window?
    BOOL m_isDialog;                            // is window a dialog box?
    LONG m_userData;                            // user owned data  
    BOOL m_flagMouseTracking;                   // flag for mouse tracking
    WNDPROC m_prevWndProc;
};

}; // wingui namspace

#endif /* __wingui_generic_window_h */

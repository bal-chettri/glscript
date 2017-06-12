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
#include <wingui/window.h>

extern HINSTANCE _hAppInstance;

namespace wingui {

Window::Window () {
    m_hWnd = NULL;
    m_isMainWnd = FALSE;
    m_isDialog = FALSE;
    m_userData = 0;
    m_flagMouseTracking = FALSE;
    m_prevWndProc = NULL;
}

Window::~Window () {
    if (m_hWnd != NULL) {
        ::DestroyWindow (m_hWnd);
    }
}

/* operations */
BOOL Window::Create (int x, int y, int cx, int cy, LPCTSTR title, Window *pParent) 
{
    WINGUI_ASSERT (m_hWnd == NULL);

    WNDCLASSEX wcex;
    memset (&wcex, 0, sizeof(wcex));

    // Fill in window class attributes that usually won't change    
    wcex.lpfnWndProc = _wndProc;
    wcex.hInstance = _hAppInstance;

    // get additional window class attributes
    GetClassStyle (wcex);

    // register the window class only once  
    WNDCLASSEX dummyClassInfo;
    if (!::GetClassInfoEx (_hAppInstance, wcex.lpszClassName, &dummyClassInfo))
    {
        RegisterClassEx (&wcex);
    }

    // get window creation styles
    DWORD dwStyle, dwExStyle;
    GetCreateStyle (dwStyle, dwExStyle);

    // create the window
    m_hWnd = ::CreateWindowEx (dwExStyle, wcex.lpszClassName, title, dwStyle, 
                                x, y, cx, cy, 
                                pParent ? pParent->GetHandle() : NULL, 
                                NULL, 
                                wcex.hInstance, 
                                this);
    if (m_hWnd == NULL) {
        return FALSE;
    }

    // send the OnCreate message only after the window has been created successfully
    OnCreate ();

    return TRUE;
}

BOOL Window::Create (const RECT &rect, LPCTSTR title) {
    return Create (rect.left, rect.top, 
                    rect.right - rect.left, 
                    rect.bottom - rect.top, 
                    title );
}

void Window::Destroy () {
    if (m_hWnd != NULL) {
        ::DestroyWindow (m_hWnd);
    }
}

HWND Window::GetHandle () const {
    return m_hWnd;
}

void Window::AttachHandle (HWND hWnd) {
    // handle can only be attached if window is not yet created
    WINGUI_ASSERT ( m_hWnd == NULL );

    // verify if the window is valid
    WINGUI_ASSERT ( ::IsWindow(hWnd) );

    m_hWnd = hWnd;
    
    // attaching an external window handle also maps the window handle to this object 
    // automatically
    MapHandle ();
}

HWND Window::DetachHandle () {
    WINGUI_ASSERT ( m_hWnd != NULL );

    HWND hDetached = m_hWnd;
    
    UnmapHandle();
    
    m_hWnd = NULL;

    return hDetached;
}

void Window::AttachHandleEx (HWND hWnd, BOOL mapHandle) {
    // handle can only be attached if window is not yet created
    WINGUI_ASSERT ( m_hWnd == NULL );

    // verify if the window is valid
    WINGUI_ASSERT ( ::IsWindow(hWnd) );

    m_hWnd = hWnd;
    
    if (mapHandle) {
        MapHandle ();
    }
}

HWND Window::DetachHandleEx (BOOL unmapHandle) {
    WINGUI_ASSERT ( m_hWnd != NULL );

    HWND hDetached = m_hWnd;
    
    if (unmapHandle) {
        UnmapHandle();  
    }
    
    m_hWnd = NULL;

    return hDetached;
}

void Window::Show (int cmd_show) 
{
    if (cmd_show != SW_SHOW || !IsVisible()) {
        ::ShowWindow (m_hWnd, cmd_show);
    }
}

void Window::Hide () 
{
    ::ShowWindow (m_hWnd, SW_HIDE);     
}

BOOL Window::IsValid () const 
{
    return m_hWnd && ::IsWindow (m_hWnd);
}

BOOL Window::IsVisible () const 
{
    return ::IsWindowVisible(m_hWnd); 
}

LONG Window::GetData () const 
{
    return m_userData;
}

void Window::SetData (LONG data)
{
    m_userData = data;
}

void Window::AddChild (Window *pChildWnd) {
    WINGUI_ASSERT (this->IsValid());
    WINGUI_ASSERT (pChildWnd && pChildWnd->IsValid());
    
    // First, set WS_CHILD style bit on the window to make a child
    LONG style = GetWindowLong ( pChildWnd->GetHandle(), GWL_STYLE );
    style|= WS_CHILD;
    ::SetWindowLong ( pChildWnd->GetHandle(), GWL_STYLE, style );

    // set the parent to this window
    ::SetParent ( pChildWnd->GetHandle(), GetHandle() );
}

void Window::RemoveChild (Window *pChildWnd)
{
    // hide the child window before we remove it from the window heirarchy
    pChildWnd->Hide();

    // remove from view hierarchy
    ::SetParent (pChildWnd->GetHandle(), NULL);

    // remove WS_CHILD style from the the view
    LONG style = ::GetWindowLong (pChildWnd->GetHandle(), GWL_STYLE);
    style&= ~WS_CHILD;
    ::SetWindowLong ( pChildWnd->GetHandle(), GWL_STYLE, style );
}

HWND Window::GetParent () 
{
    return ::GetParent(m_hWnd);
}

void Window::GetWindowRect (RECT &rt)
{
    WINGUI_ASSERT (
        ::GetWindowRect (m_hWnd, &rt)
    );
}

void Window::GetClientRect (RECT &rt) 
{
    WINGUI_ASSERT (
        ::GetClientRect (m_hWnd, &rt)
    );
}

void Window::Move (int x, int y, int cx, int cy, bool repaint) 
{
    ::MoveWindow (GetHandle(), x, y, cx, cy, repaint ? TRUE : FALSE);
}

void Window::CenterWindow (Window *pParent)
{
    HWND hWndParent = NULL;

    if (pParent) hWndParent = pParent->GetHandle();
    if (!hWndParent) hWndParent = ::GetDesktopWindow ();

    if (hWndParent) 
    {
        RECT rectDlg, rectParent;
        ::GetWindowRect ( m_hWnd, &rectDlg );
        //::GetClientRect ( m_hWnd, &rectDlg );

        ::GetWindowRect ( hWndParent, &rectParent );
        //::GetClientRect ( hWndParent, &rectParent );

        POINT offset = {
            rectParent.left + (rectParent.right - rectParent.left) / 2 - (rectDlg.right - rectDlg.left) / 2,
            rectParent.top + (rectParent.bottom - rectParent.top) / 2 - (rectDlg.bottom - rectDlg.top) / 2
        };

        ::MoveWindow (m_hWnd, offset.x, offset.y, rectDlg.right - rectDlg.left,
                        rectDlg.bottom - rectDlg.top, 
                        IsWindowVisible(m_hWnd) );
    }
}

void Window::EnableDropTarget (BOOL flag_enable) {
    ::DragAcceptFiles (m_hWnd, flag_enable);
}

/* helpers */
void Window::MapHandle () {
    ::SetWindowLongPtr (m_hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)this);
}

void Window::UnmapHandle () {
    ::SetWindowLongPtr ( m_hWnd , GWLP_USERDATA, 0L );
}

void Window::MapProc ()
{
    WINGUI_ASSERT(m_hWnd != NULL && m_prevWndProc == NULL);
    m_prevWndProc = (WNDPROC)(ptrdiff_t)::GetWindowLongPtr (m_hWnd, GWLP_WNDPROC);
    ::SetWindowLongPtr (m_hWnd, GWLP_WNDPROC, (__int3264)(LONG_PTR)_wndProc);

    WNDPROC test = (WNDPROC)(ptrdiff_t)::GetWindowLongPtr (m_hWnd, GWLP_WNDPROC);
}

void Window::UnmapProc ()
{
    WINGUI_ASSERT(m_prevWndProc != NULL);
    ::SetWindowLongPtr (m_hWnd, GWLP_WNDPROC, (__int3264)(LONG_PTR)m_prevWndProc);
    m_prevWndProc = NULL;
}

/* overridables */
void Window::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) {
    dwStyle = WS_OVERLAPPEDWINDOW;
    dwExStyle = 0;
}

/**
 * Fill in the default window class style attributes.
 * Window class name must be changed in the lpszClassName member if overriden
 * for custom style attributes and all attributes below must be filled in.
 */
void Window::GetClassStyle (WNDCLASSEX &wcex) {
    wcex.lpszClassName = _T("_gls_window");
    wcex.cbSize = sizeof(wcex);
    wcex.style = 0; // CS_HREDRAW | CS_VREDRAW;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor (NULL, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(48,66,97)); // (HBRUSH)COLOR_WINDOW;
    wcex.lpszMenuName = NULL;
    wcex.hInstance = _hAppInstance;
}

LRESULT Window::HandleMessage (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_MOUSEMOVE:
        if (!m_flagMouseTracking) {
            // register for mouse out message (TME_LEAVE)
            TRACKMOUSEEVENT trackMouseEvent;
            trackMouseEvent.cbSize = sizeof (trackMouseEvent);
            trackMouseEvent.dwFlags = TME_LEAVE;
            trackMouseEvent.dwHoverTime = 0;
            trackMouseEvent.hwndTrack = GetHandle ();
            m_flagMouseTracking = ::TrackMouseEvent (&trackMouseEvent);
        }
        OnMouseMove (0, -1, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_MOUSELEAVE:
        OnMouseLeave ();
        m_flagMouseTracking = FALSE;
        break;

    case WM_LBUTTONDOWN:
        OnMouseDown (0, kMouseButtonLeft, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_LBUTTONUP:
        OnMouseUp (0, kMouseButtonLeft, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_RBUTTONDOWN:
        OnMouseDown (0, kMouseButtonRight, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_RBUTTONUP:
        OnMouseUp (0, kMouseButtonRight, LOWORD(lParam), HIWORD(lParam));
        OnContextMenu ( );
        break;

    case WM_MBUTTONDOWN:
        OnMouseDown (0, kMouseButtonMiddle, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_MBUTTONUP:
        OnMouseUp (0, kMouseButtonMiddle, LOWORD(lParam), HIWORD(lParam));
        OnContextMenu ( );
        break;

    case WM_PAINT: 
        if (m_prevWndProc == NULL) {
            PAINTSTRUCT ps;
            HDC hdc = ::BeginPaint (m_hWnd, &ps);
            OnPaint (hdc, ps);
            ::EndPaint (m_hWnd, &ps);
        }
        break;

    case WM_CHAR:
        OnKeyPress ( (int)wParam, LOWORD(lParam) );
        break;

    case WM_KEYDOWN:
        OnKeyDown ( (int)wParam );
        break;

    case WM_KEYUP:
        OnKeyUp ( (int)wParam );
        break;

    case WM_NCDESTROY:
        OnPreDestroy ();
        m_hWnd = NULL;
        break;

    case WM_DESTROY:
        OnDestroy ();
        if (m_isMainWnd) {
            // ::MessageBox (0, _T("callling PostQuitMessage(0)"), _T(""), 0);
            ::PostQuitMessage (0);
        }
        break;

    case WM_SIZE:
        {
            int cx, cy;
            cx = LOWORD(lParam);
            cy = HIWORD(lParam);
            OnResize (cx, cy);
        }
        break;

    case WM_SETFOCUS:
        OnGotFocus ();
        break;

    case WM_KILLFOCUS:
        OnLostFocus ();
        break;

    case WM_COMMAND:
        OnCommand (LOWORD(wParam), HIWORD(wParam));
        break;

    case WM_CONTEXTMENU:
        OnContextMenu ();
        break;

    case WM_CLOSE:
        {
            BOOL cancel = FALSE;
            OnClose (cancel);
            if (cancel == FALSE) {
                DestroyWindow (m_hWnd);
            }
        }
        break;

    case WM_DROPFILES:
        OnDropFiles ((HDROP)wParam);
        break;

    case WM_NOTIFY:
        {
            LPNMHDR lpNotificHdr = (LPNMHDR)lParam;     
            LONG_PTR ptr = ::GetWindowLongPtr (lpNotificHdr->hwndFrom, GWLP_USERDATA);
            Window *pWnd = (Window *) ptr;      
            if (pWnd != NULL) {
                return pWnd->OnNotify (lpNotificHdr, wParam, lParam);
            }
            break;
        }

    case WM_HSCROLL:
        {
            if (LOWORD(wParam) == SB_THUMBPOSITION || LOWORD(wParam) == SB_THUMBTRACK) {
                OnHScroll (HIWORD(wParam));
            }
            break;
        }
    case WM_VSCROLL:
        {
            if (LOWORD(wParam) == SB_THUMBPOSITION || LOWORD(wParam) == SB_THUMBTRACK) {
                OnVScroll (HIWORD(wParam));
            }
            break;
        }

    default:
        if (m_prevWndProc) {
            return CallWindowProc (m_prevWndProc, hWnd, msg, wParam, lParam);
        } else {
            return ::DefWindowProc (m_hWnd, msg, wParam, lParam);
        }
    }

    if (m_prevWndProc) {
        return CallWindowProc (m_prevWndProc, hWnd, msg, wParam, lParam);
    } else {
        return 0;
    }
}

INT_PTR Window::HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_MOUSEMOVE:
        if (!m_flagMouseTracking) {
            // register for mouse out message (TME_LEAVE)
            TRACKMOUSEEVENT trackMouseEvent;
            trackMouseEvent.cbSize = sizeof (trackMouseEvent);
            trackMouseEvent.dwFlags = TME_LEAVE;
            trackMouseEvent.dwHoverTime = 0;
            trackMouseEvent.hwndTrack = GetHandle ();
            m_flagMouseTracking = ::TrackMouseEvent (&trackMouseEvent);
        }
        OnMouseMove (0, 0, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_MOUSELEAVE:
        OnMouseLeave ();
        m_flagMouseTracking = FALSE;
        break;

    case WM_PAINT: 
        if (m_prevWndProc == NULL) {
            PAINTSTRUCT ps;
            HDC hdc = ::BeginPaint (m_hWnd, &ps);
            OnPaint (hdc, ps);
            ::EndPaint (m_hWnd, &ps);
        }
        break;

    case WM_LBUTTONDOWN: OnMouseDown (0, 0, LOWORD(lParam), HIWORD(lParam)); break;
    case WM_LBUTTONUP: OnMouseUp (0, 0, LOWORD(lParam), HIWORD(lParam)); break;
    case WM_RBUTTONDOWN: OnMouseDown (0, 0, LOWORD(lParam), HIWORD(lParam)); break;
    case WM_RBUTTONUP: 
        OnMouseUp (0, 0, LOWORD(lParam), HIWORD(lParam));
        OnContextMenu ( );
        break;
    case WM_CONTEXTMENU: OnContextMenu ( ); break;

    case WM_CHAR: OnKeyPress ( (int)wParam, LOWORD(lParam) ); break;
    case WM_KEYDOWN: OnKeyDown ( (int)wParam ); break;

    case WM_NCDESTROY:      
        OnPreDestroy ();
        m_hWnd = NULL; 
        break;
    case WM_DESTROY: 
        OnDestroy ();
        break;

    case WM_SIZE: OnResize (LOWORD(lParam), HIWORD(lParam)); break;

    case WM_SETFOCUS: OnGotFocus (); break;
    case WM_KILLFOCUS: OnLostFocus (); break;

    case WM_COMMAND: OnCommand (LOWORD(wParam), HIWORD(wParam)); break;
    
    case WM_NOTIFY:
        {
            LPNMHDR lpNotificHdr = (LPNMHDR)lParam;     
            LONG_PTR ptr = ::GetWindowLongPtr (lpNotificHdr->hwndFrom, GWLP_USERDATA);
            Window *pWnd = (Window *) ptr;      
            if (pWnd != NULL) {
                return pWnd->OnNotify (lpNotificHdr, wParam, lParam);
            }
            break;
        }

    default:
        return FALSE;
    }

    return TRUE;
}

// static 
LRESULT CALLBACK Window::_wndProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    Window *pWnd = NULL;

    if (msg == WM_CREATE) {
        // get Window object
        CREATESTRUCT *cs = (CREATESTRUCT *) lParam;
        pWnd = (Window *)cs->lpCreateParams;
        WINGUI_ASSERT (pWnd);

        // map handle to this window object
        ::SetWindowLongPtr (hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)pWnd);
    } else {
        // get window object from window handle
        LONG_PTR ptr = ::GetWindowLongPtr (hWnd, GWLP_USERDATA);
        pWnd = (Window *) ptr;
    }

    if (pWnd && pWnd->GetHandle()) {
        return pWnd->HandleMessage (hWnd, msg, wParam, lParam);
    } else {
        return ::DefWindowProc (hWnd, msg, wParam, lParam);
    }
}

// static 
INT_PTR Window::_dlgProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    Window *pThis = NULL;

    if (msg == WM_INITDIALOG) {
        // map dialog window handle to its Window object
        pThis = (Window *) lParam;
        WINGUI_ASSERT (pThis);
        ::SetWindowLongPtr ( hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)pThis);
        pThis->m_hWnd = hWnd;
    } else {
        // get window object from window handle
        LONG_PTR ptr = ::GetWindowLongPtr (hWnd, GWLP_USERDATA);
        pThis = (Window *) ptr;
    }

    if (pThis) {
        return pThis->HandleDialogMessage (msg, wParam, lParam);
    } else {
        return FALSE;
    }
}

// default message handlers...

void Window::OnCommand (int cmdId, int notifMsg) 
{
    if (!m_isMainWnd) {
        // forward command messages upwards in the window hierarchy
        ::SendMessage ( this->GetParent(), WM_COMMAND, (WPARAM)cmdId, 0 );
    }
}

void Window::OnDropFiles (HDROP hdrop) {
    /*const UINT QUERY_FILE_COUNT = 0xFFFFFFFF;

    list<wstring> list_files;

    // first, query for the number of files dropped
    UINT count_files_dropped = DragQueryFile (hdrop, QUERY_FILE_COUNT, NULL, 0);

    for (UINT i = 0; i < count_files_dropped; i++) {
        // query for the size of buffer requierd to store the file path
        UINT file_path_length = DragQueryFile (hdrop, 0, NULL, 0);

        file_path_length++; // for '\0' character

        // allocate buffer file file path
        TCHAR *file_path = new TCHAR [file_path_length];

        // retrieve the file path now
        DragQueryFile (hdrop, 0, file_path, file_path_length);

        // add file name to list
        wstring str_file_path (file_path);
        list_files.push_back (str_file_path);

        delete file_path;
    }

    // process the file now
    */
}
 
}; // wingui namespace

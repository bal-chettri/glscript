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
#include <wingui/generic_window.h>

extern HINSTANCE _hAppInstance;

GenericWindow::GenericWindow () {
    m_hWnd = NULL;
    m_isMainWnd = FALSE;
    m_isDialog = FALSE;
    m_userData = 0;
    m_flagMouseTracking = FALSE;
    m_hBrushBg = NULL;
    m_hPenBorder = NULL;
}

GenericWindow::~GenericWindow () {
    WINGUI_ASSERT (m_hWnd == NULL);

    if (m_hBrushBg)
        ::DeleteObject (m_hBrushBg);

    if (m_hPenBorder)
        ::DeleteObject (m_hPenBorder);
}

/* operations */
BOOL GenericWindow::Create (int x, int y, int cx, int cy, LPCTSTR title) {
    WINGUI_ASSERT (m_hWnd == NULL);

    WNDCLASSEX wcex;
    memset (&wcex, 0, sizeof(wcex));

    // Fill in window class attributes that usually won't change    
    wcex.lpfnWndProc = _wndProc;
    wcex.hInstance = _hAppInstance;

    // get additional window class attributes
    GetClassStyle (wcex);

    // register the window class only onece 
    WNDCLASSEX dummyClassInfo;
    if (!::GetClassInfoEx (_hAppInstance, wcex.lpszClassName, &dummyClassInfo))
    {
        RegisterClassEx (&wcex);
    }

    // get window creation styles
    DWORD dwStyle, dwExStyle;
    GetCreateStyle (dwStyle, dwExStyle);

    // create the window
    m_hWnd = ::CreateWindowEx ( dwExStyle, wcex.lpszClassName, title, dwStyle, 
                                x, y, cx, cy, NULL, NULL, 
                                wcex.hInstance, this );
    if (m_hWnd == NULL)
        return FALSE;

    OnCreate ();

    return TRUE;
}

BOOL GenericWindow::Create (const RECT &rect, LPCTSTR title) {
    return Create (rect.left, rect.top, 
                    rect.right - rect.left, 
                    rect.bottom - rect.top, 
                    title );
}

void GenericWindow::Destroy () {
    WINGUI_ASSERT (m_hWnd != NULL);
    ::DestroyWindow (m_hWnd);
    // hWnd is set to NULL when WM_NCDESTROY message is received
}

HWND GenericWindow::GetHandle () const {
    return m_hWnd;
}

void GenericWindow::AttachHandle (HWND hWnd) {
    // handle can only be attached if window is not yet created
    WINGUI_ASSERT ( m_hWnd == NULL );

    // verify if the window is valid
    WINGUI_ASSERT ( ::IsWindow(hWnd) );

    m_hWnd = hWnd;
    
    MapHandle ();
}

HWND GenericWindow::DetachHandle () {
    WINGUI_ASSERT ( m_hWnd != NULL );

    HWND hDetached = m_hWnd;
    
    UnmapHandle();  
    
    m_hWnd = NULL;

    return hDetached;
}

void GenericWindow::Show (int cmd_show) {
    ::ShowWindow (m_hWnd, cmd_show);
    ::UpdateWindow (m_hWnd);
}

void GenericWindow::Hide () {
    WINGUI_ASSERT (
        ::ShowWindow (m_hWnd, SW_HIDE)
        );
}

BOOL GenericWindow::IsValid () const {
    return m_hWnd && ::IsWindow (m_hWnd);
}

LONG GenericWindow::GetData () const {
    return m_userData;
}

void GenericWindow::SetData (LONG data) {
    m_userData = data;
}

void GenericWindow::AddChild (GenericWindow *pChildWnd) {
    WINGUI_ASSERT (
        this->IsValid()&& pChildWnd->IsValid ()
        );
    
    // First, set WS_CHILD style bit on the window to make a child
    LONG style = GetWindowLong ( pChildWnd->GetHandle(), GWL_STYLE );
    style|= WS_CHILD;
    ::SetWindowLong ( pChildWnd->GetHandle(), GWL_STYLE, style );

    // set the parent to this window
    ::SetParent ( pChildWnd->GetHandle(), m_hWnd );
}

HWND GenericWindow::GetParent () {
    return ::GetParent(m_hWnd);
}

void GenericWindow::GetWindowRect (RECT &rt) {
    WINGUI_ASSERT (
        ::GetWindowRect (m_hWnd, &rt)
    );
}

void GenericWindow::GetClientRect (RECT &rt) {
    WINGUI_ASSERT (
        ::GetClientRect (m_hWnd, &rt)
    );
}

void GenericWindow::Move (int x, int y, int cx, int cy, bool repaint) {
    ::MoveWindow (GetHandle(), x, y, cx, cy, repaint ? TRUE : FALSE);   
}

void GenericWindow::CenterWindow (GenericWindow *pParent) {
    HWND hWndParent = NULL;

    if (pParent) hWndParent = pParent->GetHandle();
    if (!hWndParent) hWndParent = ::GetDesktopWindow ();

    if (hWndParent) {
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

void GenericWindow::SetBackgroundColor (COLORREF color) {
    if (m_hBrushBg != NULL) {
        ::DeleteObject (m_hBrushBg);
    }

    if (m_hPenBorder != NULL) {
        ::DeleteObject (m_hPenBorder);
    }

    m_hBrushBg = ::CreateSolidBrush (color);
    m_hPenBorder = ::CreatePen (PS_SOLID, 1, color);
}

void GenericWindow::EnableDropTarget (BOOL flag_enable) {
    ::DragAcceptFiles (m_hWnd, flag_enable);
}

/* helpers */
void GenericWindow::MapHandle () {
    ::SetWindowLongPtr (m_hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)this);
}

void GenericWindow::UnmapHandle () {
    ::SetWindowLongPtr ( m_hWnd , GWLP_USERDATA, 0L );
}

/* overridables */
void GenericWindow::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) {
    dwStyle = WS_OVERLAPPEDWINDOW;
    dwExStyle = 0;
}

/**
 * Fill in the default window class style attributes.
 * Window class name must be changed in the lpszClassName member if overriden
 * for custom style attributes and all attributes below must be filled in.
 */
void GenericWindow::GetClassStyle (WNDCLASSEX &wcex) {
    wcex.lpszClassName = _T("_gls_window");
    wcex.cbSize = sizeof(wcex);
    wcex.style = 0; // CS_HREDRAW | CS_VREDRAW;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor (NULL, IDC_ARROW);
    wcex.hbrBackground =  NULL; // CreateSolidBrush(RGB(100,100,100));
    wcex.lpszMenuName = NULL;
    wcex.hInstance = _hAppInstance;
}

LRESULT GenericWindow::HandleMessage (UINT msg, WPARAM wParam, LPARAM lParam) {
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
        OnMouseDown (0, 0, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_LBUTTONUP:
        OnMouseUp (0, 0, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_RBUTTONDOWN:
        OnMouseDown (0, 1, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_RBUTTONUP:
        OnMouseUp (0, 1, LOWORD(lParam), HIWORD(lParam));
        OnContextMenu ( );
        break;

    case WM_ERASEBKGND:
        // we'll erase the background during the WM_PAINT message as necessary
        // to support dynamic background color for views
        // return FALSE to indicate we didn't erase the background here.
        return FALSE;

    case WM_PAINT: 
        {
            PAINTSTRUCT ps;
            HDC hdc = ::BeginPaint (m_hWnd, &ps);

            // erase the background if required
            if (ps.fErase) {
                OnEraseBackground (hdc, ps);
                ps.fErase = FALSE;
            }

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
        OnCommand ( LOWORD(wParam) );
        break;

    case WM_CONTEXTMENU:
        OnContextMenu ( );
        break;

    case WM_CLOSE:
        {
            BOOL cancel = FALSE;
            OnClose (cancel);
            if (cancel == FALSE) 
                DestroyWindow (m_hWnd);
        }
        break;

    case WM_DROPFILES:
        OnDropFiles ((HDROP)wParam);
        break;

    default:
        return ::DefWindowProc (m_hWnd, msg, wParam, lParam);
    }

    return 0;
}

INT_PTR GenericWindow::HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam) {
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

    case WM_LBUTTONDOWN:
        OnMouseDown (0, 0, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_LBUTTONUP:
        OnMouseUp (0, 0, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_RBUTTONDOWN:
        OnMouseDown (0, 0, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_RBUTTONUP:
        OnMouseUp (0, 0, LOWORD(lParam), HIWORD(lParam));
        OnContextMenu ( );
        break;

    case WM_CHAR:
        OnKeyPress ( (int)wParam, LOWORD(lParam) );
        break;

    case WM_KEYDOWN:
        OnKeyDown ( (int)wParam );
        break;

    case WM_NCDESTROY:
        OnPreDestroy ();
        m_hWnd = NULL;
        break;

    case WM_DESTROY:
        OnDestroy ();
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
        OnCommand ( LOWORD(wParam) );
        break;

    case WM_CONTEXTMENU:
        OnContextMenu ( );
        break;

    default:
        return FALSE;
    }

    return TRUE;
}

// static 
LRESULT CALLBACK GenericWindow::_wndProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    GenericWindow *pWnd = NULL;

    if (msg == WM_CREATE) {
        // get GenericWindow object
        CREATESTRUCT *cs = (CREATESTRUCT *) lParam;
        pWnd = (GenericWindow *)cs->lpCreateParams;
        WINGUI_ASSERT (pWnd);

        // bind HWND with the Sim8085IdeWindow object 
        ::SetWindowLongPtr ( hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)pWnd);
    } else {
        // get window object from window handle
        LONG_PTR ptr = ::GetWindowLongPtr (hWnd, GWLP_USERDATA);
        pWnd = (GenericWindow *) ptr;
    }

    if (pWnd) {
        return pWnd->HandleMessage (msg, wParam, lParam);
    }

    return ::DefWindowProc (hWnd, msg, wParam, lParam);
}

// static 
INT_PTR GenericWindow::_dlgProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    GenericWindow *pThis = NULL;

    if (msg == WM_INITDIALOG) {         
        // map dialog window handle to its GenericWindow object
        pThis = (GenericWindow *) lParam;       
        ::SetWindowLongPtr ( hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)pThis);
        pThis->m_hWnd = hWnd;
    }
    else {
        // get window object from window handle
        LONG_PTR ptr = ::GetWindowLongPtr (hWnd, GWLP_USERDATA);
        pThis = (GenericWindow *) ptr;
    }

    if (pThis) {
        return pThis->HandleDialogMessage (msg, wParam, lParam);
    }

    return FALSE;
}

// default message handlers...

void GenericWindow::OnCreate () {
    // set window properties
    SetBackgroundColor ( RGB(250,250,255) );
}

void GenericWindow::OnEraseBackground (HDC hdcDraw, PAINTSTRUCT &ps) {
    HGDIOBJ hOldBrush, hOldPen;
    RECT rt;

    GetClientRect (rt);

    hOldBrush = ::SelectObject (hdcDraw, m_hBrushBg);
    hOldPen = ::SelectObject (hdcDraw, m_hPenBorder );

    // Erase background
    //::Rectangle (hdcDraw, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right, ps.rcPaint.bottom);
    ::Rectangle (hdcDraw, rt.left, rt.top, rt.right, rt.bottom);

    // do cleanup
    ::SelectObject (hdcDraw, hOldBrush);
    ::SelectObject (hdcDraw, hOldPen);
}

void GenericWindow::OnCommand (int cmdId) {
    if (!m_isMainWnd) {
        // forward command messages upwards in the window hierarchy
        ::SendMessage ( this->GetParent(), WM_COMMAND, (WPARAM)cmdId, 0 );
    }
}

void GenericWindow::OnDropFiles (HDROP hdrop) {
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
 
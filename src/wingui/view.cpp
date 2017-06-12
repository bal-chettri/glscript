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
#include <wingui/view.h>

extern HINSTANCE _hAppInstance;

namespace wingui {

View::View ()  :
    _resizable(TRUE),
    _contextMenuId(-1),
    _hMenu(NULL)
{   
}

View::~View () 
{
}

BOOL View::Create (int x, int y, int cx, int cy, Window *pParent) 
{
    // views must have a parent window
    WINGUI_ASSERT (pParent != NULL);
    
    // compute view's rect for specified client size
    DWORD dwStyle, dwExStyle;
    GetCreateStyle (dwStyle, dwExStyle);
    RECT window_rect = { 0, 0, cx, cy };
    ::AdjustWindowRect (&window_rect, dwStyle, FALSE);
    cx = window_rect.right - window_rect.left;
    cy = window_rect.bottom - window_rect.top;

    // set frame
    _frame.x1 = x;
    _frame.y1 = y;
    _frame.x2 = x + cx - 1;
    _frame.y2 = y + cy - 1;

    // call base implementation to create the view's window
    return Window::Create(x, y, cx, cy, NULL, pParent);
}

BOOL View::Create (const RECT &rect, Window *pParent) 
{
    return Create (rect.left, rect.top, 
                    rect.right - rect.left + 1, 
                    rect.bottom - rect.top + 1,
                    pParent);
}

BOOL View::Create (int resourceId, Window *pParent)
{
    // create a view from a dialog box resource
    WINGUI_ASSERT (pParent != NULL);
    m_hWnd = ::CreateDialogParam ( _hAppInstance, 
                                    MAKEINTRESOURCE(resourceId),
                                    pParent->GetHandle(), 
                                    (DLGPROC)_dlgProc, 
                                    (LPARAM) this
                                    );
    if (m_hWnd != NULL) {
        OnCreate ();
    }

    return TRUE;
}

void View::AddSubView (View *pSubView) 
{
    WINGUI_ASSERT (pSubView && pSubView->IsValid());

    LONG style = ::GetWindowLong (pSubView->GetHandle(), GWL_STYLE);
    style|= WS_VISIBLE; // set auto visible
    ::SetWindowLong ( pSubView->GetHandle(), GWL_STYLE, style );

    _subViews.push_back (pSubView);
    AddChild ( pSubView );
}

void View::RemoveSubView (View *pSubView) 
{
    WINGUI_ASSERT (pSubView && pSubView->IsValid());
    _subViews.remove (pSubView);
    RemoveChild(pSubView);
}

void View::RemoveAllSubViews () 
{
    std::list<View *>::iterator it;
    
    for (it = _subViews.begin(); it != _subViews.end(); ++it) {
        View *pSubView = *it;

        // remove from sub view list 
        _subViews.remove (pSubView);

        // from from view hierarchy
        ::SetParent (pSubView->GetHandle(), NULL);

        // remove WS_CHILD style from the the view
        LONG style = ::GetWindowLong (pSubView->GetHandle(), GWL_STYLE);
        style&= ~WS_CHILD;
        ::SetWindowLong ( pSubView->GetHandle(), GWL_STYLE, style );
    }

    _subViews.clear ();
}

void View::CenterView (Window *pParent) {
    HWND hWndParent = NULL;

    if (pParent) hWndParent = pParent->GetHandle();
    if (!hWndParent) hWndParent = ::GetDesktopWindow ();

    if (hWndParent) {
        RECT rectDlg, rectParent;
        // ::GetWindowRect ( m_hWnd, &rectDlg );
        ::GetClientRect ( m_hWnd, &rectDlg );

        // ::GetWindowRect ( hWndParent, &rectParent );
        ::GetClientRect ( hWndParent, &rectParent );

        POINT offset = {
            rectParent.left + (rectParent.right - rectParent.left) / 2 - (rectDlg.right - rectDlg.left) / 2,
            rectParent.top + (rectParent.bottom - rectParent.top) / 2 - (rectDlg.bottom - rectDlg.top) / 2
        };

        ::MoveWindow (m_hWnd, offset.x, offset.y, rectDlg.right - rectDlg.left,
                        rectDlg.bottom - rectDlg.top, 
                        IsWindowVisible(m_hWnd) );
    }
}

void View::SetFocus()
{
    ::SetFocus(GetHandle());
}

void View::SetContextMenuId(int id)
{
    if (_contextMenuId != id) {
        _contextMenuId = id;
        if (_hMenu) {
            ::DestroyMenu(_hMenu);
        }
        _hMenu = ::LoadMenu(NULL, MAKEINTRESOURCE(_contextMenuId));
        WINGUI_ASSERT(_hMenu != NULL);
    }
}

void View::ShowContextMenu(int menuIndex)
{
    WINGUI_ASSERT(_hMenu != NULL);
    HMENU hMenu = GetSubMenu(_hMenu, menuIndex);
    WINGUI_ASSERT(hMenu != NULL);
    POINT pt;
    GetCursorPos(&pt);
    ::TrackPopupMenu(hMenu, TPM_TOPALIGN | TPM_LEFTALIGN | TPM_NOANIMATION, 
                     pt.x, pt.y, 0, GetHandle(), NULL);
}

void View::SetFont(HFONT hFont)
{
    LPARAM lParam;
    if (IsVisible()) {
        lParam = MAKELPARAM(TRUE,0);
    } else {
        lParam = 0;
    }
    ::SendMessage (GetHandle(), WM_SETFONT, (WPARAM)hFont, lParam);
}

/* rendering */
void View::RefreshView () {
    CalcLayout ();

    RECT rect;
    GetClientRect (rect );

    ::InvalidateRect ( GetHandle (), &rect, TRUE );
}

void View::RedrawView () {
    RECT rect;
    GetClientRect ( rect );
    ::InvalidateRect ( GetHandle (), &rect, TRUE );
}

// ILayout implementation
ILayout::Frame View::GetFrame ()
{   
    /*
    RECT rect;
    GetClientRect(rect);
    return Frame(rect.left, rect.top, rect.right, rect.bottom);
    */
    return _frame;
}

void View::SetFrame (const Frame &f)
{
    _frame = f;
    ::MoveWindow(m_hWnd, f.x1, f.y1, f.x2 - f.x1, f.y2 - f.y1, TRUE);
}

void View::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) 
{
    dwStyle = WS_CHILD;
    dwExStyle = 0;
}

void View::GetClassStyle (WNDCLASSEX &wcex) 
{
    wcex.lpszClassName = _T("_gls_view");
    wcex.cbSize = sizeof(wcex);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hIcon = NULL;
    wcex.hIconSm = NULL;
    wcex.hCursor = LoadCursor (NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)COLOR_WINDOW; // CreateSolidBrush(RGB(128,128,255));
    wcex.lpszMenuName = NULL;
    wcex.hInstance = _hAppInstance;
}

void View::OnCreate () {
    Window::OnCreate ();
}

void View::OnPreDestroy () {
    if (_hMenu) {
        ::DestroyMenu(_hMenu);
        _hMenu = NULL;
    }
    Window::OnPreDestroy ();
}

void View::OnMouseDown (int shift, int button, int x, int y) 
{
    ::SetFocus (GetHandle());
}

// cals CalcLayout ()
void View::OnResize (int cx, int cy) 
{
    // re calculate view layout when resized
    CalcLayout ();
}

};// wingui namespace

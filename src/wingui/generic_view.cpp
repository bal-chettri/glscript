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
#include <wingui/generic_view.h>

GenericView::GenericView () {	
	m_opacity = 1.0f;
	m_hDC = NULL;
	m_isDoubleBuffered = FALSE;
}

GenericView::~GenericView () {	
}

BOOL GenericView::Create (int x, int y, int cx, int cy) {
	if ( GenericWindow::Create (0, 0, 1, 1, NULL) ) 
	{
		// set style bits for a view
		LONG style = ::GetWindowLong (m_hWnd, GWL_STYLE);
		
		style&= ~WS_CAPTION; // remove title bar

		style&= ~WS_VISIBLE; // set auto visible FALSE		

		::SetWindowLong ( m_hWnd, GWL_STYLE, style );

		// resize the view
		MoveWindow (GetHandle(), x, y, cx, cy, FALSE);				
		return TRUE;
	}

	return FALSE;
}

BOOL GenericView::Create (const RECT &rect) {
	return Create (rect.left, rect.top, 
					rect.right - rect.left + 1, 
					rect.bottom - rect.top + 1);
}

void GenericView::AddSubView (GenericView *pSubView) {
	WINGUI_ASSERT (pSubView && pSubView->IsValid());

	LONG style = ::GetWindowLong (pSubView->GetHandle(), GWL_STYLE);
	style|= WS_VISIBLE; // set auto visible
	::SetWindowLong ( pSubView->GetHandle(), GWL_STYLE, style );

	m_subViews.push_back (pSubView);
	AddChild ( pSubView );
}

void GenericView::RemoveSubView (GenericView *pSubView) {
	// remove from sub view list 
	m_subViews.remove (pSubView);

	// from from view hierarchy
	::SetParent (pSubView->GetHandle(), NULL);

	// remove WS_CHILD style from the the view
	LONG style = ::GetWindowLong (pSubView->GetHandle(), GWL_STYLE);
	style&= ~WS_CHILD;
	::SetWindowLong ( pSubView->GetHandle(), GWL_STYLE, style );
}

void GenericView::RemoveAllSubViews () {
	list<GenericView *>::iterator it;
	
	for (it = m_subViews.begin(); it != m_subViews.end(); it++) {
		GenericView *pSubView = *it;

		// remove from sub view list 
		m_subViews.remove (pSubView);

		// from from view hierarchy
		::SetParent (pSubView->GetHandle(), NULL);

		// remove WS_CHILD style from the the view
		LONG style = ::GetWindowLong (pSubView->GetHandle(), GWL_STYLE);
		style&= ~WS_CHILD;
		::SetWindowLong ( pSubView->GetHandle(), GWL_STYLE, style );
	}

	m_subViews.clear ();
}

void GenericView::CenterView (GenericWindow *pParent) {
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

void GenericView::SetOpacity (float opacity) {
	// #TODO: set window opacity
}

void GenericView::SetDoubleBuffered (BOOL flag) {
	if (flag == m_isDoubleBuffered)
		return;

	// #TODO: set or disable double buffering
	if (m_isDoubleBuffered) {

	} else {

	}
}

/* rendering */
void GenericView::RefreshView () {
	CalcLayout ();

	RECT rect;
	GetClientRect (rect );

	::InvalidateRect ( GetHandle (), &rect, TRUE );
}

void GenericView::RedrawView () {
	RECT rect;
	GetClientRect ( rect );
	::InvalidateRect ( GetHandle (), &rect, TRUE );
}

void GenericView::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) {
	dwStyle = WS_OVERLAPPED;
	dwExStyle = 0;
}

void GenericView::GetClassStyle (WNDCLASSEX &wcex) {
	wcex.lpszClassName = _T("_gls_view");
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hIcon = NULL;
	wcex.hIconSm = NULL;
	wcex.hCursor = LoadCursor (NULL, IDC_ARROW);
	wcex.hbrBackground = NULL;
	wcex.lpszMenuName = NULL;
}

void GenericView::OnCreate () {
	GenericWindow::OnCreate ();

	// cache window DC for performance
	m_hDC = ::GetDC (m_hWnd);

	// initialize window specific properties
	SetBackgroundColor ( RGB(200,200,200) );

	SetDoubleBuffered ( FALSE );
}

void GenericView::OnPreDestroy () {
	// release cached DC
	if (m_hDC != NULL) {
		::ReleaseDC (m_hWnd, m_hDC);
		m_hDC = NULL;
	}

	GenericWindow::OnPreDestroy ();
}

// cals CalcLayout ()
void GenericView::OnResize (int cx, int cy) {
	// re calculate view layout when resized
	CalcLayout ();
}

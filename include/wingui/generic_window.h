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

#if defined (DEBUG) || defined(_DEBUG)
 #define WINGUI_ASSERT(M)	assert(M)
#else
 #define WINGUI_ASSERT(M)	M
#endif

/* A base genreic version of win32 window */
class GenericWindow {
public:
	// ctor
	GenericWindow ();

	// dtor
	virtual ~GenericWindow ();

public:
	/* operations */
	virtual BOOL Create (int x, int y, int cx, int cy, LPCTSTR title);
	virtual BOOL Create (const RECT &rect, LPCTSTR title);
	void Destroy ();
	HWND GetHandle () const;
	void AttachHandle (HWND hWnd);
	HWND DetachHandle ();
	void Show (int cmd_chow = SW_SHOW);
	void Hide ();
	BOOL IsValid () const;
	LONG GetData () const;
	void SetData (LONG data);
	void AddChild (GenericWindow *childWnd);
	HWND GetParent ();
	void GetWindowRect (RECT &rt);
	void GetClientRect (RECT &rt);
	void Move (int x, int y,  int cx, int cy, bool repaint = true);
	void CenterWindow (GenericWindow *pParent = NULL);
	void SetBackgroundColor (COLORREF color);
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
	virtual LRESULT HandleMessage (UINT msg, WPARAM wParam, LPARAM lParam);
	virtual INT_PTR HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam);

	// window procedure callback
	static LRESULT CALLBACK _wndProc (HWND, UINT, WPARAM, LPARAM);
	// dialog box window procedure callback
	static INT_PTR _dlgProc (HWND hWndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
	// message handlers
	virtual void OnCreate ();
	virtual void OnPreDestroy () { }
	virtual void OnDestroy () { }
	virtual void OnEraseBackground (HDC hdc, PAINTSTRUCT &ps);
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
	virtual void OnCommand (int cmdId);
	virtual void OnDropFiles (HDROP hdrop);
	virtual void OnClose (BOOL &cancel) { };

protected:
	// data members
	HWND m_hWnd;								// the actual window handle	
	BOOL m_isMainWnd;							// is main window?
	BOOL m_isDialog;							// is window a dialog box?
	LONG m_userData;							// user owned data	
	BOOL m_flagMouseTracking;					// flag for mouse tracking
	HBRUSH m_hBrushBg;							// background brush
	HPEN m_hPenBorder;							// background border pen
};

#endif /* __wingui_generic_window_h */

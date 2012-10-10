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
#ifndef __wingui_generic_view_h
  #define __wingui_generic_view_h

#include "generic_window.h"

using namespace std;

/* A base genreic version of win32 view */
class GenericView : public GenericWindow {
public:
	/* constructors */

	// default construction
	GenericView ();	

	// dtor
	virtual ~GenericView ();

public:
	// operations
	virtual BOOL Create (int x, int y, int cx, int cy);
	virtual BOOL Create (const RECT &rect);	

	// view management
	void AddSubView (GenericView *subView);
	void RemoveSubView (GenericView *subView);
	void RemoveAllSubViews ();
	void GenericView::CenterView (GenericWindow *pParent);
	void SetOpacity (float opacity);
	void SetDoubleBuffered (BOOL flag = TRUE);

	HDC GetCachedDC () {
		return m_hDC;
	}

	/* rendering */
	// calls CalcLayout () and invalidates the view
	void RefreshView ();
	// invalidates the view
	void RedrawView ();
	// compute layout for rendering data
	virtual void CalcLayout () { }

protected:
	virtual void GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle);
	virtual void GetClassStyle (WNDCLASSEX &wcex);

	virtual void OnCreate ();
	virtual void OnPreDestroy ();
	virtual void OnResize (int cx, int cy);

protected:
	// data members	
	float m_opacity;							// background opacity
	HDC m_hDC;									// cached window DC for performance
	BOOL m_isDoubleBuffered;					// use double buffered window
	list<GenericView *>m_subViews;				// child / sub views
}; 

#endif /* __wingui_generic_view_h */

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

#include <wingui/wingui_gdi.h>

BOOL Font::Create (LPCTSTR lpszFaceName, int size, HDC hRefDC, LONG lfWeight) 
{
	Delete ();

	LOGFONT logfont;
	memset (&logfont, 0, sizeof(logfont));
	logfont.lfCharSet = DEFAULT_CHARSET;
	logfont.lfHeight = size;
	logfont.lfWeight = lfWeight;
	lstrcpyn (logfont.lfFaceName, lpszFaceName,
			sizeof(logfont.lfFaceName) - 1);

	HDC hdc = hRefDC == NULL ? ::GetDC (NULL) : hRefDC;
	if (!hdc) return FALSE;
	
	// lfHeight must be scaled based on passed DC units
	POINT pt, ptOrg = {0, 0};
	pt.y = ::GetDeviceCaps (hdc, LOGPIXELSY) * logfont.lfHeight;
	pt.y/= 72;    // 72 points/inch, 10 decipoints/point
	::DPtoLP (hdc, &pt, 1);
	::DPtoLP (hdc, &ptOrg, 1);
	logfont.lfHeight = -abs(pt.y - ptOrg.y);

	if (hRefDC == NULL) ::ReleaseDC (NULL, hdc);

	// create the point font
	m_hFont = ::CreateFontIndirect (&logfont);
	return m_hFont != NULL;
}


////////////////////////////////////////////////////////////////////////
// MemoryBitmap

BOOL MemoryBitmap::Create (int cx, int cy, HDC hRefDC)
{
	Dispose ();

	if ( !(m_hDC = ::CreateCompatibleDC (hRefDC)) )
		return FALSE;

	// load the imagesheet bitmap from the app resource
	if ( !(m_hBitmap = ::CreateCompatibleBitmap (hRefDC, cx, cy)) )
	{
		::DeleteDC (m_hDC);
		m_hDC = NULL;
		return FALSE;
	}

	// save current bitmap and select the image sheet bitmap into the DC
	m_hOldBitmap = ::SelectObject (m_hDC, (HGDIOBJ) m_hBitmap);

	return TRUE;
}

void MemoryBitmap::Dispose ()
{
	if (m_hDC != NULL)
	{
		::SelectObject (m_hDC, m_hOldBitmap);
		::DeleteObject ((HGDIOBJ)m_hBitmap);

		m_hBitmap = NULL;
		m_hOldBitmap = NULL;

		DeleteDC (m_hDC);
		m_hDC = NULL;
	}
}

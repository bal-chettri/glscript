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
#ifndef __WINGUI_GDI_H
 #define __WINGUI_GDI_H

namespace wingui {
/**
 * Font class
 */
class Font 
{
protected:
    HFONT m_hFont;
public:
    Font () {
        m_hFont = NULL;
    }

    Font (LPCTSTR lpszFaceName, int size, HDC hdc) {
        m_hFont = NULL;
        Create (lpszFaceName, size, FW_NORMAL, hdc);
    }

    Font (const Font &fnt) {
        m_hFont = NULL;
    }

    ~Font () {
        Delete ();
    }

    BOOL Create (LPCTSTR lpszFaceName, int size, LONG lfWieght, HDC hRefDC);
    inline BOOL Create (LPCTSTR lpszFaceName, int size, HDC hdc);
    inline BOOL Create (LPCTSTR lpszFaceName, int size);

    inline operator HFONT() const {
        return m_hFont;
    }

    void Delete () {
        if (m_hFont) {
            DeleteObject (m_hFont);
            m_hFont = NULL;
        }
    }
};

inline BOOL Font::Create (LPCTSTR lpszFaceName, int size, HDC hRefDC) 
{
    return Create (lpszFaceName, size, FW_NORMAL, hRefDC);
}

inline BOOL Font::Create (LPCTSTR lpszFaceName, int size)
{
    HDC hdc = CreateCompatibleDC (NULL);
    BOOL ret = Create (lpszFaceName, size, FW_NORMAL, hdc);
    ::DeleteDC (hdc);
    return ret;
}

/**
 * Color class
 */
class Color {
public:
    COLORREF value;

    Color () { }
    Color (COLORREF rgb) : value(rgb) { }
    Color (const Color &color) {
        value = color.value;
    }

    Color SetRGB (BYTE r, BYTE g, BYTE b) {
        value = RGB (r, g, b);
    }

    void GetRGB (BYTE r, BYTE g, BYTE b) {
        r = GetRValue (value);
        g = GetGValue (value);
        b = GetBValue (value);
    }
    
    Color GetBrighter (int factor = 10) {
        BYTE red = GetRValue(value) + factor;
        BYTE green = GetRValue(value) + factor;
        BYTE blue = GetRValue(value) + factor;

        red = red > 255 ? 255 : red;
        green = green > 255 ? 255 : green;
        blue = blue > 255 ? 255 : blue;

        return Color ( RGB(red, green, blue) );
    }

    Color GetDarker (float scaleFactor = 0.2f) {
        float red = (float)GetRValue(value) / 255.0f;
        float green = (float)GetRValue (value) / 255.0f;
        float blue = (float)GetRValue (value) / 255.0f;

        red = red - 0.25f;
        green = green - 0.25f;
        blue = blue - 0.25f;

        red = red < 0.0f ? 0.0f : red;
        green = green < 0.0f ? 0.0f : green;
        blue = blue < 0.0f ? 0.0f : blue;

        return Color ( RGB((int)red, (int)green, (int)blue) );
    }

    static Color GrayColor (BYTE value) {
        return Color (RGB (value, value, value));
    }
    static Color RedColor () {  
        return Color ( RGB(255,0,0) );
    }
    static Color GreenColor () { 
        return Color ( RGB(0,255,0) );
    } 
    static Color BlueColor () {  
        return Color ( RGB(0,0,255) );
    } 
};

class MemoryBitmap 
{
protected:
    HBITMAP m_hBitmap;
    HGDIOBJ m_hOldBitmap;
    HDC m_hDC;

public:
    MemoryBitmap () {
        m_hBitmap = NULL;
        m_hOldBitmap = NULL;
        m_hDC = NULL;
    }

    ~MemoryBitmap () {
        Dispose ();
    }

    HDC GetDC () const {
        return m_hDC;
    }

    BOOL Create (int cx, int cy, HDC hRefDC = NULL);
    void Dispose ();
};

}; // wingui namespace

#endif /* __WINGUI_GDI_H */

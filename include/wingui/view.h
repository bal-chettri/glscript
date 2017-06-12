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

#include "window.h"
#include "Layout.h"

#include <list>

namespace wingui {

/* A base genreic version of win32 view */
class View : public Window, public ILayout
{
public:
    /* constructors */

    // default construction
    View ();    

    // dtor
    virtual ~View ();

public:
    // operations
    virtual BOOL Create (int x, int y, int cx, int cy, Window *pParent);
    virtual BOOL Create (const RECT &rect, Window *pParent);
    virtual BOOL Create (int resourceId, Window *pParent);

    // view management
    std::list<View *>   GetSubViews() { return _subViews; }

    void AddSubView (View *subView);
    void RemoveSubView (View *subView);
    void RemoveAllSubViews ();
    void CenterView (Window *pParent);
    void SetFocus();

    // dialog control support functions. These functions allows to work with dialog controls
    // directly without requiring to bind view objects to controls.
    HWND GetControl(int id) { return ::GetDlgItem(GetHandle(), id); }
    void CheckButton(int btnId) { ::CheckDlgButton(GetHandle(), btnId, BST_CHECKED); }
    void UncheckButton(int btnId) { ::CheckDlgButton(GetHandle(), btnId, BST_UNCHECKED); }
    void CheckButton(int btnId, BOOL flag) 
    { 
        if (flag)
            CheckButton(btnId);
        else
            UncheckButton(btnId);
    }
    BOOL IsButtonChecked(int btnId) { return ::IsDlgButtonChecked(GetHandle(), btnId); }
    
    void SetControlText (int id, LPCTSTR lpszText) { ::SetDlgItemText (GetHandle(), id, lpszText); }
    TCHAR *GetControlText (int id, TCHAR *pBuffer, int cchMax)
    {
        ::GetDlgItemText(GetHandle(), id, pBuffer, cchMax);
        return pBuffer;
    }
    wingui_tstring GetControlString(int id)
    {
        HWND hCtrl = GetControl(id);
        int length = GetWindowTextLength(hCtrl);
        if (length > 0)
        {
            TCHAR *pBuffer = new TCHAR[length + 1];
            GetDlgItemText(GetHandle(), id, pBuffer, length + 1);
            wingui_tstring str(pBuffer);
            delete [] pBuffer;
            return str;
        }
        return wingui_tstring(_T(""));
    }

    int GetControlInt (int id)
    {
        BOOL translated = FALSE;
        return (int)::GetDlgItemInt(m_hWnd, id, &translated, TRUE);
    }
    void SetControlInt(int id, int value)
    {
        TCHAR buff[30];
        _stprintf(buff, _T("%d"), value);
        SetControlText(id, buff);
    }
    float GetControlFloat (int id)
    {
        TCHAR buff[30];
        GetControlText(id, buff, 30);
#ifdef UNICODE
        return (float)_wtof(buff);
#else       
        return(float)atof(buff);
#endif
    }
    void SetControlFloat (int id, float value)
    {
        TCHAR buff[30];
        _stprintf(buff, _T("%.2f"), value);
        SetControlText(id, buff);
    }
    void EnableControl (int id, BOOL flag = TRUE) { ::EnableWindow (GetControl(id), flag); }
    void FocusControl (int id) { ::SetFocus(GetControl(id)); }

    // context menu support
    inline int GetContextMenuId() const { return _contextMenuId; }
    inline HMENU GetContextMenu() const { return _hMenu; }
    void SetContextMenuId(int id);
    void ShowContextMenu(int menuIndex);

    void SetFont(HFONT hFont);

    // UI
    virtual void CalcLayout () { }
    virtual void UpdateUI () { }
    void RefreshView ();
    void RedrawView ();

    // ILayout implementation
    virtual Frame GetFrame ();
    virtual void SetFrame (const Frame &f);
    virtual BOOL IsResizable () { return _resizable; }
    virtual void SetResizable (BOOL flag) { _resizable = flag; }
    virtual BOOL IsContainer () { return FALSE; }

protected:
    virtual void GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle);
    virtual void GetClassStyle (WNDCLASSEX &wcex);

    virtual void OnCreate ();
    virtual void OnPreDestroy ();
    virtual void OnMouseDown (int shift, int button, int x, int y);
    virtual void OnResize (int cx, int cy);

private:
    Frame               _frame;
protected:
    // data members 
    std::list<View *>   _subViews;
    BOOL                _resizable;
    int                 _contextMenuId;
    HMENU               _hMenu;
}; 

}; // wingui namespace

#endif /* __wingui_generic_view_h */

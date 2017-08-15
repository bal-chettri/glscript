#include "stdafx.h"
#include <glscript/gls_string_utils.h>
#include <string.h>
#include <stdlib.h>

namespace gls
{

WS2MBS::WS2MBS(const wchar_t *wstr)
{
    size_t len = wcslen(wstr);
    _mbstr = new char[len + 1];
    wcstombs(_mbstr, wstr, len);
    _mbstr[len] = '\0';
}

MBS2WS::MBS2WS(const char *str)
{
    size_t len = strlen(str);
    _wstr = new wchar_t[len + 1];
    ::mbstowcs(_wstr, str, len);
    _wstr[len] = L'\0';
}

} // gls namespace 

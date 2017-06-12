#ifndef __WINGUI_TYPES_H__
#define __WINGUI_TYPES_H__

#include <string>
#include <assert.h>
#include <windows.h>

#if defined(UNICODE) || defined(_UNICODE)
    typedef std::wstring wingui_tstring;
#else
    typedef std::string wingui_tstring;
#endif

#if defined (DEBUG) || defined(_DEBUG)
#   define WINGUI_ASSERT(M) assert(M)
#else
#   define WINGUI_ASSERT(M) M
#endif

#endif // !__WINGUI_TYPES_H__

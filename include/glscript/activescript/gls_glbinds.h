//
// gls_glbinds.h  glscript OpenGL binds. Defines macros for binding OpenGL functions.
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
#ifndef __GLSCRIPT_GLBINDS_H__
#define __GLSCRIPT_GLBINDS_H__

/* Set of macros for implementing gl function calls */

#define GLS_IMP_GL_PROC0(_fn) \
HRESULT STDMETHODCALLTYPE _fn() { \
    ::_fn(); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC1(_fn,_pt,_pn) \
HRESULT STDMETHODCALLTYPE _fn(_pt _pn) { \
    ::_fn(_pn); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC1_PTR(_fn,_pt,_pn) \
HRESULT STDMETHODCALLTYPE _fn(_pt _pn) { \
    ::_fn(*(reinterpret_cast<GLScript_Array *>(_pn))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC2(_fn,_pt1,_pn1,_pt2,_pn2) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2) { \
    ::_fn(_pn1,_pn2); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC2_PTR(_fn,_pt1,_pn1,_pt2,_pn2) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2) { \
    ::_fn(_pn1,*(reinterpret_cast<GLScript_Array *>(_pn2))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC3(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3) { \
    ::_fn(_pn1,_pn2,_pn3); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC3_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3) { \
    ::_fn(_pn1,_pn2,*(reinterpret_cast<GLScript_Array *>(_pn3))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC4(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC4_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4) { \
    ::_fn(_pn1,_pn2,_pn3,*(reinterpret_cast<GLScript_Array *>(_pn4))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC5(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC5_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,*(reinterpret_cast<GLScript_Array *>(_pn5))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC6(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC6_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,*(reinterpret_cast<GLScript_Array *>(_pn6))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC7(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6,_pt7,_pn7) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6, _pt7 _pn7) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6,_pn7); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC7_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6,_pt7,_pn7) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6, _pt7 _pn7) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6,*(reinterpret_cast<GLScript_Array *>(_pn7))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC8(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6,_pt7,_pn7,_pt8,_pn8) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6, _pt7 _pn7, _pt8 _pn8) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6,_pn7,_pn8); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC8_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6,_pt7,_pn7,_pt8,_pn8) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6, _pt7 _pn7, _pt8 _pn8) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6,_pn7,*(reinterpret_cast<GLScript_Array *>(_pn8))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC9_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6,_pt7,_pn7,_pt8,_pn8,_pt9,_pn9) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6, _pt7 _pn7, _pt8 _pn8, _pt9 _pn9) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6,_pn7,_pn8,*(reinterpret_cast<GLScript_Array *>(_pn9))); \
    return NOERROR; \
}

#define GLS_IMP_GL_PROC10_PTR(_fn,_pt1,_pn1,_pt2,_pn2,_pt3,_pn3,_pt4,_pn4,_pt5,_pn5,_pt6,_pn6,_pt7,_pn7,_pt8,_pn8,_pt9,_pn9,_pt10,_pn10) \
HRESULT STDMETHODCALLTYPE _fn(_pt1 _pn1, _pt2 _pn2, _pt3 _pn3, _pt4 _pn4, _pt5 _pn5, _pt6 _pn6, _pt7 _pn7, _pt8 _pn8, _pt9 _pn9, _pt10 _pn10) { \
    ::_fn(_pn1,_pn2,_pn3,_pn4,_pn5,_pn6,_pn7,_pn8,_pn9,*(reinterpret_cast<GLScript_Array *>(_pn10))); \
    return NOERROR; \
}

#endif /* __GLSCRIPT_GLBINDS_H__ */

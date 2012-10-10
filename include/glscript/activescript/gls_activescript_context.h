//
// gls_activescript_context.h  glscript OpenGL Context class. Provides
// access to OpenGL APIs.
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
#ifndef __GLSCRIPT_ACTIVESCRIPTING_CONTEXT_H__
#define __GLSCRIPT_ACTIVESCRIPTING_CONTEXT_H__

// prevent direct inclusion of this header file.
#ifndef __GLSCRIPT_ACTIVESCRIPT_HOST_H__
#error "Do not include this header directly. Include gls_activescript_host.h instead."
#endif

// macros for implementing OpenGL function call binds
#include "gls_glbinds.h"

// externs...
extern const IID *GLScript_Context_IIDs[];

// GLScript_Context class...
class GLScript_Context : public AutomationContainedComObject<
									_GLScript_Context,
									GLScript_Context_IIDs,
									&IID__GLScript_Context> 
{
public:
	// _GLScript_GLContext functions...
	HRESULT STDMETHODCALLTYPE flush ();

	GLS_IMP_GL_PROC2(glAccum, unsigned int, op, float, value);
	GLS_IMP_GL_PROC2(glAlphaFunc, unsigned int, func, float, ref);
	HRESULT STDMETHODCALLTYPE glAreTexturesResident (int n, _GLScript_Array *textures, _GLScript_Array *residences, unsigned char *pRet) {
		*pRet = ::glAreTexturesResident(n, *(reinterpret_cast<GLScript_Array *>(textures)),*(reinterpret_cast<GLScript_Array *>(residences)));
		return NOERROR;
	}
	GLS_IMP_GL_PROC1(glArrayElement, int, i);
	GLS_IMP_GL_PROC1(glBegin, unsigned int, mode);
	GLS_IMP_GL_PROC2(glBindTexture, unsigned int, target, unsigned int, texture);
	GLS_IMP_GL_PROC7_PTR(glBitmap,int, width, int, height, float, xorig, float, yorig, float, xmove, float, ymove, _GLScript_Array *,bitmap);
	GLS_IMP_GL_PROC2(glBlendFunc, unsigned int, sfactor, unsigned int, dfactor);
	GLS_IMP_GL_PROC1(glCallList, unsigned int, list);
	GLS_IMP_GL_PROC3_PTR(glCallLists, int, n, unsigned int, type, _GLScript_Array *, lists);
	GLS_IMP_GL_PROC1(glClear, unsigned int, mask);
	GLS_IMP_GL_PROC4(glClearAccum, float, red, float, green, float, blue, float, alpha);
	GLS_IMP_GL_PROC4(glClearColor, float, red, float, green, float, blue, float, alpha);
	GLS_IMP_GL_PROC1(glClearDepth, double, depth);
	GLS_IMP_GL_PROC1(glClearIndex, float, c);
	GLS_IMP_GL_PROC1(glClearStencil, int, s);
	GLS_IMP_GL_PROC2_PTR(glClipPlane,unsigned int, plane, _GLScript_Array *,equation);
	GLS_IMP_GL_PROC3(glColor3b, signed char, red, signed char, green, signed char, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3bv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3d, double, red, double, green, double, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3dv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3f, float, red, float, green, float, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3fv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3i, int, red, int, green, int, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3iv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3s, short, red, short, green, short, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3sv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3ub, unsigned char, red, unsigned char, green, unsigned char, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3ubv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3ui, unsigned int, red, unsigned int, green, unsigned int, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3uiv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glColor3us, unsigned short, red, unsigned short, green, unsigned short, blue);
	GLS_IMP_GL_PROC1_PTR(glColor3usv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4b, signed char, red, signed char, green, signed char, blue, signed char, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4bv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4d, double, red, double, green, double, blue, double, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4dv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4f, float, red, float, green, float, blue, float, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4fv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4i, int, red, int, green, int, blue, int, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4iv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4s, short, red, short, green, short, blue, short, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4sv,_GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4ub, unsigned char, red, unsigned char, green, unsigned char, blue, unsigned char, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4ubv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4ui, unsigned int, red, unsigned int, green, unsigned int, blue, unsigned int, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4uiv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColor4us, unsigned short, red, unsigned short, green, unsigned short, blue, unsigned short, alpha);
	GLS_IMP_GL_PROC1_PTR(glColor4usv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glColorMask, unsigned char, red, unsigned char, green, unsigned char, blue, unsigned char, alpha);
	GLS_IMP_GL_PROC2(glColorMaterial, unsigned int, face, unsigned int, mode);
	GLS_IMP_GL_PROC4_PTR(glColorPointer, int, size, unsigned int, type, int, stride, _GLScript_Array *,pointer);
	GLS_IMP_GL_PROC5(glCopyPixels, int, x, int, y, int, width, int, height, unsigned int, type);
	GLS_IMP_GL_PROC7(glCopyTexImage1D, unsigned int, target, int, level, unsigned int, internalFormat, int, x, int, y, int, width, int, border);
	GLS_IMP_GL_PROC8(glCopyTexImage2D, unsigned int, target, int, level, unsigned int, internalFormat, int, x, int, y, int, width, int, height, int, border);
	GLS_IMP_GL_PROC6(glCopyTexSubImage1D, unsigned int, target, int, level, int, xoffset, int, x, int, y, int, width);
	GLS_IMP_GL_PROC8(glCopyTexSubImage2D, unsigned int, target, int, level, int, xoffset, int, yoffset, int, x, int, y, int, width, int, height);
	GLS_IMP_GL_PROC1(glCullFace, unsigned int, mode);
	GLS_IMP_GL_PROC2(glDeleteLists, unsigned int, list, int, range);
	GLS_IMP_GL_PROC2_PTR(glDeleteTextures, int, n, _GLScript_Array *,textures);
	GLS_IMP_GL_PROC1(glDepthFunc, unsigned int, func);
	GLS_IMP_GL_PROC1(glDepthMask, unsigned char, flag);
	GLS_IMP_GL_PROC2(glDepthRange, double, zNear, double, zFar);
	GLS_IMP_GL_PROC1(glDisable, unsigned int, cap);
	GLS_IMP_GL_PROC1(glDisableClientState, unsigned int, arrayt);
	GLS_IMP_GL_PROC3(glDrawArrays, unsigned int, mode, int, first, int, count);
	GLS_IMP_GL_PROC1(glDrawBuffer, unsigned int, mode);
	GLS_IMP_GL_PROC4_PTR(glDrawElements, unsigned int, mode, int, count, unsigned int, type, _GLScript_Array *,indices);
	GLS_IMP_GL_PROC5_PTR(glDrawPixels, int, width, int, height, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC1(glEdgeFlag, unsigned char, flag);
	GLS_IMP_GL_PROC2_PTR(glEdgeFlagPointer, int, stride, _GLScript_Array *,pointer);
	GLS_IMP_GL_PROC1_PTR(glEdgeFlagv, _GLScript_Array *,flag);
	GLS_IMP_GL_PROC1(glEnable, unsigned int, cap);
	GLS_IMP_GL_PROC1(glEnableClientState, unsigned int, arrayt);
	GLS_IMP_GL_PROC0(glEnd);
	GLS_IMP_GL_PROC0(glEndList);
	GLS_IMP_GL_PROC1(glEvalCoord1d, double, u);
	GLS_IMP_GL_PROC1_PTR(glEvalCoord1dv, _GLScript_Array *,u);
	GLS_IMP_GL_PROC1(glEvalCoord1f, float, u);
	GLS_IMP_GL_PROC1_PTR(glEvalCoord1fv, _GLScript_Array *,u);
	GLS_IMP_GL_PROC2(glEvalCoord2d, double, u, double, v);
	GLS_IMP_GL_PROC1_PTR(glEvalCoord2dv, _GLScript_Array *,u);
	GLS_IMP_GL_PROC2(glEvalCoord2f, float, u, float, v);
	GLS_IMP_GL_PROC1_PTR(glEvalCoord2fv, _GLScript_Array *,u);
	GLS_IMP_GL_PROC3(glEvalMesh1, unsigned int, mode, int, i1, int, i2);
	GLS_IMP_GL_PROC5(glEvalMesh2, unsigned int, mode, int, i1, int, i2, int, j1, int, j2);
	GLS_IMP_GL_PROC1(glEvalPoint1, int, i);
	GLS_IMP_GL_PROC2(glEvalPoint2, int, i, int, j);
	GLS_IMP_GL_PROC3_PTR(glFeedbackBuffer, int, size, unsigned int, type, _GLScript_Array *,buffer);
	GLS_IMP_GL_PROC0(glFinish);
	GLS_IMP_GL_PROC0(glFlush);
	GLS_IMP_GL_PROC2(glFogf, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC2_PTR(glFogfv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2(glFogi, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC2_PTR(glFogiv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC1(glFrontFace, unsigned int, mode);
	GLS_IMP_GL_PROC6(glFrustum, double, left, double, right, double, bottom, double, top, double, zNear, double, zFar);
	HRESULT STDMETHODCALLTYPE glGenLists (int range, unsigned int * retVal) {
		*retVal = ::glGenLists(range);
		return NOERROR;
	}
	GLS_IMP_GL_PROC2_PTR(glGenTextures, int, n, _GLScript_Array *,textures);
	GLS_IMP_GL_PROC2_PTR(glGetBooleanv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2_PTR(glGetClipPlane, unsigned int, plane, _GLScript_Array *,equation);
	GLS_IMP_GL_PROC2_PTR(glGetDoublev, unsigned int, pname, _GLScript_Array *,params);
	HRESULT STDMETHODCALLTYPE glGetError (unsigned int *retVal) {
		*retVal = ::glGetError();
		return NOERROR;
	}
	GLS_IMP_GL_PROC2_PTR(glGetFloatv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2_PTR(glGetIntegerv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetLightfv, unsigned int, light, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetLightiv, unsigned int, light, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetMapdv, unsigned int, target, unsigned int, query, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3_PTR(glGetMapfv, unsigned int, target, unsigned int, query, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3_PTR(glGetMapiv, unsigned int, target, unsigned int, query, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3_PTR(glGetMaterialfv, unsigned int, face, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetMaterialiv, unsigned int, face, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2_PTR(glGetPixelMapfv, unsigned int, map, _GLScript_Array *,values);
	GLS_IMP_GL_PROC2_PTR(glGetPixelMapuiv, unsigned int, map, _GLScript_Array *,values);
	GLS_IMP_GL_PROC2_PTR(glGetPixelMapusv, unsigned int, map, _GLScript_Array *,values);
	HRESULT STDMETHODCALLTYPE glGetPointerv (unsigned int pname, void* *params)
	{
		// #TODO: Implementation
		return NOERROR;
	}
	GLS_IMP_GL_PROC1_PTR(glGetPolygonStipple, _GLScript_Array *,mask);
	HRESULT STDMETHODCALLTYPE glGetString(unsigned int name, BSTR *retVal)
	{
		const GLubyte *str = ::glGetString (name);
		if (str == NULL)
			return E_FAIL;

		wchar_t wstrbuff[1024];
		::mbtowc (wstrbuff, (const char*)str, ::strlen((const char*)str));

		*retVal = ::SysAllocString (wstrbuff);
		if (*retVal == NULL)
			return E_OUTOFMEMORY;

		return NOERROR;
	}
	GLS_IMP_GL_PROC3_PTR(glGetTexEnvfv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetTexEnviv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetTexGendv, unsigned int, coord, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetTexGenfv, unsigned int, coord, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetTexGeniv, unsigned int, coord, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC5_PTR(glGetTexImage, unsigned int, target, int, level, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC4_PTR(glGetTexLevelParameterfv, unsigned int, target, int, level, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC4_PTR(glGetTexLevelParameteriv, unsigned int, target, int, level, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetTexParameterfv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3_PTR(glGetTexParameteriv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2(glHint, unsigned int, target, unsigned int, mode);
	GLS_IMP_GL_PROC1(glIndexMask, unsigned int, mask);
	GLS_IMP_GL_PROC3_PTR(glIndexPointer, unsigned int, type, int, stride, _GLScript_Array *,pointer);
	GLS_IMP_GL_PROC1(glIndexd, double, c);
	GLS_IMP_GL_PROC1_PTR(glIndexdv, _GLScript_Array *,c);
	GLS_IMP_GL_PROC1(glIndexf, float, c);
	GLS_IMP_GL_PROC1_PTR(glIndexfv, _GLScript_Array *,c);
	GLS_IMP_GL_PROC1(glIndexi, int, c);
	GLS_IMP_GL_PROC1_PTR(glIndexiv, _GLScript_Array *,c);
	GLS_IMP_GL_PROC1(glIndexs, short, c);
	GLS_IMP_GL_PROC1_PTR(glIndexsv, _GLScript_Array *,c);
	GLS_IMP_GL_PROC1(glIndexub, unsigned char, c);
	GLS_IMP_GL_PROC1_PTR(glIndexubv, _GLScript_Array *,c);
	GLS_IMP_GL_PROC0(glInitNames);
	GLS_IMP_GL_PROC3_PTR(glInterleavedArrays, unsigned int, format, int, stride, _GLScript_Array *,pointer);
	HRESULT STDMETHODCALLTYPE glIsEnabled (unsigned int cap, unsigned char *retVal) {
		*retVal = ::glIsEnabled(cap);
		return NOERROR;
	}
	HRESULT STDMETHODCALLTYPE glIsList(unsigned int list, unsigned char * retVal) {
		*retVal = ::glIsList(list);
		return NOERROR;
	}
	HRESULT STDMETHODCALLTYPE glIsTexture(unsigned int texture, unsigned char * retVal) {
		*retVal = ::glIsTexture(texture);
		return NOERROR;
	}
	GLS_IMP_GL_PROC2(glLightModelf, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC2_PTR(glLightModelfv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2(glLightModeli, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC2_PTR(glLightModeliv, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glLightf, unsigned int, light, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC3_PTR(glLightfv, unsigned int, light, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glLighti, unsigned int, light, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC3_PTR(glLightiv, unsigned int, light, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC2(glLineStipple, int, factor, unsigned short, pattern);
	GLS_IMP_GL_PROC1(glLineWidth, float, width);
	GLS_IMP_GL_PROC1(glListBase, unsigned int, base);
	GLS_IMP_GL_PROC0(glLoadIdentity);
	GLS_IMP_GL_PROC1_PTR(glLoadMatrixd, _GLScript_Array *,m);
	GLS_IMP_GL_PROC1_PTR(glLoadMatrixf, _GLScript_Array *,m);
	GLS_IMP_GL_PROC1(glLoadName, unsigned int, name);
	GLS_IMP_GL_PROC1(glLogicOp, unsigned int, opcode);
	GLS_IMP_GL_PROC6_PTR(glMap1d, unsigned int, target, double, u1, double, u2, int, stride, int, order, _GLScript_Array *,points);
	GLS_IMP_GL_PROC6_PTR(glMap1f, unsigned int, target, float, u1, float, u2, int, stride, int, order, _GLScript_Array *,points);
	GLS_IMP_GL_PROC10_PTR(glMap2d, unsigned int, target, double, u1, double, u2, int, ustride, int, uorder, double, v1, double, v2, int, vstride, int, vorder, _GLScript_Array *,points);
	GLS_IMP_GL_PROC10_PTR(glMap2f, unsigned int, target, float, u1, float, u2, int, ustride, int, uorder, float, v1, float, v2, int, vstride, int, vorder, _GLScript_Array *,points);
	GLS_IMP_GL_PROC3(glMapGrid1d, int, un, double, u1, double, u2);
	GLS_IMP_GL_PROC3(glMapGrid1f, int, un, float, u1, float, u2);
	GLS_IMP_GL_PROC6(glMapGrid2d, int, un, double, u1, double, u2, int, vn, double, v1, double, v2);
	GLS_IMP_GL_PROC6(glMapGrid2f, int, un, float, u1, float, u2, int, vn, float, v1, float, v2);
	GLS_IMP_GL_PROC3(glMaterialf, unsigned int, face, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC3_PTR(glMaterialfv, unsigned int, face, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glMateriali, unsigned int, face, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC3_PTR(glMaterialiv, unsigned int, face, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC1(glMatrixMode, unsigned int, mode);
	GLS_IMP_GL_PROC1_PTR(glMultMatrixd, _GLScript_Array *,m);
	GLS_IMP_GL_PROC1_PTR(glMultMatrixf, _GLScript_Array *,m);
	GLS_IMP_GL_PROC2(glNewList, unsigned int, list, unsigned int, mode);
	GLS_IMP_GL_PROC3(glNormal3b, signed char, nx, signed char, ny, signed char, nz);
	GLS_IMP_GL_PROC1_PTR(glNormal3bv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glNormal3d, double, nx, double, ny, double, nz);
	GLS_IMP_GL_PROC1_PTR(glNormal3dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glNormal3f, float, nx, float, ny, float, nz);
	GLS_IMP_GL_PROC1_PTR(glNormal3fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glNormal3i, int, nx, int, ny, int, nz);
	GLS_IMP_GL_PROC1_PTR(glNormal3iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glNormal3s, short, nx, short, ny, short, nz);
	GLS_IMP_GL_PROC1_PTR(glNormal3sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3_PTR(glNormalPointer, unsigned int, type, int, stride, _GLScript_Array *,pointer);
	GLS_IMP_GL_PROC6(glOrtho, double, left, double, right, double, bottom, double, top, double, zNear, double, zFar);
	GLS_IMP_GL_PROC1(glPassThrough, float, token);
	GLS_IMP_GL_PROC3_PTR(glPixelMapfv, unsigned int, map, int, mapsize, _GLScript_Array *,values);
	GLS_IMP_GL_PROC3_PTR(glPixelMapuiv, unsigned int, map, int, mapsize, _GLScript_Array *,values);
	GLS_IMP_GL_PROC3_PTR(glPixelMapusv, unsigned int, map, int, mapsize, _GLScript_Array *,values);
	GLS_IMP_GL_PROC2(glPixelStoref, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC2(glPixelStorei, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC2(glPixelTransferf, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC2(glPixelTransferi, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC2(glPixelZoom, float, xfactor, float, yfactor);
	GLS_IMP_GL_PROC1(glPointSize, float, size);
	GLS_IMP_GL_PROC2(glPolygonMode, unsigned int, face, unsigned int, mode);
	GLS_IMP_GL_PROC2(glPolygonOffset, float, factor, float, units);
	GLS_IMP_GL_PROC1_PTR(glPolygonStipple, _GLScript_Array *,mask);
	GLS_IMP_GL_PROC0(glPopAttrib);
	GLS_IMP_GL_PROC0(glPopClientAttrib);
	GLS_IMP_GL_PROC0(glPopMatrix);
	GLS_IMP_GL_PROC0(glPopName);
	HRESULT STDMETHODCALLTYPE glPrioritizeTextures (int n, _GLScript_Array *textures, _GLScript_Array *priorities) {
		::glPrioritizeTextures (n, *(reinterpret_cast<GLScript_Array *>(textures)), *(reinterpret_cast<GLScript_Array *>(priorities)));
		return NOERROR;
	}
	GLS_IMP_GL_PROC1(glPushAttrib, unsigned int, mask);
	GLS_IMP_GL_PROC1(glPushClientAttrib, unsigned int, mask);
	GLS_IMP_GL_PROC0(glPushMatrix);
	GLS_IMP_GL_PROC1(glPushName, unsigned int, name);
	GLS_IMP_GL_PROC2(glRasterPos2d, double, x, double, y);
	GLS_IMP_GL_PROC1_PTR(glRasterPos2dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glRasterPos2f, float, x, float, y);
	GLS_IMP_GL_PROC1_PTR(glRasterPos2fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glRasterPos2i, int, x, int, y);
	GLS_IMP_GL_PROC1_PTR(glRasterPos2iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glRasterPos2s, short, x, short, y);
	GLS_IMP_GL_PROC1_PTR(glRasterPos2sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glRasterPos3d, double, x, double, y, double, z);
	GLS_IMP_GL_PROC1_PTR(glRasterPos3dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glRasterPos3f, float, x, float, y, float, z);
	GLS_IMP_GL_PROC1_PTR(glRasterPos3fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glRasterPos3i, int, x, int, y, int, z);
	GLS_IMP_GL_PROC1_PTR(glRasterPos3iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glRasterPos3s, short, x, short, y, short, z);
	GLS_IMP_GL_PROC1_PTR(glRasterPos3sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glRasterPos4d, double, x, double, y, double, z, double, w);
	GLS_IMP_GL_PROC1_PTR(glRasterPos4dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glRasterPos4f, float, x, float, y, float, z, float, w);
	GLS_IMP_GL_PROC1_PTR(glRasterPos4fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glRasterPos4i, int, x, int, y, int, z, int, w);
	GLS_IMP_GL_PROC1_PTR(glRasterPos4iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glRasterPos4s, short, x, short, y, short, z, short, w);
	GLS_IMP_GL_PROC1_PTR(glRasterPos4sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC1(glReadBuffer, unsigned int, mode);
	GLS_IMP_GL_PROC7_PTR(glReadPixels, int, x, int, y, int, width, int, height, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC4(glRectd, double, x1, double, y1, double, x2, double, y2);
	HRESULT STDMETHODCALLTYPE glRectdv (_GLScript_Array *v1, _GLScript_Array *v2)  {
		::glRectdv (*(reinterpret_cast<GLScript_Array *>(v1)), *(reinterpret_cast<GLScript_Array *>(v2)));
		return NOERROR;
	}
	GLS_IMP_GL_PROC4(glRectf, float, x1, float, y1, float, x2, float, y2);
	HRESULT STDMETHODCALLTYPE glRectfv (_GLScript_Array *v1, _GLScript_Array *v2) {
		::glRectfv (*(reinterpret_cast<GLScript_Array *>(v1)), *(reinterpret_cast<GLScript_Array *>(v2)));
		return NOERROR;
	}
	GLS_IMP_GL_PROC4(glRecti, int, x1, int, y1, int, x2, int, y2);
	HRESULT STDMETHODCALLTYPE glRectiv(_GLScript_Array *v1, _GLScript_Array *v2) {
		::glRectiv (*(reinterpret_cast<GLScript_Array *>(v1)), *(reinterpret_cast<GLScript_Array *>(v2)));
		return NOERROR;
	}
	GLS_IMP_GL_PROC4(glRects, short, x1, short, y1, short, x2, short, y2);
	HRESULT STDMETHODCALLTYPE glRectsv(_GLScript_Array *v1, _GLScript_Array *v2) {
		::glRectsv (*(reinterpret_cast<GLScript_Array *>(v1)), *(reinterpret_cast<GLScript_Array *>(v2)));
		return NOERROR;
	}
	HRESULT STDMETHODCALLTYPE glRenderMode(unsigned int mode, int *retVal) {
		*retVal = ::glRenderMode(mode);
		return NOERROR;
	}
	GLS_IMP_GL_PROC4(glRotated, double, angle, double, x, double, y, double, z);
	GLS_IMP_GL_PROC4(glRotatef, float, angle, float, x, float, y, float, z);
	GLS_IMP_GL_PROC3(glScaled, double, x, double, y, double, z);
	GLS_IMP_GL_PROC3(glScalef, float, x, float, y, float, z);
	GLS_IMP_GL_PROC4(glScissor, int, x, int, y, int, width, int, height);
	GLS_IMP_GL_PROC2_PTR(glSelectBuffer, int, size, _GLScript_Array *,buffer);
	GLS_IMP_GL_PROC1(glShadeModel, unsigned int, mode);
	GLS_IMP_GL_PROC3(glStencilFunc, unsigned int, func, int, ref, unsigned int, mask);
	GLS_IMP_GL_PROC1(glStencilMask, unsigned int, mask);
	GLS_IMP_GL_PROC3(glStencilOp, unsigned int, fail, unsigned int, zfail, unsigned int, zpass);
	GLS_IMP_GL_PROC1(glTexCoord1d, double, s);
	GLS_IMP_GL_PROC1_PTR(glTexCoord1dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC1(glTexCoord1f, float, s);
	GLS_IMP_GL_PROC1_PTR(glTexCoord1fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC1(glTexCoord1i, int, s);
	GLS_IMP_GL_PROC1_PTR(glTexCoord1iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC1(glTexCoord1s, short, s);
	GLS_IMP_GL_PROC1_PTR(glTexCoord1sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glTexCoord2d, double, s, double, t);
	GLS_IMP_GL_PROC1_PTR(glTexCoord2dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glTexCoord2f, float, s, float, t);
	GLS_IMP_GL_PROC1_PTR(glTexCoord2fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glTexCoord2i, int, s, int, t);
	GLS_IMP_GL_PROC1_PTR(glTexCoord2iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glTexCoord2s, short, s, short, t);
	GLS_IMP_GL_PROC1_PTR(glTexCoord2sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glTexCoord3d, double, s, double, t, double, r);
	GLS_IMP_GL_PROC1_PTR(glTexCoord3dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glTexCoord3f, float, s, float, t, float, r);
	GLS_IMP_GL_PROC1_PTR(glTexCoord3fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glTexCoord3i, int, s, int, t, int, r);
	GLS_IMP_GL_PROC1_PTR(glTexCoord3iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glTexCoord3s, short, s, short, t, short, r);
	GLS_IMP_GL_PROC1_PTR(glTexCoord3sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glTexCoord4d, double, s, double, t, double, r, double, q);
	GLS_IMP_GL_PROC1_PTR(glTexCoord4dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glTexCoord4f, float, s, float, t, float, r, float, q);
	GLS_IMP_GL_PROC1_PTR(glTexCoord4fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glTexCoord4i, int, s, int, t, int, r, int, q);
	GLS_IMP_GL_PROC1_PTR(glTexCoord4iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glTexCoord4s, short, s, short, t, short, r, short, q);
	GLS_IMP_GL_PROC1_PTR(glTexCoord4sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4_PTR(glTexCoordPointer, int, size, unsigned int, type, int, stride, _GLScript_Array *,pointer);
	GLS_IMP_GL_PROC3(glTexEnvf, unsigned int, target, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC3_PTR(glTexEnvfv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glTexEnvi, unsigned int, target, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC3_PTR(glTexEnviv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glTexGend, unsigned int, coord, unsigned int, pname, double, param);
	GLS_IMP_GL_PROC3_PTR(glTexGendv, unsigned int, coord, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glTexGenf, unsigned int, coord, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC3_PTR(glTexGenfv, unsigned int, coord, unsigned int, pname, _GLScript_Array*,params);
	GLS_IMP_GL_PROC3(glTexGeni, unsigned int, coord, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC3_PTR(glTexGeniv, unsigned int, coord, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC8_PTR(glTexImage1D, unsigned int, target, int, level, int, internalformat, int, width, int, border, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC9_PTR(glTexImage2D, unsigned int, target, int, level, int, internalformat, int, width, int, height, int, border, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC3(glTexParameterf, unsigned int, target, unsigned int, pname, float, param);
	GLS_IMP_GL_PROC3_PTR(glTexParameterfv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC3(glTexParameteri, unsigned int, target, unsigned int, pname, int, param);
	GLS_IMP_GL_PROC3_PTR(glTexParameteriv, unsigned int, target, unsigned int, pname, _GLScript_Array *,params);
	GLS_IMP_GL_PROC7_PTR(glTexSubImage1D, unsigned int, target, int, level, int, xoffset, int, width, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC9_PTR(glTexSubImage2D, unsigned int, target, int, level, int, xoffset, int, yoffset, int, width, int, height, unsigned int, format, unsigned int, type, _GLScript_Array *,pixels);
	GLS_IMP_GL_PROC3(glTranslated, double, x, double, y, double, z);
	GLS_IMP_GL_PROC3(glTranslatef, float, x, float, y, float, z);
	GLS_IMP_GL_PROC2(glVertex2d, double, x, double, y);
	GLS_IMP_GL_PROC1_PTR(glVertex2dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glVertex2f, float, x, float, y);
	GLS_IMP_GL_PROC1_PTR(glVertex2fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glVertex2i, int, x, int, y);
	GLS_IMP_GL_PROC1_PTR(glVertex2iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC2(glVertex2s, short, x, short, y);
	GLS_IMP_GL_PROC1_PTR(glVertex2sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glVertex3d, double, x, double, y, double, z);
	GLS_IMP_GL_PROC1_PTR(glVertex3dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glVertex3f, float, x, float, y, float, z);
	GLS_IMP_GL_PROC1_PTR(glVertex3fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glVertex3i, int, x, int, y, int, z);
	GLS_IMP_GL_PROC1_PTR(glVertex3iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC3(glVertex3s, short, x, short, y, short, z);
	GLS_IMP_GL_PROC1_PTR(glVertex3sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glVertex4d, double, x, double, y, double, z, double, w);
	GLS_IMP_GL_PROC1_PTR(glVertex4dv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glVertex4f, float, x, float, y, float, z, float, w);
	GLS_IMP_GL_PROC1_PTR(glVertex4fv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glVertex4i, int, x, int, y, int, z, int, w);
	GLS_IMP_GL_PROC1_PTR(glVertex4iv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4(glVertex4s, short, x, short, y, short, z, short, w);
	GLS_IMP_GL_PROC1_PTR(glVertex4sv, _GLScript_Array *,v);
	GLS_IMP_GL_PROC4_PTR(glVertexPointer, int, size, unsigned int, type, int, stride, _GLScript_Array *,pointer);
	GLS_IMP_GL_PROC4(glViewport, int, x, int, y, int, width, int, height);

public:
	/* ctor */
	GLScript_Context (IUnknown *pParent) 
		: AutomationContainedComObject (pParent) 
	{ }

	/* dtor */
	virtual ~GLScript_Context () {
	}
};

#endif /* __GLSCRIPT_ACTIVESCRIPTING_CONTEXT_H__ */

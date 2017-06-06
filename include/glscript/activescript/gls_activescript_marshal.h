//
// gls_activescript_marshal.h  glscript COM VARIANT access routines.
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
#ifndef __GLSCRIPT_SCRIPTING_MARHSAL_H
 #define __GLSCRIPT_SCRIPTING_MARHSAL_H

#ifdef __cplusplus
extern "C" {
#endif

// macros for implementing gls_comvariant_get_* functions...

#define GLS_COMVARIANT_FUNC_DECL(_TN,_RT) \
bool gls_comvariant_get_##_TN##_value(VARIANT *,_RT *);

#define GLS_COMVARIANT_FUNC_BEGIN(_TN) \
bool gls_comvariant_get_##_TN##_value(VARIANT *pVariant, _CPPTYPE *pValue) { \
    switch (pVariant->vt) {

#define GLS_COMVARIANT_FUNC_TYPECHECK(_VT,_VF) \
    case _VT: \
        *pValue = (_CPPTYPE)pVariant->_VF; \
        break;

#define GLS_COMVARIANT_FUNC_END() \
    default: \
        return false; \
    } /*end switch*/ \
    return true; \
}

/*
bool gls_comvariant_get_char_value (VARIANT *pVariant, signed char *pValue);
bool gls_comvariant_get_byte_value (VARIANT *pVariant, unsigned char *pValue);
bool gls_comvariant_get_short_value (VARIANT *pVariant, short *pValue);
bool gls_comvariant_get_ushort_value (VARIANT *pVariant, unsigned short *pValue);
bool gls_comvariant_get_int_value (VARIANT *pVariant, int *pValue);
bool gls_comvariant_get_uint_value (VARIANT *pVariant, unsigned int *pValue);
bool gls_comvariant_get_long_value (VARIANT *pVariant, long *pValue);
bool gls_comvariant_get_ulong_value (VARIANT *pVariant, unsigned long *pValue);
bool gls_comvariant_get_float_value (VARIANT *pVariant, float *pValue);
bool gls_comvariant_get_double_value (VARIANT *pVariant, double *pValue);
*/
GLS_COMVARIANT_FUNC_DECL(char,signed char);
GLS_COMVARIANT_FUNC_DECL(byte,unsigned char);
GLS_COMVARIANT_FUNC_DECL(short,short);
GLS_COMVARIANT_FUNC_DECL(ushort,unsigned short);
GLS_COMVARIANT_FUNC_DECL(int,int);
GLS_COMVARIANT_FUNC_DECL(uint,unsigned int);
GLS_COMVARIANT_FUNC_DECL(long,long);
GLS_COMVARIANT_FUNC_DECL(ulong,unsigned long);
GLS_COMVARIANT_FUNC_DECL(float,float);
GLS_COMVARIANT_FUNC_DECL(double,double);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __GLSCRIPT_SCRIPTING_MARHSAL_H */

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
#include <tchar.h>
#include "gls_obj_model.h"

GLS_OBJ_Model::GLS_OBJ_Model () {
    m_obj_parser = new objparser::ParserOBJ ();
    m_width = m_height = m_depth = 0.0f;
    m_model_initialized = FALSE;
}

GLS_OBJ_Model::~GLS_OBJ_Model () {
    delete m_obj_parser;
}

HRESULT STDMETHODCALLTYPE GLS_OBJ_Model::get_boundingBox (_BoundingBox **ppbb) {
    *ppbb = NULL;

    _BoundingBox *pBB;
    HRESULT hr = BoundingBox_Factory.CreateInstance (NULL, IID__BoundingBox, (LPVOID *)&pBB);
    if (FAILED(hr)) {
        return hr;
    }

    (reinterpret_cast<BoundingBox *>(pBB))->_SetBoundingBox (m_width, m_height, m_depth);

    *ppbb = pBB;
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLS_OBJ_Model::render () {
    if (m_model_initialized) {
        const char *vertex_data = reinterpret_cast<const char *>
                                    (m_obj_parser->GetVertexData());
        const GLushort *indices = m_obj_parser->GetIndices();

        // setup vertex array...
        ::glEnableClientState (GL_VERTEX_ARRAY);
        ::glVertexPointer (3, GL_FLOAT, sizeof(objparser::VERTEX_DATA), 
                            vertex_data + VERTEX_DATA_VERTICES_OFFSET);

        // setup normals array...
        if (m_obj_parser->GetNormalsCount() > 0) {
            ::glEnableClientState (GL_NORMAL_ARRAY);
            ::glNormalPointer (GL_FLOAT, sizeof(objparser::VERTEX_DATA), 
                                vertex_data + VERTEX_DATA_NORMALS_OFFSET);
        }

        // render the model
        ::glDrawElements (GL_TRIANGLES, m_obj_parser->GetElementsCount(), GL_UNSIGNED_SHORT, 
                            indices);

        // disable arrays...
        ::glDisableClientState (GL_VERTEX_ARRAY);
        ::glDisableClientState (GL_NORMAL_ARRAY);
    }

    return NOERROR;
}

// internal public methods...

BOOL GLS_OBJ_Model::_InitModel (const char *lpsz_model_path) {
    FILE *fp = fopen (lpsz_model_path, "rb");
    if (fp == NULL) {
        return FALSE;
    }

    int err = m_obj_parser->Parse (fp);

    fclose (fp);

    if (err == 0) {
        CalcBoundingBox ();
        m_model_initialized = TRUE;
    }

    return m_model_initialized;
}

void GLS_OBJ_Model::CalcBoundingBox () {
    GLfloat min_x, min_y, min_z, max_x, max_y, max_z;
    min_x = min_y = min_z = max_x = max_y = max_z = 0.0f;

    size_t length = m_obj_parser->GetVerticesCount ();
    const objparser::VERTEX_DATA *vertex_data = m_obj_parser->GetVertexData ();

    if (length > 0) {
        min_x = max_x = vertex_data[0].x;
        min_y = max_y = vertex_data[0].y;
        min_z = max_z = vertex_data[0].z;
    }

    // find min max
    for (size_t i = 1; i < length; i++) {
        if (vertex_data[i].x < min_x) {
            min_x = vertex_data[i].x;
        } else if (vertex_data[i].x > max_x) {
            max_x = vertex_data[i].x;
        }

        if (vertex_data[i].y < min_y) {
            min_y = vertex_data[i].y;
        } else if (vertex_data[i].y > max_y) {
            max_y = vertex_data[i].y;
        }

        if (vertex_data[i].z < min_z) {
            min_z = vertex_data[i].z;
        } else if (vertex_data[i].z > max_z) {
            max_z = vertex_data[i].z;
        }
    }

    // find BB
    m_width = max_x - min_x;
    m_height = max_y - min_y;
    m_depth = max_z - min_z;
}

/* externs */
const IID *_BoundingBox_IIDs[] = 
{
    &IID_IUnknown,
    &IID_IDispatch,
    &IID__BoundingBox,
    NULL
};

ClassFactory<BoundingBox> BoundingBox_Factory;

const IID *_GLS_OBJ_Model_IIDs[] = 
{
    &IID_IUnknown,
    &IID_IDispatch,
    &IID__ObjModel,
    NULL
};

ClassFactory<GLS_OBJ_Model> GLS_OBJ_Model_Factory;

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
#include "objparser.h"

using namespace objparser;

// Parser class definition...

Parser::Parser () {
    m_analyzer = new AnalyzerOBJ ();

    m_vertices = NULL;
    m_normals = NULL;
    m_texture_vertices = NULL;
    m_group_indices = NULL;

    m_vertex_data = NULL;
    m_indices = NULL;

    m_error_code = 0;
}

Parser::~Parser () {
    delete m_analyzer;
    Cleanup ();
}

#ifdef _DEBUG
void Parser::Dump () {
    size_t count, i;

    printf ("vertices:\n");
    count = m_analyzer->GetVerticesCount () + m_analyzer->GetExtraVerticesCount ();
    for (i = 0; i < count; ++i) {
        printf ("v %f %f %f\n", 
                m_vertex_data[i].x,
                m_vertex_data[i].y,
                m_vertex_data[i].z);
    }

    printf ("\nnormals:\n");
    count = m_analyzer->GetVerticesCount ();
    for (i = 0; i < count; ++i) {
        printf ("vn %f %f %f\n", 
                m_vertex_data[i].nx,
                m_vertex_data[i].ny,
                m_vertex_data[i].nz);
    }

    printf ("\nfaces:\n");
    count = m_analyzer->GetFacesCount();
    GLushort *index = m_indices;
    for (i = 0; i < count; ++i) {
        printf ("f %u %u %u\n", m_indices[i * 3], m_indices[i * 3 + 1], m_indices[i * 3 + 2]);
    }
    printf ("\n");
}
#endif

bool Parser::AllocMemory () {
     // cleanup first
    Cleanup ();

    // allocate intermediate memory blocks
    m_vertices = new VERTEX [ m_analyzer->GetVerticesCount() + 
                              m_analyzer->GetExtraVerticesCount() ];

    m_normals = new NORMAL_VERTEX [ m_analyzer->GetNormalsCount() ];

    m_texture_vertices = new TEXTURE_VERTEX [ m_analyzer->GetTextureVerticesCount() ];

    m_group_indices = new INDEX [ m_analyzer->GetElementsCount() ];

    // allocate output memory blocks
    m_vertex_data = new VERTEX_DATA [ m_analyzer->GetVerticesCount() +
                                      m_analyzer->GetExtraVerticesCount() ];

    m_indices = new GLushort [ m_analyzer->GetElementsCount() ];

    // check memory allocation failure
    if (!m_vertices || ! m_normals || !m_texture_vertices || 
        !m_indices || !m_vertex_data || ! m_indices) 
    {
        Cleanup ();
        return false;
    }

    memset (m_vertex_data, 0, 
            sizeof(VERTEX_DATA) * (m_analyzer->GetVerticesCount() + 
                                    m_analyzer->GetExtraVerticesCount())
            );
    memset (m_indices, 0, sizeof(GLushort) * m_analyzer->GetElementsCount());

    return true;
}

void Parser::Cleanup () {
    if (m_vertices) {
        delete m_vertices;
        m_vertices = NULL;
    }
    if (m_normals) {
        delete m_normals;
        m_normals = NULL;
    }
    if (m_texture_vertices) {
        delete m_texture_vertices;
        m_texture_vertices = NULL;
    }
    if (m_group_indices) {
        delete m_group_indices;
        m_group_indices = NULL;
    }

    if (m_vertex_data) {
        delete m_vertex_data;
        m_vertex_data = NULL;
    }
    if (m_indices) {
        delete m_indices;
        m_indices = NULL;
    }
}

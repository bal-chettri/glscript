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
#include "math.h"

using namespace objparser;

// ParserOBJ class definition...

int ParserOBJ::Parse (FILE *fp) {
    // constants...
    const int LINE_BUFF_SIZE = 1024;
    
    // vars..
    char buff[LINE_BUFF_SIZE + 1];
    const char *line;
    int err;
    
    // cleanup before parsing a new OBJ file 
    Cleanup ();

    // analyze the OBJ file first
    err = m_analyzer->Analyze (fp);
    if (err != 0) {
        return err;
    }

    m_analyzer->GetIndexHash().Reset ();

    // rewind the file pointer to begin parsing the OBJ file
    rewind (fp);

    // allocate memory blocks
    if ( !AllocMemory() ) {
        return objparserOutOfMemory;
    }
    
    // array indices
    int vertex_index = 0;
    int extra_vertex_index = m_analyzer->GetVerticesCount ();
    int normal_index = 0;
    int texture_index = 0;
    int face_index = 0;

    while (!feof (fp)) {
        // read next line from the file
        line = fgets(buff, LINE_BUFF_SIZE, fp);
        if (!line) {
            break;
        }

        // trim comments and skip the leading white space
        Utils::TrimComment (buff);
        line = Utils::SkipWhite(line);
        if (Utils::IsEndOfLine(line)) {
            continue;
        }

        // parse OBJ commands...

        if (*line == 'v' && *(line + 1) == 'n') {
            line+= 2;
            Utils::ParseVertex (line, m_normals[normal_index]);
            ++normal_index;
        }
        
        else if (*line == 'v' && *(line + 1) == 't') {
            line+= 2;
            Utils::ParseVertex2D (line, m_texture_vertices[texture_index].x, 
                                    m_texture_vertices[texture_index].y);
            ++texture_index;
        }

        else if (*line == 'v') {
            Utils::ParseVertex(++line, m_vertices[vertex_index]);
            ++vertex_index;
        }

        else if (*line == 'f') {
            unsigned face_count;
            ParseFaces (++line, face_count, &m_group_indices[face_index * 3], extra_vertex_index);
            face_index+= face_count;
        }

        else if (*line == 'g') {
            // #TODO
        }       
    }

    // process the OBJ data to create the final output data
    return Process ();
}

int ParserOBJ::ParseFaces (const char *s, unsigned &face_count, INDEX *indices, int &extra_vertex_index) {
    unsigned index_count = 0;
    INDEX *index_ptr = indices; 
    GLshort vi, ti, ni;

    face_count = 0;

    while ( !Utils::IsEndOfLine(s) ) {
        s = Utils::SkipWhite(s);
        if (Utils::IsEndOfLine(s)) {
            break;
        }       

        // split a non-triangular polygon face (with > 3 sides) into a triangular face
        if (index_count >= 3) {
            // const INDEX *base_index_ptr = indices;
            const INDEX *base_index_ptr = index_ptr - 3;

            index_ptr[0].vi = base_index_ptr[0].vi;
            index_ptr[0].ti = base_index_ptr[0].ti;
            index_ptr[0].ni = base_index_ptr[0].ni;

            index_ptr[1].vi = base_index_ptr[2].vi;
            index_ptr[1].ti = base_index_ptr[2].ti;
            index_ptr[1].ni = base_index_ptr[2].ni;

            // base_index_ptr = index_ptr;

            index_ptr+= 2;
        }
        
        // scan the next v/vt/vn group...
        index_ptr->vi = index_ptr->ti = index_ptr->ni = INDEX_MISSING;

        // scan vt
        Utils::ParseInt (&s, vi);

        // check for duplicate vertex index
        if (m_analyzer->GetIndexHash().IsSet (vi)) {
            GLshort new_index = (GLshort)++extra_vertex_index;
            m_vertices[new_index - 1].x = m_vertices[vi - 1].x;
            m_vertices[new_index - 1].y = m_vertices[vi - 1].y;
            m_vertices[new_index - 1].z = m_vertices[vi - 1].z;
            vi = new_index;
        }
        m_analyzer->GetIndexHash().Set (vi);

        index_ptr->vi = vi;
        if (*s == '/') {
            // scan vt
            ++s;
            if (Utils::ParseInt (&s, ti)) {
                index_ptr->ti = ti;
            }
            if (*s == '/') {
                // scan vn
                ++s;                
                if (Utils::ParseInt (&s, ni)) {
                    index_ptr->ni = ni;
                }
            }
        }

        // check for INDEX group delimeter
        if (*s == ' ' || *s == '\t' || 
            *s == '\r' || *s == '\n') {
            ++index_count;
            ++index_ptr;
        }
    } // while

    // calculate the number for faces parsed
    face_count = 1 + (index_count - 3);

    return 0;
}

int ParserOBJ::Process () {
    size_t i, count;
    
    // copy vertices to main vertex data    
    count = m_analyzer->GetVerticesCount () + m_analyzer->GetExtraVerticesCount ();
    for (i = 0 ; i < count; ++i) {
        m_vertex_data[i].x = m_vertices[i].x;
        m_vertex_data[i].y = m_vertices[i].y;
        m_vertex_data[i].z = m_vertices[i].z;
    }

    // copy indices to main index array
    count = m_analyzer->GetElementsCount ();
    for (i = 0; i < count; ++i) {
        m_indices[i] = (GLushort) (m_group_indices[i].vi - 1);
    }

    // calculate default normal vector for each face and assign it to the vertices.
    // It is assumed that each polygon face is convex and the vertices are not shared.
    count = m_analyzer->GetFacesCount ();
    for (i = 0; i < count; i++) {
        const INDEX *index_ptr = &m_group_indices [i * 3];

        // get each vertex of the face
        VERTEX_DATA *V1 = &m_vertex_data [index_ptr[0].vi - 1];
        VERTEX_DATA *V2 = &m_vertex_data [index_ptr[1].vi - 1];
        VERTEX_DATA *V3 = &m_vertex_data [index_ptr[2].vi - 1];

        // calculate the normal vector...
        VERTEX U;
        VERTEX V;
        VERTEX N;

        // Set Vector U to (Triangle.p2 minus Triangle.p1)
        U.x = V2->x - V1->x;
        U.y = V2->y - V1->y;
        U.z = V2->z - V1->z;

        // Set Vector V to (Triangle.p3 minus Triangle.p1)
        V.x = V3->x - V1->x;
        V.y = V3->y - V1->y;
        V.z = V3->z - V1->z;
 
        // Set Normal.x to (multiply U.y by V.z) minus (multiply U.z by V.y)
        N.x = (U.y * V.z) - (U.z * V.y);
        // Set Normal.y to (multiply U.z by V.x) minus (multiply U.x by V.z)
        N.y = (U.z * V.x) - (U.x * V.z);
        // Set Normal.z to (multiply U.x by V.y) minus (multiply U.y by V.x)
        N.z = (U.x * V.y) - (U.y * V.x);

        /*N.x*= -1.0f;
        N.y*= -1.0f;
        N.z*= -1.0f;*/

        // normalize the vector
        float length = sqrt ( (N.x * N.x) + (N.y * N.y) + (N.z * N.z) );
        N.x = N.x / length;
        N.y = N.y / length;
        N.z = N.z / length;

        // assign the normal vector to each vertex of the face
        V1->nx = N.x;
        V1->ny = N.y;
        V1->nz = N.z;

        V2->nx = N.x;
        V2->ny = N.y;
        V2->nz = N.z;

        V3->nx = N.x;
        V3->ny = N.y;
        V3->nz = N.z;
    }

    // assign normals from the normals data. This will override the default
    // normals assigned above...
    count = m_analyzer->GetElementsCount ();
    for (i = 0; i < count; ++i) {
        if (m_group_indices[i].ni != INDEX_MISSING) {
            if ( (m_group_indices[i].ni - 1) < m_analyzer->GetNormalsCount()) {
                VERTEX_DATA *vertex_data = 
                    &m_vertex_data [ m_group_indices[i].vi - 1 ];

                const NORMAL_VERTEX *normal_vertex = 
                    &m_normals[ m_group_indices[i].ni - 1 ];

                vertex_data->nx = normal_vertex->x;
                vertex_data->ny = normal_vertex->y;
                vertex_data->nz = normal_vertex->z;
            }
        }
    }

    // assign texture vertices to each vertex in main vertex data
    count = m_analyzer->GetElementsCount ();
    for (i = 0; i < count; ++i) {
        if (m_group_indices[i].ti != INDEX_MISSING) {
            if ( (m_group_indices[i].ti - 1) < m_analyzer->GetTextureVerticesCount()) {
                VERTEX_DATA *vertex_data = 
                    &m_vertex_data [ m_group_indices[i].vi - 1 ];

                const TEXTURE_VERTEX *texture_vertex = 
                    &m_texture_vertices[ m_group_indices[i].ti - 1 ];

                vertex_data->tx = texture_vertex->x;
                vertex_data->ty = texture_vertex->y;
            }
        }
    }

    // free the intermediate memory blocks...
    delete m_vertices, m_vertices = NULL;
    delete m_normals, m_normals = NULL;
    delete m_texture_vertices, m_texture_vertices = NULL;
    delete m_group_indices, m_group_indices = NULL;

    return 0;
}

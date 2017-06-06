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

/**
 * objparser.h      Parser for OBJ 3D file format
 */
#ifndef __OBJPARSER_H
#define __OBJPARSER_H

/** objparser namespace. Collection of classes for OBJ file parsing. */
namespace objparser {

#define INDEX_MISSING                   (GLushort)-1
#define MAX_INDICES_PER_FACE            100

/** ObjParserError enum. Generic error codes used by all objparser classes. */
enum ObjParserError {
    objparserSuccess = 0,
    objparserErrorIO,
    objparserOutOfMemory,
    objparserInvalidKeyword,
    objparserInvalidVertex, 
    objparserInvalidFace
};

struct VERTEX {
    GLfloat x, y, z;
};

typedef VERTEX NORMAL_VERTEX;

struct TEXTURE_VERTEX {
    GLfloat x, y;
};

struct INDEX {
    GLushort vi, ti, ni;
};

struct VERTEX_DATA {
    GLfloat x, y, z;
    GLfloat nx, ny, nz;
    GLfloat tx, ty;
};

#define VERTEX_DATA_VERTICES_OFFSET             0
#define VERTEX_DATA_NORMALS_OFFSET              (sizeof(GLfloat) * 3)
#define VERTEX_DATA_TEXTURE_VERTICES_OFFSET     (sizeof(GLfloat) * 6)

/** Utils class. Utilities for objparser library. */
class Utils {
public:
    static const char *SkipWhite (const char *s);
    static const char *SkipBlankLines (const char *s);
    static const char *SkipLine (const char *s);
    static bool IsEndOfLine (const char *s);
    static char *TrimComment (char *s);

    static bool ParseInt (const char **ps, GLshort &value);
    static bool ParseVertex (const char *s, VERTEX &v);
    static bool ParseVertex2D (const char *s, GLfloat &x, GLfloat &y);
}; /* Utils class */

/** IndexHash class. */
class IndexHash {
    /* Each WORD can store 16 index states (bit 0 to 15). For a total of 65536 indices,
       we just need 65536/16 = 4096 WORDs of memory. */
    unsigned short state [4096];
public:
    IndexHash () {
        memset (state, 0, sizeof(state));
    }

    bool IsSet (unsigned short index) {
        unsigned short pos, mask;
        IndexToBitMask (index, &pos, &mask);
        return (state[pos] & mask) ? true : false;
    }

    void Set (unsigned short index) {
        unsigned short pos, mask;
        IndexToBitMask (index, &pos, &mask);
        state[pos]|= mask;
    }

    void Clear (unsigned short index) {
        unsigned short pos, mask;
        IndexToBitMask (index, &pos, &mask);
        state[pos]&= ~mask;
    }

    void Reset () {
        memset (state, 0, sizeof(state));
    }

    inline void IndexToBitMask (unsigned short index, 
                                unsigned short *pos, 
                                unsigned short *mask) 
    {
        *pos = index / 16;
        *mask = 1 << (index % 16);
    }
};

/** Analyzer class. Base abstract class for obj format analyzers. */
class Analyzer {
public:
    /** Analyzer ctor. Default constructor. */
    Analyzer ();
    
    /** Analyzer dtor. Destructor. */
    virtual ~Analyzer ();

public:
    /** Analyze method. Analyzes the obj format file. */
    virtual int Analyze (FILE *fp) = 0;

    virtual void Reset ();  

public: 
    size_t GetVerticesCount () const {
        return m_count_vertices;
    }

    size_t GetExtraVerticesCount () const {
        return m_count_extra_vertices;
    }

    size_t GetNormalsCount () const {
        return m_count_normals;
    }

    size_t GetTextureVerticesCount () const {
        return m_count_texture_vertices;
    }

    size_t GetFacesCount () const {
        return m_count_faces;
    }

    size_t GetElementsCount () const {
        return m_count_faces * 3;
    }

    const std::vector<std::string> &GetExternalReferences () const {
        return m_external_references;
    }

    size_t GetRequiredMemory () const {
        return m_required_memory;
    }

    int GetLastErrorCode () const {
        return m_error_code;
    }

    IndexHash &GetIndexHash () {
        return index_hash;
    }

protected:
    void CalculateRequiredMemory ();

protected:  
    size_t m_count_vertices;
    size_t m_count_extra_vertices;
    size_t m_count_normals;
    size_t m_count_texture_vertices;
    size_t m_count_faces;
    IndexHash index_hash;
    std::vector<std::string> m_external_references;
    size_t m_required_memory;   
    int m_error_code;
}; /* Analyzer class */


/** AnalyzerOBJ class. Performs analysis of .OBJ files. */
class AnalyzerOBJ : public Analyzer {
public:
    /** Analyze method. Analyzes the .OBJ file. */
    int Analyze (FILE *fp);
protected:
    int ScanFaces (const char *s, unsigned &count, INDEX *indices);
}; /* AnalyzerOBJ class. */


/** AnalyzerMOD class. Performs analysis of .MOD files. */
class AnalyzerMOD : public Analyzer {
public:
    /** Analyze method. Analyzes the .MOD file. */
    int Analyze (FILE *fp);
}; /* AnalyzerMOD class. */


/** Parser class. Base abstract class for obj format parsers. */
class Parser {
public:
    /** Parser ctor. Default constructor. */
    Parser ();
    
    /** Parser dtor. Destructor. */
    virtual ~Parser ();

public:
    /** Parse method. Parses the obj format file. */
    virtual int Parse (FILE *fp) = 0;

#ifdef _DEBUG
    virtual void Dump ();
#endif

    /** GetAnalyzer method. Returns the internal Analyzer instance. */
    const Analyzer *GetAnalyzer () const {
        return m_analyzer;
    }

    /** GetVerticesCount method. Returns number of vertices. */
    size_t GetVerticesCount () const {
        return m_analyzer->GetVerticesCount();
    }
    
    /** GetElementsCount method. Returns number of elements. */
    size_t GetElementsCount () const {
        return m_analyzer->GetElementsCount ();
    }
    
    /** GetNormalsCount method. Returns number of elements. */
    size_t GetNormalsCount () const {
        return m_analyzer->GetNormalsCount ();
    }

    /** GetFacesCount method. Returns number of faces. */
    size_t GetFacesCount () const {
        return m_analyzer->GetFacesCount ();
    }

    const VERTEX_DATA *GetVertexData () const {
        return m_vertex_data;
    }
    
    const GLushort *GetIndices () const {
        return m_indices;
    }

    int GetLastErrorCode () const {
        return m_error_code;
    }

protected:
    /** Allocates memory for vertex index data */ 
    virtual bool AllocMemory ();

    /** Cleanup method. Performs cleanup and frees resources. This method is automatically
    called by the destructor so you are not required to call it. */
    virtual void Cleanup ();

protected:
    Analyzer        *m_analyzer;                /** pointer to dynamic analayzer object */
    VERTEX          *m_vertices;                /** base pointer to vertex data */
    NORMAL_VERTEX   *m_normals;                 /** base pointer to normals data */
    TEXTURE_VERTEX  *m_texture_vertices;        /** base pointer to texture vertex data */
    INDEX           *m_group_indices;           /** base pointer to grouped faces indices */

    VERTEX_DATA     *m_vertex_data;             /** final output data */
    GLushort        *m_indices;

    int             m_error_code;               /** parser error code */
}; /* Parser class */


/** ParserOBJ class. Parses the .OBJ format files.  */
class ParserOBJ : public Parser {
public:
    /** Parse method. Parses the .OBJ file. */
    int Parse (FILE *fp);

protected:  
    int ParseFaces (const char *s, unsigned &face_count, INDEX *indices, int &extra_vertex_index);
    int Process ();
};


/** ParserMOD class. Parses the .MOD format files.  */
class ParserMOD : public Parser {
public:
    /** Parse method. Parses the .MOD file. */
    int Parse (FILE *fp);
};

}; /* objparser namespace */

#endif /* __OBJPARSER_H */

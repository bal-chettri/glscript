//
// gls_obj.h  glscript library base object interfaces.
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
#ifndef __GLSCRIPT_OBJ_H__
#define __GLSCRIPT_OBJ_H__

#include <assert.h>

namespace gls {

/**
 * RefObject is the abstract base class for all reference types. Basic featuers
 * provided by this class is object lifetime management using reference counting.
 */
class RefObject {
protected:
	// ctor. Intially, referece count is set to 1.
	RefObject () : 
		 m_ref_count(1) 
	{ }

	// dtor. This must be virtual so we can `delete this`.
	virtual ~RefObject() {
		assert(m_ref_count == 0);
	}

public:
	/** AddRef. Adds a reference */
	virtual unsigned long AddRef () {
		return ++m_ref_count;
	}

	/** Release. Releases a reference */
	virtual unsigned long Release () {
		unsigned long val = --m_ref_count;
		if (m_ref_count == 0) {
			delete this;
		}
		return val;
	}

private:
	unsigned long m_ref_count;
};

/** ContainedRefObject class. Contained or aggregated referenced object type. */
class ContainedRefObject : public RefObject {
protected:
	ContainedRefObject (RefObject *parent) 
		: m_parent(parent) 
	{ }

	ContainedRefObject (size_t my_offset) {
		m_parent = reinterpret_cast<RefObject *>((unsigned char *)this - my_offset);
	}

public:
	virtual unsigned long AddRef () {
		return m_parent->AddRef ();
	}

	virtual unsigned long Release () {
		return m_parent->Release ();
	}

public:
	// This does not require Release() to be called on the returned parent object 
	// pointer The caller may, however, Addref it if it needs to use it further.
	RefObject *GetParent() {
		return m_parent;
	}

protected:
	RefObject *m_parent;
};

}; // gls namesapce

#endif /* !__GLSCRIPT_OBJ_H__ */

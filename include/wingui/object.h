#ifndef __WINGUI_OBJECT_H__
#define __WINGUI_OBJECT_H__

#include "Types.h"

namespace wingui {

class Object
{
public:
    Object () : 
       _obj(0)
    {
    }

    ~Object()
    {
    }
private:
    int _obj;
};

};

#endif // !__WINGUI_OBJECT_H__

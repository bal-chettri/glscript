#ifndef __WINGUI_LAYOUT_H__
#define __WINGUI_LAYOUT_H__

namespace wingui {

/** ILayout interface. Interface for basic layout element. */
class ILayout
{
public:
    /** Frame structure. */
    struct Frame
    {
        int x1, y1, x2, y2;
        Frame () :
            x1(0), y1(0), x2(0), y2(0)
        {
        }
        Frame (int x1_, int y1_, int x2_, int y2_) :
            x1(x1_), y1(y1_), x2(x2_), y2(y2_)
        {
        }
        inline int Width() const { return x2 - x1 + 1; }
        inline int Height() const { return y2 - y1 + 1; }
    };
    
    /** Returns / sets frame */
    virtual Frame GetFrame () = 0;
    virtual void SetFrame (const Frame &f) = 0;

    /** is the layout resiable */
    virtual BOOL IsResizable() = 0;
    virtual void SetResizable(BOOL flag) = 0;

    /** is the layout a container layout */
    virtual BOOL IsContainer () = 0;
};

}; // wingui namespace

#endif // !__WINGUI_LAYOUT_H__

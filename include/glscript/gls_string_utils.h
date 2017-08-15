#ifndef __GLSCRIPT_STRING_UTILS_H__
#define __GLSCRIPT_STRING_UTILS_H__

namespace gls
{

class WS2MBS
{
public:
    explicit WS2MBS(const wchar_t *);    
    inline operator const char *() const { return _mbstr; }
private:
    explicit WS2MBS(const WS2MBS &);
    WS2MBS & operator = (const WS2MBS &);
    char *_mbstr;
};

class MBS2WS
{
public:
    explicit MBS2WS(const char *);    
    inline operator const wchar_t *() const { return _wstr; }
private:
    explicit MBS2WS(const MBS2WS &);
    WS2MBS & operator = (const MBS2WS &);
    wchar_t *_wstr;
};

} // gls namespace 

#endif // !__GLSCRIPT_STRING_UTILS_H__

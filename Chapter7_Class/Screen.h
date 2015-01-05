#ifndef _screen_h
#define _screen_h
#include <string>
class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
private:
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
#endif

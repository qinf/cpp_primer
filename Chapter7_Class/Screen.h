#ifndef _screen_h
#define _screen_h

#include <string>
#include <iostream>
#include "Window_mgr.h"

class Screen {
public:
    friend void Window_mgr::clear(ScreenIndex);
    //friend class Window_mgr;
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    void some_member() const;
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {
        os << contents;
    }
};

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos row, pos col, char ch) {
    contents[row*width+col] = ch;
    return *this;
}
inline void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = std::string(s.height * s.width, ' ');
}
#endif

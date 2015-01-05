#include "Screen.h"

char Screen::get(Screen::pos ht, Screen::pos wd) const {
    return contents[ht*width + wd];
}

Screen &Screen::move(Screen::pos r, Screen::pos c) {
    cursor = r * width + c;
    return *this;
}
void Screen::some_member() const {
    ++access_ctr;
}

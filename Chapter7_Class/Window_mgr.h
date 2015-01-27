#ifndef _Window_mgr_h
#define _Window_mgr_h
#include <string>
#include <vector>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};
/*
inline void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = std::string(s.height * s.width, ' ');
}
*/

#endif

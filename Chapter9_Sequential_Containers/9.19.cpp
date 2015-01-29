#include <string>
#include <deque>
#include <list>
#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::deque; using std::string; using std::list;

void func() {
    string s;
    list<string> slist;
    while(cin >> s) {
        slist.push_back(s);
        slist.emplace_back(s);
    }

    for (auto s : slist) {
        cout << s << endl;
    }
}

int main() {
    func();
}

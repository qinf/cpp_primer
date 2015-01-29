#include <string>
#include <deque>
#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::deque; using std::string;

void func() {
    string s;
    deque<string> sdeque;
    while(cin >> s) {
        sdeque.push_back(s);
        sdeque.emplace_back(s);
    }

    for (auto s : sdeque) {
        cout << s << endl;
    }
}

int main() {
    func();
}

#include <iostream>
#include <list>
#include <vector>
#include <string>
using std::cout; using std::endl;
using std::list; using std::vector; using std::string;

void func() {
    list<const char*> il = {"I", "am", "a", "dog"};
    vector<string> svec(il.cbegin(), il.cend());
    for (auto &s : svec)
        cout << s << endl;
}

int main() {
    func();
}

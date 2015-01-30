#include <iostream>
#include <forward_list>
#include <string>
using std::cout; using std::endl;
using std::string; using std::forward_list;

forward_list<string> func(forward_list<string> &il, string s1, string s2) {
    auto iter = il.begin();
    auto prev = il.before_begin();
    for (; iter != il.end(); prev = iter++)
        if (*iter == s1)
            break;
    if (iter == il.end())
        il.insert_after(prev, s2);
    else
        il.insert_after(iter, s2);
    return il;
}

int main() {
    forward_list<string> il{"one", "two", "three", "four"};
    forward_list<string> list_1 = func(il, "two", "two");
    forward_list<string> list_2 = func(il, "five", "five");
    for (auto i : list_2)
        cout << i << endl;
    return 0;
}

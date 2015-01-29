#include <iostream>
#include <list>
#include <vector>
using std::cout; using std::endl;
using std::vector; using std::list;

bool func(vector<int> ivec, list<int> il) {
    if (ivec.size() != il.size())
        return false;
    auto iter1 = ivec.cbegin();
    auto iter2 = il.cbegin();
    for (; iter1 != ivec.end(); ++iter1, ++iter2)
        if (*iter1 != *iter2)
            return false;
    return true;
}

bool func2(vector<int> ivec, list<int> il) {
    list<int> il2(ivec.cbegin(), ivec.cend());
    return il2 == il;
}

int main() {
    vector<int> ivec = {1, 2, 3};
    list<int> il = {1, 2, 3};
    cout << func(ivec, il) << endl;
    cout << func2(ivec, il) << endl;

    cout << "-----------" << endl;

    vector<int> ivec2 = {1, 2, 4};
    list<int> il2 = {1, 2, 3};
    cout << func(ivec2, il2) << endl;
    cout << func2(ivec2, il2) << endl;
}

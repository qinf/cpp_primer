#include <iostream>
#include <list>
#include <vector>
#include <string>
using std::list; using std::vector; using std::string;
using std::cout; using std::endl;

void func() {
    list<int> il{1, 2, 3, 4, 5, 6};
    vector<double> dvec(il.cbegin(), il.cend());
    for (auto i : dvec)
        cout << i << endl;
    cout << "------------" << endl;

    vector<int> ivec{2, 4, 6, 8};
    vector<double> ddvec(ivec.cbegin(), ivec.cend());
    for (auto i : ddvec)
        cout << i << endl;
}

int main() {
    func();
}

#include <iostream>
#include <list>
#include <vector>
using std::cout; using std::endl;
using std::list; using std::vector;

int main() {
    int ia[] = {0, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec(std::begin(ia), std::end(ia));
    list<int> il(std::begin(ia), std::end(ia));
    auto iter = ivec.begin();
    while(iter != ivec.end()) {
        if (*iter % 2 == 0) {
            iter = ivec.erase(iter); // If not assign the value erase return to iter, it will coredump.
        } else
            ++iter;
    }
    auto iter1 = il.begin();
    while(iter1 != il.end()) {
        if (*iter1 % 2 != 0) {
            iter1 = il.erase(iter1);
        } else
            ++iter1;
    }
    for (auto i : ivec)
        cout << i << endl;
    cout << "------" << endl;
    for (auto j : il)
        cout << j << endl;
}

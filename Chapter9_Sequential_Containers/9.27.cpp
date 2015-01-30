#include <iostream>
#include <forward_list>
using std::cout; using std::endl;
using std::forward_list;

int main() {
    forward_list<int> il{1, 2, 3, 4, 5, 6};
    auto iter = il.begin();
    while(iter == il.begin() && iter != il.end() && *iter % 2 == 1)
        iter = il.erase_after(il.before_begin());
    auto iter1 = iter++;
    //auto iter1 = (iter != il.end() ? iter++ : iter);
    while (iter != il.end() && iter1 != il.end()) {
        if (*iter % 2 == 1) {
            iter = il.erase_after(iter1);
        }
        else {
            ++iter;
            ++iter1;
        }
    }
    for (auto i : il)
        cout << i << endl;
}

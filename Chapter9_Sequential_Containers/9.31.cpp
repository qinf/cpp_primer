#include <iostream>
#include <iterator>
#include <list>
#include <forward_list>
using std::cout; using std::endl;
using std::prev; using std::next; using std::list; using std::forward_list;

//use list
void func1() {
    list<int> il{0, 1, 2, 3, 4, 5, 6};
    for (auto iter = il.begin(); iter != il.end(); ) {
        if (*iter % 2)
            iter = next(++il.insert(iter, *iter));
        else {
            iter = il.erase(iter);
        }
    }
    for (auto i : il)
        cout << i << endl;
}

//use forward_list
void func2() {
    forward_list<int> il{0, 1, 2, 3, 4, 5, 6};
    for(auto prev = il.before_begin(), curr = il.begin(); curr != il.end(); ) {
        if (*curr % 2) {
            curr = ++il.insert_after(curr, *curr);
            std::advance(prev, 2);
        } else {
            curr = il.erase_after(prev);
        }
    }

    for (auto i : il)
        cout << i << endl;
}

int main() {
    func1();
    cout << "--------" << endl;
    func2();
}

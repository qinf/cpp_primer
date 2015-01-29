#include <iostream>
#include <list>
#include <deque>
using std::cout; using std::endl;
using std::list; using std::deque;

void func() {
    list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> odd, even;
    for (auto i : il) {
        if (i % 2 == 1)
            odd.push_back(i);
        else
            even.emplace_back(i);
    }

    for (auto i : odd)
        cout << i << endl;
    cout << "-----------" << endl;
    for (auto i : even)
        cout << i << endl;
}

int main() {
    func();
}

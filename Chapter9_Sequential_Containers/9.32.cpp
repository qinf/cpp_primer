#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;

void func() {
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6};
    auto iter = ivec.begin();
    while (iter != ivec.end()) {
        if (*iter % 2) {
            iter = ivec.insert(iter, *iter++);
            iter += 2;
        } else {
            ivec.erase(iter);
        }
    }
    for (auto i : ivec)
        cout << i << endl;
}

int main() {
    func();
    return 0;
}

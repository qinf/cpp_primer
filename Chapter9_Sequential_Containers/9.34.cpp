#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;
int main() {
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ivec.begin();
    while (iter != ivec.end()) {
        if (*iter % 2) {
            iter = ivec.insert(iter, *iter++);
            //++iter;
        }
        ++iter;
    }
    for (auto i : ivec)
        cout << i << endl;

    return 0;
}

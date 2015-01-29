#include <iostream>
#include <vector>

bool find(std::vector<int>::iterator beg, std::vector<int>::iterator end, int value) {
    while (beg != end) {
        if (*beg++ == value) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6};
    bool flag = find(ivec.begin(), ivec.end(), 2);
    std::cout << flag << std::endl;
}

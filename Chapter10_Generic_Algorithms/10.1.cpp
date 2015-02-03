#include <iostream>
#include <algorithm>
#include <vector>
using std::cout; using std::endl;
using std::vector; using std::count;

int main() {
    vector<int> ivec{1, 2, 3, 4, 6, 3, 3, 4, 2, 2};
    int num = count(ivec.begin(), ivec.end(), 2);
    cout << num << endl;
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8};
    for (auto &i : ivec) {
        i = (i % 2 == 1) ? (2 *i) : i;
    }
    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

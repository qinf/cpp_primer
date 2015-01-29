#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;

bool func(vector<int> ivec1, vector<int> ivec2) {
    return ivec1 == ivec2;
}

bool func2(vector<int> ivec1, vector<int> ivec2) {
    if  (ivec1.size() != ivec2.size())
        return false;
    for(vector<int>::size_type index = 0; index != ivec1.size(); ++index) {
        if (ivec1[index] != ivec2[index])
            return false;
    }
    return true;
}

int main() {
    vector<int> ivec1 = {1, 2, 3};
    vector<int> ivec2 = {1, 2, 3};
    cout << func(ivec1, ivec2) << endl;
    vector<int> ivec3 = {1, 2, 3};
    vector<int> ivec4 = {1, 2, 2};
    cout << func(ivec3, ivec4) << endl;
}

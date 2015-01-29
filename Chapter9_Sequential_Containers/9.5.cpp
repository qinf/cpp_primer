#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;

using vector_iter = vector<int>::iterator;
vector_iter func(vector_iter beg, vector_iter end, int value) {
    for (vector_iter iter = beg; iter != end; ++iter) {
        if (*iter == value)
            return iter;
    }
    return end;
}

int main() {
    vector<int> ivec{1, 2, 3, 4, 5, 6};
    vector_iter iter = func(ivec.begin(), ivec.end(), 0);
    if (iter != ivec.end())
        cout << *iter << endl;
    else
        cout << "not found!" << endl;
}

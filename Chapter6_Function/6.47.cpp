#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void print(vector<int> &ivec) {
    #ifndef NDEBUG
        cout << ivec.size() << endl;
    #endif
    while(!ivec.empty()){
        auto tmp = ivec.back();
        ivec.pop_back();
        print(ivec);
        cout << tmp << endl;
    }
}

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6};
    print(ivec);
    return 0;
}

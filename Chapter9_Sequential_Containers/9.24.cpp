#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;

int main() {
    vector<int> ivec = {1, 2, 3};
    cout << ivec.at(0) << endl;
    cout << ivec[0] << endl;
    cout << ivec.front() << endl;
    cout << *ivec.begin() << endl;
    cout << "-------------" << endl;
    vector<int> ivec1;
    cout << ivec1.at(0) << endl;
    cout << ivec1[0] << endl;
    cout << ivec1.front() << endl;
    cout << *ivec1.begin() << endl;
}

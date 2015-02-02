#include <vector>
#include <string>
#include <iostream>
using std::vector; using std::string; using std::cout; using std::endl;

int main() {
    vector<char> chvec{'a', 'b', 'c', 'd', 'e'};
    string s(chvec.begin(), chvec.end());
    cout << s << endl;
}

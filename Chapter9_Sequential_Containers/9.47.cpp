#include <string>
#include <iostream>
using std::string; using std::cout; using std::endl;

void func(string s) {
    auto pos = s.find_first_of("0123456789", 0);
    while(pos != string::npos) {
        cout << s[pos] << endl;
        pos = s.find_first_of("0123456789", pos + 1);
    }
    cout << "------------" << endl;
    for (auto p = 0; (p = s.find_first_of("abcdefghijklmnopqrstuvwxyz", p)) != string::npos; ++p) {
        cout << s[p] << endl;
    }
}

int main() {
    string s("1243abcd");
    func(s);
    return 0;
}

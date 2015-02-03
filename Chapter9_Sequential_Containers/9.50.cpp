#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl;
using std::vector; using std::string;
using std::begin; using std::end;

void func() {
    string s[] = {"123", "234", "345", "456"};
    vector<string> svec(std::begin(s), std::end(s));
    int sum = 0;
    for (auto s : svec) {
        sum += stoi(s);
    }
    cout << sum << endl;
}

void func2() {
    string s[] = {"123.0", "234.0", "345.0", "456.0"};
    vector<string> svec(begin(s), end(s));
    double sum = 0;
    for (auto s : svec) {
        sum += stod(s);
    }
    cout << sum << endl;
}

int main() {
    func();
    cout << "--------------" << endl;
    func2();
}

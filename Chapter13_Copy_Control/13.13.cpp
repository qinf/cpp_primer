#include <iostream>
#include <string>
using std::cout; using std::endl;
using std::string;

struct X {
    X() {cout << "X()" << endl; }
    X(const X &x) {
        cout << "X(const X&)" << endl;
    }
    X &operator=(const X &x) {
        cout << "X &operator=(const X &x)" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void func(X x) {}
void func2(X &x) {}

int main() {
    X x;
    func(x);
    func2(x);
    //X x1 = new X();
    //delete x1;
}

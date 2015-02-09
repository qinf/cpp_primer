#include <iostream>
#include <string>
using std::cout; using std::endl;

class numbered {
public:
    numbered() { ++mysn; }
    friend void f(numbered s) { cout << s.mysn << endl; }
    friend void f1(const numbered &s) { cout << s.mysn << endl; }
    numbered(const numbered &s) { mysn = s.mysn; ++mysn; }
private:
    static int mysn;
};

int numbered::mysn  = 0;

int main() {
    numbered a, b = a, c = b;
    //f(a);
    //f(b);
    //f(c);
    f1(a);
    f1(b);
    f1(c);
}

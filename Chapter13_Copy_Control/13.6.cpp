#include <string>
#include <iostream>
using std::ostream; using std::cout; using std::endl;
using std::string;

class HasPtr {
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &ptr): ps(new string(*(ptr.ps))), i(ptr.i) { }
    HasPtr& operator=(const HasPtr &p) {
        *ps = *(p.ps);
        i = p.i;
        return *this;
    }
    friend ostream& print(ostream &os, HasPtr &p) {
        os << p.ps << " " << p.i << endl;
        return os;
    }

private:
    string *ps;
    int i;
};

int main() {
    HasPtr p("I am a dog");
    print(cout, p);
    HasPtr p1 = p;
    print(cout, p1);
    return 0;
}

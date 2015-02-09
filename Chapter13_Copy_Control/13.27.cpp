#include <iostream>
#include <string>
using std::ostream; using std::cout; using std::endl;
using std::string;

class HasPtr {
public:
    friend ostream& print(ostream &os, HasPtr &p);
    HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}
ostream &print(ostream &os, HasPtr &p) {
    os << *p.ps << " " << p.i << " " << *p.use;
    return os;
}
HasPtr& HasPtr::operator=(const HasPtr &p) {
    ++(*p.use);
    if (--(*use) == 0) {
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    return *this;
}

int main() {
    HasPtr p1("test");
    HasPtr p2 = p1;
    HasPtr p3(p1);
    print(cout, p1) << endl;
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    return 0;
}

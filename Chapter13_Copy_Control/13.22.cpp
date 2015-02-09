#include <iostream>
#include <string>
using std::cout; using std::endl; using std::ostream;
using std::string;

class HasPtr {
public:
    HasPtr() {}
    //默认传入空字符串
    HasPtr(int i, const string &_s = string()): ivalue(i), s(new string(_s)) { }
    HasPtr(const HasPtr &p): ivalue(p.ivalue), s(new string(*p.s)) { }
    HasPtr &operator=(const HasPtr &p) {
        //需要释放s指向的原有内存
        ivalue = p.ivalue;
        s = new string(*p.s);
        return *this;
    }
    ~HasPtr() {
        delete s;
    }
    friend ostream &print(ostream &os, HasPtr &p) {
        os << p.ivalue << " " << *p.s;
        return os;
    }
private:
    int ivalue;
    string *s;
};

int main() {
    HasPtr p(100, "tt");
    HasPtr p1(p);
    print(cout, p) << endl;
    print(cout, p1) << endl;
    return 0;
}

#include <iostream>
#include <string>
using std::cout; using std::endl; using std::ostream;
using std::string;

class HasPtr {
public:
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    HasPtr() {}
    //默认传入空字符串
    HasPtr(int i, const string &_s = string()): ivalue(i), s(new string(_s)) { }
    HasPtr(const HasPtr &p): ivalue(p.ivalue), s(new string(*p.s)) { }
    //HasPtr &operator=(const HasPtr &p) {
    //    auto news = *p.s;
    //    //需要释放s指向的原有内存
    //    delete s;
    //    ivalue = p.ivalue;
    //    //s = new string(*p.s);
    //    s = new string(news);
    //    return *this;
    //}
    HasPtr &operator=(HasPtr p) {
        swap(*this, p);
        return *this;
    }
    ~HasPtr() {
        delete s;
    }
    friend ostream &print(ostream &os, HasPtr &p) {
        os << p.ivalue << " " << p.s;
        return os;
    }
private:
    int ivalue;
    string *s;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    cout << "in swap" << endl;
    using std::swap;
    swap(lhs.ivalue, rhs.ivalue);
    swap(lhs.s, rhs.s);
}

int main() {
    HasPtr p(100, "tt");
    HasPtr p1(p);
    p = p;
    print(cout, p) << endl;
    print(cout, p1) << endl;
    cout << "--------" << endl;
    HasPtr p2(300, "p2");
    HasPtr p3(300, "p3");
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    swap(p2, p3);
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    cout << "-------------" << endl;
    HasPtr p4(400, "p4");
    HasPtr p5(500, "p5");
    print(cout, p4) << endl;
    print(cout, p5) << endl;
    p5 = p4;
    print(cout, p4) << endl;
    print(cout, p5) << endl;
    return 0;
}

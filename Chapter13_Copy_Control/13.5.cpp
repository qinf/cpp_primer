#include <string>
using std::string;

class HasPtr {
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &ptr): ps(new string(*(ptr.ps))), i(ptr.i) { }
    //HasPtr(const HasPtr &ptr) {
    //    ps = new string(*(ptr.ps));
    //    i = ptr.i;
    //}
private:
    string *ps;
    int i;
};

#include <iostream>
#include <string>
using std::string; using std::cout; using std::endl;

void replace(string &s, string oldVal, string newVal) {
    for (auto index = 0; index != s.size(); ++index) {
        if (s.substr(index, oldVal.size()) == oldVal) {
            s.replace(index, oldVal.size(), newVal);
        }
    }
}
int main() {
    string s("tho hah");
    replace(s, "tho", "though");
    cout << s << endl;
    s = "thru bibi";
    replace(s, "thru", "through");
    cout << s << endl;
}

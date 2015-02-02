#include <string>
#include <iostream>
using std::string; using std::cout; using std::endl;
void func(string &s, string pre, string end) {
    s.insert(0, pre);
    s.append(end);
}
int main() {
    string s("Jim");
    func(s, "Mr.", "Jr.");
    cout << s << endl;
    return 0;
}

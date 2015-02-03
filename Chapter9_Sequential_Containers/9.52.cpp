#include <iostream>
#include <string>
#include <stack>
using std::cout; using std::endl;
using std::string; using std::stack;

void func(string &s) {
    bool isSeen = false;
    stack<char> chStack;
    for (auto const ch : s) {
        if (ch == '(') {
            isSeen = true;
            continue;
        } else if (ch == ')') {
            isSeen = false;
            continue;
        }
        if (isSeen)
            chStack.push(ch);
    }
    string str;
    while(!chStack.empty()) {
        str += chStack.top();
        chStack.pop();
    }
    str = s.replace(s.find("("), str.size() + 2, str);
    cout << str << endl;
}

int main() {
    string s("I am a (dog)");
    func(s);
}

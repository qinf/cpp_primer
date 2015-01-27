#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::vector; using std::string; using std::istringstream;
using std::cin; using std::cout; using std::endl;

struct PersonInfo {
    string name;
    vector<string> phones;
};

void func() {
    string line, word;
    vector<PersonInfo> people;
    while(getline(cin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
}

int main() {
    func();
}

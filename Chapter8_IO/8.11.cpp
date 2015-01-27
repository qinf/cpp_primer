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

void print(vector<PersonInfo> &);
void func() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    print(people);
}

void print(vector<PersonInfo> &infos) {
    for (auto &info : infos) {
        cout << "name:" << info.name << " phones:";
        for (auto &s : info.phones)
            cout << s << " ";
        cout << endl;
    }
}

int main() {
    func();
}

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using std::string; using std::vector;
using std::ifstream; using std::istringstream; using std::ostringstream;
using std::cout; using std::endl;

struct PersonInfo {
    string name;
    vector<string> phones;
};

void func(vector<PersonInfo> &people) {
    for (const auto &info : people) {
        ostringstream formatted, badNums;
        for (const auto &phone : info.phones) {
            formatted << " " << phone;
        }
        if (badNums.str().empty()) {
            cout << info.name
               << formatted.str() << endl;
        }
    }
}

int main(int argc, char** argv) {
    string line, word;
    vector<PersonInfo> people;
    ifstream in(argv[1]);
    while(getline(in, line)) {
        PersonInfo info;
        istringstream ins(line);
        ins >> info.name;
        while(ins >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    /*
    for (const auto &info : people) {
        cout << info.name;
        for (const auto phone : info.phones)
            cout << " " << phone;
        cout << endl;
    }
    */
    func(people);
}

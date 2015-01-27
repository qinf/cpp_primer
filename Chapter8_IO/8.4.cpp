#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

void print_from_file(std::string file_name, std::vector<std::string> &svec) {
    std::ifstream in(file_name);
    std::string s;
    while(in >> s)
        svec.push_back(s);
    for (auto i : svec)
        std::cout << i << std::endl;
}

int main() {
    /*
    std::ifstream f("a.txt");
    std::string s;
    std::vector<std::string> svec;
    while(getline(f, s)) {
        std::istringstream ins(s);
        std::string ss;
        while (ins >> ss)
            svec.push_back(ss);
    }
    for (auto i : svec)
        std::cout << i << std::endl;
        */
    std::vector<std::string> svec;
    print_from_file("a.txt", svec);
}

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

void func(std::string file_name) {
    std::ifstream f(file_name);
    std::string line, word;
    std::vector<std::string> svec;
    while(getline(f, line)) {
        //std::cout << line << std::endl;
        std::istringstream ins(line);
        //ins.str(line);
        while(ins >> word) {
            svec.push_back(word);
            std::cout << word << std::endl;
        }
    }
}

void print(std::vector<std::string> &vec) {
    for(auto &s : vec) {
        std::cout << s << std::endl;
    }
}

int main() {
    func("./a.txt");
    return 0;
}

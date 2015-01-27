#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

void func(std::string file_name) {
    std::ifstream f(file_name);
    std::string line, word;
    //std::istringstream ins;
    std::vector<std::string> svec;
    while(getline(f, line)) {
        //std::cout << line << std::endl;
        //ins.str(line);
        svec.push_back(line);
    }
    for (auto &s : svec) {
        std::istringstream ins(s);
        while(ins >> word)
            std::cout << word << std::endl;
    }
}


int main() {
    func("./a.txt");
    return 0;
}

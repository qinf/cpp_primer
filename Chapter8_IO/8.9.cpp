#include <iostream>
#include <string>
#include <sstream>

std::istream &print(std::istream &in) {
    auto old_state = in.rdstate();
    std::cout << old_state << std::endl;
    std::string s;
    while(in >> s) {
        std::cout << s << std::endl;
    }
    in.setstate(old_state);
    std::cout << in.rdstate() << std::endl;
    //in.clear();
    return in;
}

int main() {
    std::istringstream ins("hello");
    print(ins);
    return 0;
}

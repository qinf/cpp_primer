#include <iostream>
#include <string>

std::istream &func(std::istream &in) {
    auto old_state = in.rdstate();
    std::cout << old_state << std::endl;
    std::string s;
    while(in >> s) {
        std::cout << s << std::endl;
    }
    in.setstate(old_state);
    std::cout << in.rdstate() << std::endl;
    in.clear();
    return in;
}

int main() {
    std::istream &in = func(std::cin);
    std::cout << in.rdstate() << std::endl; // Why the state output is 6?
}

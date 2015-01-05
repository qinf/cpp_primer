#ifndef
#define

#include <string>
#include <iostream>

class Person {
public:
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &p){
    is >> p.name >> p.address;
    return is;
}
std::ostream &print(std::ostream &os, const Person &p) {
    os << p.name << " " << p.address;
    return os;
}

#endif

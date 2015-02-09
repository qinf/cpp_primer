#include <iostream>
#include <string>
using std::cout; using std::endl;
using std::string;

class Employee {
public:
    Employee() {
        ++id;
    }
    Employee(string _name): name(_name) {
        ++id;
    }
private:
    string name;
    static int id;
};

int Employee::id = 0;

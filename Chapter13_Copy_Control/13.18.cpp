#include <iostream>
#include <string>
using std::cout; using std::endl; using std::ostream;
using std::string;

class Employee {
public:
    Employee(): id(++num) {
        //id = ++num;
    }
    Employee(string _name): name(_name), id(++num) {
        //id = ++num;
    }
    friend ostream &print(ostream &os, Employee &e) {
        os << e.name << " " << e.id;
        return os;
    }
private:
    string name;
    int id;
    static int num;
};

int Employee::num = 0;

int main() {
    Employee e1;
    Employee e2;
    print(cout, e1) << endl;
    print(cout, e2) << endl;
}

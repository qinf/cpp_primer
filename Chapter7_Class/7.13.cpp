#include "7.2.h"
#include <iostream>
using namespace std;
int main(int args, char** argv) {
    Sales_data total = Sales_data(cin);
    Sales_data trans;
    while(read(cin, trans)) {
        if (total.isbn() == trans.isbn())
            total.combine(trans);
        else {
            print(cout, total) << endl;
            total = trans;
        }
    }
    return 0;
}

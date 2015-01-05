#include "7.2.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main(int args, char** argv) {
    Sales_data data1 = Sales_data();
    Sales_data data2 = Sales_data("2001");
    Sales_data data3 = Sales_data("2002", 3, 30);
    Sales_data data4 = Sales_data(cin);
    print(cout, data1) << endl;
    print(cout, data2) << endl;
    print(cout, data3) << endl;
    print(cout, data4) << endl;
    /*
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while(read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total);
                total.isbn() = trans.isbn();
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    */
    return 0;
}

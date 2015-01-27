#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void func(std::string file, std::string out_file) {
    Sales_data total;
    std::ifstream in(file);
    //std::ofstream out(out_file);
    if(read(in, total)) {
        Sales_data trans;
        while(read(in, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                save_to_file(out_file, total);
                total = trans;
            }
        }
        print(cout, total) << endl;
        save_to_file(out_file, total);
    } else {
        cerr << "No data?!" << endl;
    }
}

int main(int argc, char** argv) {
    func(argv[1], argv[2]);
    return 0;
}

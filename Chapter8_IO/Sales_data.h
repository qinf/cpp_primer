#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
#include <fstream>

class Sales_data {
    friend std::istream &read(std::istream &in, Sales_data &data);
    friend std::ostream &print(std::ostream &out, const Sales_data &data);
    friend void save_to_file(std::string out_file, Sales_data &data);

public:
    Sales_data() = default;
    //Sales_data(std::string _bookNo="", unsigned _units_sold = 0, double _revenue = 0)
        //:bookNo(_bookNo), units_sold(_units_sold), revenue(_revenue) {}
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

std::istream &read(std::istream &in, Sales_data &data);
std::ostream &print(std::ostream &out, const Sales_data &data);

#endif

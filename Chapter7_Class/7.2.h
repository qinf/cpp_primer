#ifndef _7_2_H
#define _7_2_H
#include <string>
#include <iostream>
using std::string;
using std::endl;

struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), price(p), revenue(p*n) { }
    Sales_data(std::istream &is) {
        is >> this->bookNo >> this->units_sold >> this->price;
        this->revenue = this->units_sold * this->price;
    }

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &rhs);
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
};

double Sales_data::avg_price() const {
    if (units_sold != 0) {
        return revenue/units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
    is >> item.bookNo >> item.units_sold >> item.price;
    item.revenue = item.units_sold * item.price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os  << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

#endif

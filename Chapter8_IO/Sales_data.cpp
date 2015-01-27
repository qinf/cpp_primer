#include "Sales_data.h"

/*
double Sales_data::avg_price() const {
    return units_sold != 0 ? (revenue / units_sold) : 0;
}
*/

Sales_data &Sales_data::combine(const Sales_data& data) {
    units_sold += data.units_sold;
    revenue += data.revenue;
    return *this;
}

std::istream &read(std::istream &in, Sales_data &data) {
    in >> data.bookNo >> data.units_sold >> data.revenue;
    return in;
}

std::ostream &print(std::ostream &out, const Sales_data &data) {
    out << data.isbn() << " " << data.units_sold << " " << data.revenue;
    return out;
}

void save_to_file(std::string out_file, Sales_data &data) {
    std::ofstream out(out_file, std::ofstream::app);
    out << data.bookNo << " " <<  data.units_sold << " " << data.revenue << std::endl;
}

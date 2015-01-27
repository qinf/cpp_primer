#include <string>
#include <iostream>

class Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &data);
public:
    Sales_data(std::string s, unsigned cnt, double price):
        bookNo(s), units_sold(cnt), revenue(cnt * price) {
            std::cout << "in Sales_data(std::string s, unsigned cnt, doule price)" << std::endl;
        }
    Sales_data(): Sales_data("", 0, 0) {
        std::cout << "in Sales_data()" << std::endl;
    }
    Sales_data(std::string s): Sales_data(s, 0, 0) {
        std::cout << "in Sales_data(std::string s)" << std::endl;
    }
    Sales_data(std::istream &is): Sales_data() {
        std::cout << "in Sales_data(std::istream &is)" << std::endl;
        read(is, *this);
    }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
std::istream &read(std::istream &is, Sales_data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}
int main(int argc, char ** argv) {
    char ch;
    while (std::cin >> ch) {
        switch (ch) {
            case 'a': {
                Sales_data s1("first", 0, 0);
                break;
            }
            case 'b': {
                Sales_data s2;
                break;
            }
            case 'c': {
                Sales_data s3("third");
                break;
            }
            case 'd':{
                Sales_data s4(std::cin);
                break;
            }
        }
    }
    return 0;
}

#include <string>
#include <iostream>
using std::string; using std::cout; using std::endl;
using std::ostream;

class Date {
public:
    friend ostream &print(ostream &os, Date &date) {
        cout << "month: " << date.month << ", day: "  << date.day << ", year: " << date.year;
        return os;
    }
    Date(const string &s);
private:
    unsigned month;
    unsigned day;
    unsigned year;
};

int main() {
    Date date("Jan 1 1980");
    print(cout, date) << endl;
    Date date2("12/03/2014");
    print(cout, date2) << endl;
    Date date3("January 1,2015");
    print(cout, date3) << endl;
}

Date::Date(const string &s) {
    unsigned format = 0;

    if (s.find_first_of(",") != string::npos)
        format = 1;
    if (s.find_first_of("/") != string::npos)
        format = 2;

    switch (format) {
    case 1:
        if (s.find("Jan") != string::npos) month = 1;
        if (s.find("Feb") != string::npos) month = 2;
        if (s.find("Mar") != string::npos) month = 3;
        if (s.find("Apr") != string::npos) month = 4;
        if (s.find("Map") != string::npos) month = 5;
        if (s.find("Jun") != string::npos) month = 6;
        if (s.find("Jul") != string::npos) month = 7;
        if (s.find("Aug") != string::npos) month = 8;
        if (s.find("Sep") != string::npos) month = 9;
        if (s.find("Oct") != string::npos) month = 10;
        if (s.find("Nov") != string::npos) month = 11;
        if (s.find("Dec") != string::npos) month = 12;

        day = stoi(s.substr(s.find_first_of("1234567890"), s.find(",") - s.find_first_of("1234567890")));
        year = stoi(s.substr(s.find(",") + 1));
        break;
    case 2:
        month = stoi(s.substr(0, s.find_first_of("/")));
        day = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/")));
        year = stoi(s.substr(s.find_last_of("/") + 1));
        break;
    default:
        if (s.find("Jan") != string::npos) month = 1;
        if (s.find("Feb") != string::npos) month = 2;
        if (s.find("Mar") != string::npos) month = 3;
        if (s.find("Apr") != string::npos) month = 4;
        if (s.find("Map") != string::npos) month = 5;
        if (s.find("Jun") != string::npos) month = 6;
        if (s.find("Jul") != string::npos) month = 7;
        if (s.find("Aug") != string::npos) month = 8;
        if (s.find("Sep") != string::npos) month = 9;
        if (s.find("Oct") != string::npos) month = 10;
        if (s.find("Nov") != string::npos) month = 11;
        if (s.find("Dec") != string::npos) month = 12;
        day = stoi(s.substr(s.find_first_of(" ") + 1, s.find_last_of(" ") - s.find_first_of(" ")));
        year = stoi(s.substr(s.find_last_of(" ") + 1));
    }
}

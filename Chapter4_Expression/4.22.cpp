#include <iostream>
#include <string>
using namespace std;
void version_1(int grade)
{
    string finalgrade =
        (grade > 90) ? "high pass"
                     : (grade < 60) ? "fail"
                                    : (grade < 75) ? "low pass" : "pass";
    cout << finalgrade << endl;
}
void version_2(int grade)
{
    string finalgrade =
        (grade > 90) ? "high pass"
                     : (grade > 75) ? "pass"
                                    : (grade < 60) ? "fail" : "low pass";
    cout << finalgrade << endl;
}
int main()
{
    int grade;
    while(cin >> grade) {
        version_2(grade);
    }
    return 0;
}

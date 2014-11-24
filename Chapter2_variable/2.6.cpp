#include <iostream>
using namespace std;
int main()
{
    int month = 9, day = 7;
    cout << "month = " << month<< ", day = " << day << endl;
    int month_1 = 09, day_1 = 07;//出错
    cout << "month_1 = " << month_1 << ", day_1 = " << day_1 << endl;
    return 0;
}

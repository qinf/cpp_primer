#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i = 5;
    int * ptr = &i;
    int ival = 0;
    vector<int> vec{1, 2};
    //cout << (ptr != 0 && *ptr++) << endl;
    //cout << (ival++ && ival) << endl;

    //warning: unsequenced modification and access to 'ival' [-Wunsequenced]]
    cout << ((vec[ival++]) <= vec[ival]) << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    cout << "Who gose with F\145rugs?\012" << endl;
    cout << 3.14e1L << endl;
    cout << 1024f << endl;//出错 invalid suffix "f" on integer constant
    cout << 3.14L << endl;
    return 0;
}

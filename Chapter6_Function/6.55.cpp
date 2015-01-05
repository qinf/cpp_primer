#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int add(int a, int b) {
    return a+b;
}
int minus(int a, int b) {
    return a-b;
}
int multiply(int a, int b) {
    return a*b;
}
int divide(int a, int b) {
    return a/b;
}
int main()
{
    vector<int (*)(int, int)> op_vec;
    op_vec.push_back(add);
    op_vec.push_back(minus);
    op_vec.push_back(multiply);
    op_vec.push_back(divide);
    for(auto op : op_vec)
        //cout << op << endl;
        cout << op(2, 1) << endl;
    return 0;
}

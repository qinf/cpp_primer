#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    double *dp = &i; // cannot convert ‘int*’ to ‘double*’ in initialization
    int *ip = i; // invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
    int *p = &i;

    //2.24
    int j = 42;
    long *lp = &j; // cannot convert ‘int*’ to ‘long int*’ in initialization
}

#include <iostream>
int main()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */; //  warning: missing terminating " character [enabled by default]"
    std::cout << /* "*/" /* "/*" */;
    return 0;
}

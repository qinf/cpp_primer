#include <iostream>
using std::cout;
using std::endl;

// std::begin() and std::end() won't work for pointers. They only work for array.
void version_1(int (&arr)[3][4]) {
    for (const int (&p)[4] : arr) {
        for (int q : p) {
            cout << q << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    version_1(arr);
    for (const int (&p)[4] : arr) {
        for (int q : p)
            std::cout << q << " ";
        std::cout << std::endl;
    }

    //odinary for loop using subscipts
    for (size_t i = 0; i != 3; ++i) {
        for (size_t j = 0; j != 4; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // ordinary for loop by using pointer
    for (int (*p)[4] = arr; p != arr + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }
    return 0;
}

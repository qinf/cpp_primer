#include <iostream>
using namespace std;

void version_1(int (&arr)[3][4]) {
    using int_array = int[4];
    // if there is no & before a, there will be an error: array initializer must be an initializer list
    for(int_array &a : arr) {
        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
}

void version_2(int (&arr)[3][4]) {
    for (int i = 0; i != 3; ++i) {
        for (int j = 0; j != 4; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void version_3(int (&arr)[3][4]) {
    using int_array = int[4];
    for (int_array *a = arr; a != arr+3; ++a) {
        for (int *p = *a; p != *a+4; ++p)
            cout << *p << " ";
        cout << endl;
    }
}

int main() {
    int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    version_1(arr);
    version_2(arr);
    version_3(arr);
    return 0;
}

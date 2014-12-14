#include <iostream>
using namespace std;

void version_1(int (&arr)[3][4]) {
    for(auto &p : arr) {
        for (auto q : p)
            cout << q << " ";
        cout << endl;
    }
}

void version_2(int (&arr)[3][4]) {
    for(size_t i = 0; i != 3; ++i) {
        for (size_t j = 0; j != 4; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void version_3(int (&arr)[3][4]) {
    for(auto p = arr; p != arr + 3; ++p) {
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }
}

int main() {
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    version_1(arr);
    version_2(arr);
    version_3(arr);
    return 0;
}

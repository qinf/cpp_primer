#include <vector>
#include <iostream>
using std::vector; using std::cout; using std::endl;

int main() {
    vector<int> ivec;
    cout << "size: " <<  ivec.size() << ", capacity: " << ivec.capacity() << endl;
    ivec.push_back(1);
    cout << "size: " <<  ivec.size() << ", capacity: " << ivec.capacity() << endl;
    ivec.push_back(1);
    cout << "size: " <<  ivec.size() << ", capacity: " << ivec.capacity() << endl;
    ivec.push_back(1);
    cout << "size: " <<  ivec.size() << ", capacity: " << ivec.capacity() << endl;
    ivec.push_back(1);
    ivec.push_back(1);
    cout << "size: " <<  ivec.size() << ", capacity: " << ivec.capacity() << endl;
    for (auto i = ivec.size(); i != ivec.capacity(); ++i)
        ivec.push_back(1);
    ivec.push_back(1);
    cout << "size: " <<  ivec.size() << ", capacity: " << ivec.capacity() << endl;
    cout << "---------------" << endl;
    vector<int> vec;
    vec.resize(10);
    cout << "size: " <<  vec.size() << ", capacity: " << vec.capacity() << endl;
    for (auto i = vec.size(); i != vec.capacity(); ++i)
        vec.push_back(1);
    vec.push_back(1);
    cout << "size: " <<  vec.size() << ", capacity: " << vec.capacity() << endl;
}

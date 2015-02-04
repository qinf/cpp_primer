#include "StrBlob.h"
#include <iostream>
#include <memory>
using std::cout; using std::endl;
using std::make_shared; using std::string;
int main() {
    StrBlob blob({"I", "am", "a", "dog"});
    cout << blob.use_count() << endl;
    StrBlob b = blob;
    cout << b.use_count() << endl;
    cout << "--------" << endl;
    StrBlobPtr weak_blob(blob);
    cout << weak_blob.weak_count() << endl;
    cout << blob.use_count() << endl;
    StrBlobPtr weak_blob2 = weak_blob;
    cout << weak_blob2.weak_count() << endl;
    cout << blob.use_count() << endl;
    return 0;
}

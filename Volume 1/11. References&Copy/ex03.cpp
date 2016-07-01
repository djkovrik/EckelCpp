/**
Write a program in which you try to
    (1) Create a reference that is not initialized when it is created.
    (2) Change a reference to refer to another object after it is initialized.
    (3) Create a NULL reference.
**/

#include <iostream>

using namespace std;

int main() {

    int x = 10;
    int y = 20;
    int& ref2 = x;

    cout << ref2 << endl;

    // 1
    // int& ref1;
    // error: 'ref1' declared as reference but not initialized

    // 2
    ref2 = y;
    cout << ref2 << endl;

    // 3
    // int& ref3 = NULL;
    // error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'|
return 0;
}

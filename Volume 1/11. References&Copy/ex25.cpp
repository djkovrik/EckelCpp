/**
Create a class containing an array of int.
Can you index through this array using a pointer to member?
**/

#include <iostream>

using namespace std;

class SomeClass {
public:
    SomeClass() : class_array{1,2,3,4,5} {}
    int class_array[5];
};

int main() {

    SomeClass s;
    SomeClass* sPtr = &s;

    int (SomeClass::*array_ptr)[5] = &SomeClass::class_array;

    cout << *( sPtr->*array_ptr + 2 ) << endl;
    /// YES, WE CAN

return 0;
}

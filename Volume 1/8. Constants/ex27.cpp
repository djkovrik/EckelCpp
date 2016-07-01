/**
Create a class with a volatile data member. Create both volatile and
non-volatile member functions that modify the volatile data member,
and see what the compiler says. Create both volatile and non-volatile
objects of your class and try calling both the volatile and non-volatile
member functions to see what is successful and what kind of error
messages the compiler produces.
**/

#include <iostream>

class MyClass {
public:
    MyClass() : x(0) {}
    MyClass(int y) : x(y) {}
    void volatileFunc() volatile { x = 1; }
    void nonVolatileFunc() { x = 2; }
private:
    volatile int x;
};

int main() {

    MyClass m1;
    volatile MyClass m2;

    m1.volatileFunc();    // OK
    m1.nonVolatileFunc(); // OK

    m2.volatileFunc();    // OK
    m2.nonVolatileFunc(); //! error: no matching function for call to 'MyClass::nonVolatileFunc() volatile'
                          //! note: no known conversion for implicit 'this' parameter from 'volatile MyClass*' to 'MyClass*'
return 0;
}

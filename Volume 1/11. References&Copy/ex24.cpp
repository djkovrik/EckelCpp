/**
Create a class containing a double and a print( ) function that prints
the double. In main( ), create pointers to members for both the data member
and the function in your class. Create an object of your class and a pointer
to that object, and manipulate both class elements via your pointers to members,
using both the object and the pointer to the object.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() : d(0) {}
    MyClass(double ddd) : d(ddd) {}
    void print() { cout << "d=" << d << endl; }

    double d;
};

int main() {

    MyClass m(1.23);
    MyClass* mPtr = &m;

    double MyClass::*dPtr = &MyClass::d;
    void (MyClass::*fptr)() = &MyClass::print;

    m.print();
    mPtr->*dPtr = 2.34;
    (mPtr->*fptr)();


return 0;
}

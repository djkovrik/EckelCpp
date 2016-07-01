/**
Create a class containing a const member that you initialize in the
constructor initializer list and an untagged enumeration that you
use to determine an array size.
**/

#include <iostream>

class SomeClass {
public:
    SomeClass() : x(0), i({0}) {}
    SomeClass(int y) : x(y), i({0}) {}
private:
    enum { size = 10 };
    int i[size];
    const int x;
};

int main() {

    SomeClass(123);

return 0;
}

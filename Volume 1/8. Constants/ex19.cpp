/**
Create a class containing both a const and a non-const float.
Initialize these using the constructor initializer list.
**/

#include <iostream>

class S {
public:
    S() : a(0), b(0) {}
    S(float aa, float bb) : a(aa), b(bb) {}
private:
    float a;
    const float b;
};

int main() {

    S(1.1, 2.2);

return 0;
}

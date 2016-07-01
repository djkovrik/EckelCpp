/**
Create a function that takes an argument by value as a const;
then try to change that argument in the function body.
**/

#include <iostream>

class SomeClass {
public:
    SomeClass(int i) : x(i) {}
    void increment() {x++;}
private:
    int x;
};

void someFunc(const SomeClass );

int main() {

    SomeClass a(2);
    someFunc(a);

return 0;
}

//!error: passing 'const SomeClass' as 'this' argument of 'void SomeClass::increment()' discards qualifiers
void someFunc(const SomeClass s) {
    s.increment();
}

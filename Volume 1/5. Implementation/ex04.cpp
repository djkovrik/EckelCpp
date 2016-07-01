/**
Write two classes, each of which has a member function that takes a pointer
to an object of the other class. Create instances of both objects in main( )
and call the aforementioned member function in each class.
**/
#include <iostream>

using namespace std;

class B;

class A {
public:
    void functionA(B *);
    void printName() { cout << "Class A" << endl; }
};

class B {
public:
    void functionB(A *);
    void printName() { cout << "Class B" << endl; }
};

void A::functionA(B *bPtr) { bPtr->printName(); }
void B::functionB(A *aPtr) { aPtr->printName(); }

int main() {

    A a;
    B b;

    a.functionA(&b);
    b.functionB(&a);

return 0;
}

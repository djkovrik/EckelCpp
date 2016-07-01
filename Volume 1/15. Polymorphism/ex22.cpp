/**
Write a class with three overloaded virtual functions. Inherit a
new class from this and override one of the functions. Create an
object of your derived class. Can you call all the base class
functions through the derived-class object? Upcast the address
of the object to the base. Can you call all three functions
through the base? Remove the overridden definition in the derived
class. Now can you call all the base class functions through the
derived-class object?
**/

#include <iostream>

using namespace std;

class Base {
public:
    virtual void a() { cout << "Base::a()" << endl; }
    virtual void a(double ) { cout << "Base::a(double )" << endl; }
    virtual void a(int ) { cout << "Base::a(int )" << endl; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void a() { cout << "Derived::a()" << endl; }
};

int main() {

    Derived* dPtr = new Derived;

    dPtr->a();
    //!dPtr->a(1.2);
    //!dPtr->a(3);

    delete dPtr;

    Base* bPtr = new Derived;

    bPtr->a();
    bPtr->a(1.2);
    bPtr->a(3);

    delete bPtr;

return 0;
}

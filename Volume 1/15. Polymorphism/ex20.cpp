/**
Write a class with one virtual function and one non-virtual function.
Inherit a new class, make an object of this class, and upcast to a pointer
of the base-class type. Use the clock( ) function found in <ctime>
(you’ll need to look this up in your local C library guide) to measure
the difference between a virtual call and non-virtual call. You’ll need
to make multiple calls to each function inside your timing loop in order
to see the difference.
**/

#include <iostream>
#include <ctime>

using namespace std;

class Base {
public:
    virtual void a() const { char c[1000000]; }
    void b() const { char c[1000000]; }
    virtual ~Base(){}
};

class Derived : public Base {};

int main() {

    Base*  bPtr = new Derived;

    clock_t t0 = clock();
    cout << "Virtual calls: ";

    for (size_t i = 0; i < 8000000; i++)
        bPtr->a();

    clock_t t1 = clock();
    cout << (double)(t1 - t0) / CLOCKS_PER_SEC  << endl;

    t0 = clock();
    cout << "Non-virtual calls: ";

    for (size_t i = 0; i < 8000000; i++)
        bPtr->b();

    t1 = clock();
    cout << (double)(t1 - t0) / CLOCKS_PER_SEC  << endl;

return 0;
}

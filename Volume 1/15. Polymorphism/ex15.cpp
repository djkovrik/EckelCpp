/**
Write a small program to show the difference between calling a
virtual function inside a normal member function and calling a
virtual function inside a constructor. The program should prove
that the two calls produce different results.
**/

#include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "f() within Base(): " << endl; f(); }
    virtual void f() { cout << "\tBase::f()" << endl; }
};

class Child : public Base {
public:
    Child() : Base() { cout << "f() within Child(): " << endl; f(); }
    void f() { cout << "\tChild::f()" << endl; }
    void g() { cout << "f() within g(): " << endl; f(); }
};

int main() {

    Child* c = new Child;
    c->g();
    delete c;

return 0;
}

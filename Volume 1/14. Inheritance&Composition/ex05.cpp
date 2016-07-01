/**
In Combined.cpp, create a class D that inherits from B and has a
member object of class C. Add code to show when the constructors
and destructors are being called.
**/

#include <iostream>

using namespace std;

class A {
    int i;
public:
    A(int ii) : i(ii) { cout << "A(" << ii << ")" << endl; }
    ~A() { cout << "~A()" << endl; }
    void f() const {}
};

class B {
    int i;
public:
    B(int ii) : i(ii) { cout << "B(" << ii << ")" << endl; }
    ~B() { cout << "~B()" << endl; }
    void f() const {}
};

class C : public B {
    A a;
public:
    C(int ii) : B(ii), a(ii) { cout << "C(" << ii << ")" << endl; }
    ~C() { cout << "~C()" << endl; }
    void f() const {
        a.f();
        B::f();
    }
};

class D : public B {
    C c;
public:
    D(int ii) : B(ii), c(ii) { cout << "D(" << ii << ")" << endl; }
    ~D() { cout << "~D()" << endl; }
    void f() const {}
};


int main() {
    D d(123);
}

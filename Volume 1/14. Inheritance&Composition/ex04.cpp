/**
Modify Combined.cpp to add another level of inheritance and a new member object.
Add code to show when the constructors and destructors are being called.
**/

#include <iostream>

using namespace std;

class A {
    int i;
public:
    A(int ii) : i(ii) { cout << "A(" << i << ")" << endl; }
    ~A() { cout << "~A()" << endl; }
    void f() const {}
};

class B {
    int i;
public:
    B(int ii) : i(ii) { cout << "B(" << i << ")" << endl; }
    ~B() { cout << "~B()" << endl; }
    void f() const {}
};

class B2 : public B {
    int i;
public:
    B2(int ii) : B(ii), i(ii) { cout << "B2(" << i << ")" << endl; }
    ~B2() { cout << "~B2()" << endl; }
    void f() const {}
};

class C : public B2 {
    A a;
    B b;
public:
    C(int ii) : B2(ii), a(ii), b(ii) { cout << "C(" << ii << ")" << endl; }
    ~C() { cout << "~C()" << endl; }
    void f() const {
        a.f();
        B2::f();
    }
};

int main() {
    C c(47);
}

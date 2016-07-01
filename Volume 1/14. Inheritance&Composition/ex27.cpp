/**
This exercise creates the design pattern called proxy. Start with a
base class Subject and give it three functions: f( ), g( ), and h( ).
Now inherit a class Proxy and two classes Implementation1 and Implementation2
from Subject. Proxy should contain a pointer to a Subject, and all the member
functions for Proxy should just turn around and make the same calls through
the Subject pointer. The Proxy constructor takes a pointer to a Subject that
is installed in the Proxy (usually by the constructor). In main( ), create
two different Proxy objects that use the two different implementations.
Now modify Proxy so that you can dynamically change implementations.
**/

#include <iostream>

using namespace std;

class Subject {
public:
    virtual void f() { cout << "Subject::f() called." << endl; }
    virtual void g() { cout << "Subject::g() called." << endl; }
    virtual void h() { cout << "Subject::h() called." << endl; }
};

class Proxy : public Subject {
public:
    Proxy(Subject* s) : Subject(), sPtr(s) {}
    void f() { sPtr->f(); }
    void g() { sPtr->g(); }
    void h() { sPtr->h(); }
    void setImplementation(Subject* s) { sPtr = s; }
private:
    Subject* sPtr;
};

class Implementation1 : public Subject {
public:
    void f() { cout << "Implementation1::f() called." << endl; }
    void g() { cout << "Implementation1::g() called." << endl; }
    void h() { cout << "Implementation1::h() called." << endl; }
};

class Implementation2 : public Subject {
public:
    void f() { cout << "Implementation2::f() called." << endl; }
    void g() { cout << "Implementation2::g() called." << endl; }
    void h() { cout << "Implementation2::h() called." << endl; }
};



int main() {

    Implementation1 i1;
    Implementation2 i2;

    Proxy p(&i1);

    p.f(); p.g(); p.h();

    p.setImplementation(&i2);
    cout << "Implementation changed." << endl;

    p.f(); p.g(); p.h();

return 0;
}

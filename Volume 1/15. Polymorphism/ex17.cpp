/**
Take Exercise 16 and add calls to f( ) in each destructor. Explain what happens.

Ex 16:
Modify VirtualsInDestructors.cpp by inheriting a class from Derived
and overriding f( ) and the destructor. In main( ), create and upcast
an object of your new type, then delete it.
**/
#include <iostream>
using namespace std;

class Base {
public:
  virtual ~Base() {
    cout << "~Base()\n";
    f();
  }
  virtual void f() { cout << "Base::f()\n"; }
};

class Derived : public Base {
public:
  ~Derived() { cout << "~Derived()\n"; f(); }
  void f() { cout << "Derived::f()\n"; }
};

class Derived2 : public Derived {
public:
  ~Derived2() { cout << "~Derived2()\n"; f(); }
  void f() { cout << "Derived2::f()\n"; }
};

int main() {
  Base* bp = new Derived2;
  delete bp;
} ///:~

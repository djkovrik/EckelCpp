/**
Modify NameHiding.cpp by adding three overloaded functions named h( ) to Base,
and show that redefining one of them in a derived class hides the others.
**/
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
  int f() const {
    cout << "Base::f()\n";
    return 1;
  }
  int f(string) const { return 1; }
  void g() {}

  void h(int) const {}
  void h(string) const {}
  void h(double) const {}
};

class Derived1 : public Base {
public:
  void g() const {}
};

class Derived2 : public Base {
public:
  // Redefinition:
  int f() const {
    cout << "Derived2::f()\n";
    return 2;
  }
};

class Derived3 : public Base {
public:
  // Change return type:
  void f() const { cout << "Derived3::f()\n"; }
};

class Derived4 : public Base {
public:
  // Change argument list:
  int f(int) const {
    cout << "Derived4::f()\n";
    return 4;
  }
};

class Derived5 : public Base {
public:
    // overloaded h()
    void h() const {}
};

int main() {

    Derived5 d5;

    d5.h();
    //!d5.h(2);
    //!d5.h("test");
    //!d5.h(1.2);

}

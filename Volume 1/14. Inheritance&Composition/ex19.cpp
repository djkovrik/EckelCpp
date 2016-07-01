/**
Change Protected.cpp so that Derived is using protected inheritance.
See if you can call value( ) for a Derived object.
**/

#include <iostream>

using namespace std;

class Base {
  int i;
protected:
  int read() const { return i; }
  void set(int ii) { i = ii; }
public:
  Base(int ii = 0) : i(ii) {}
  int value(int m) const { return m*i; }
};

class Derived : protected Base {
  int j;
public:
  Derived(int jj = 0) : j(jj) {}
  void change(int x) { set(x); }
};

int main() {
  Derived d;
  d.change(10);
  //cout << d.value(5) << endl;
  //!error: 'int Base::value(int) const' is inaccessible|
} ///:~

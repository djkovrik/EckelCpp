/**
Modify C14:Order.cpp by adding a virtual function in the base class of
the CLASS macro (have it print something) and by making the destructor
virtual. Make objects of the various subclasses and upcast them to the
base class. Verify that the virtual behavior works and that proper
construction and destruction takes place.
**/

#include <fstream>

using namespace std;

ofstream out("ex21.out");

#define CLASS(ID) class ID { \
public: \
  ID(int) { out << #ID " constructor\n"; } \
  virtual void f() { out << #ID "::f()\n"; } \
  virtual ~ID() { out << #ID " destructor\n"; } \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1 {
  Member1 m1;
  Member2 m2;
public:
  Derived1(int) : m2(1), m1(2), Base1(3) {
    out << "Derived1 constructor\n";
  }
  ~Derived1() {
    out << "Derived1 destructor\n";
  }
};

class Derived2 : public Derived1 {
  Member3 m3;
  Member4 m4;
public:
  Derived2() : m3(1), Derived1(2), m4(3) {
    out << "Derived2 constructor\n";
  }

  void f() {
      out << "Derived2::f()\n";
    }

  ~Derived2() {
    out << "Derived2 destructor\n";
  }
};

int main() {
  Derived2 d2;

  Base1* b = &d2;

  b->f();

  delete b;
}

/**
In CopyConstructor.cpp, inherit a new class from Child and give
it a Member m. Write a proper constructor, copy-constructor,
operator=, and operator<< for ostreams, and test the class in main( ).
**/

#include <iostream>

using namespace std;

class Parent {
  int i;
public:
  Parent(int ii) : i(ii) {
    cout << "Parent(int ii)\n";
  }
  Parent(const Parent& b) : i(b.i) {
    cout << "Parent(const Parent&)\n";
  }
  Parent() : i(0) { cout << "Parent()\n"; }
  friend ostream&
    operator<<(ostream& os, const Parent& b) {
    return os << "Parent: " << b.i << endl;
  }
};

class Member {
  int i;
public:
  Member(int ii) : i(ii) {
    cout << "Member(int ii)\n";
  }
  Member(const Member& m) : i(m.i) {
    cout << "Member(const Member&)\n";
  }
  friend ostream&
    operator<<(ostream& os, const Member& m) {
    return os << "Member: " << m.i << endl;
  }
};

class Child : public Parent {
  int i;
  Member m;
public:
  Child(int ii) : Parent(ii), i(ii), m(ii) {
    cout << "Child(int ii)\n";
  }
  friend ostream&
    operator<<(ostream& os, const Child& c){
    return os << (Parent&)c << c.m
              << "Child: " << c.i << endl;
  }
};

class Other : public Child {
friend ostream& operator<<(ostream& os, const Other& c);
    Member m;
public:
    Other(int ii) : Child(ii), m(ii) { cout << "Other(int ii)\n"; }
    Other(const Other& o) : Child(o), m(o.m) { cout << "Other(const Other&)\n"; }

    Other& operator=(const Other& right) {
        /**Usualy self-assignment check here**/
        cout << "Other::operator=()\n";
        Child::operator=(right);
        m = right.m;
        return *this;
    }
};

ostream& operator<<(ostream& os, const Other& c) {
    return os << (Child&)c << "Other: -- " << c.m << endl;
}

int main() {
  Other o(2);
  cout << "calling copy-constructor: " << endl;
  Other o2 = o;
  cout << "values in o2:\n" << o2;

  Other o3(7);
  cout << "calling assignment operator: " << endl;
  o2 = o3;
  cout << "New values in o2:\n" << o3;

return 0;
}

/**
In AddingVirtuals.cpp, make all the member functions of Pet pure virtuals,
but provide a definition for name( ). Fix Dog as necessary, using the
base-class definition of name( ).
**/
#include <iostream>
#include <string>

using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& petName) : pname(petName) {}
  virtual string name() = 0;
  virtual string speak() = 0;
};

string Pet::name() { return pname; }

class Dog : public Pet {
public:
  Dog(const string& petName) : Pet(petName) {}
  virtual string sit() { return Pet::name() + " sits"; }
  string speak() { return Pet::name() + " says 'Bark!'"; }
  string name() { return Pet::name(); }
};

int main() {

    Pet* p = new Dog("bob");

    cout << p->speak();

    delete p;
}

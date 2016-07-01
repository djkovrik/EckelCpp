/**
In Early.cpp, make Pet a pure abstract base class.
**/

#include <iostream>
#include <string>

using namespace std;

class Pet {
public:
  virtual string speak() const = 0;
};

class Dog : public Pet {
public:
  string speak() const { return "Bark!"; }
};

int main() {
  Dog ralph;
  Pet* p1 = &ralph;
  Pet& p2 = ralph;
  //Pet p3;
  // Late binding for both:
  cout << "p1->speak() = " << p1->speak() <<endl;
  cout << "p2.speak() = " << p2.speak() << endl;
  // Early binding (probably):
  //cout << "p3.speak() = " << p3.speak() << endl;
} ///:~

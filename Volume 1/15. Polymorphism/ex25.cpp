/**
Create a base class containing a clone( ) function that returns a
pointer to a copy of the current object. Derive two subclasses that
override clone( ) to return copies of their specific types. In main( ),
create and upcast objects of your two derived types, then call clone( )
for each and verify that the cloned copies are the correct subtypes.
Experiment with your clone( ) function so that you return the base
type, then try returning the exact derived type. Can you think of
situations in which the latter approach is necessary?
**/

#include <iostream>

using namespace std;

class Base {
public:
    Base() : b(0) {}
    Base(int i) : b(i) {}
    Base(const Base& c) : b(c.b) {}

    virtual string name() const { return "Base"; }
    virtual int value() const   { return b; }
    virtual Base* clone() const { return new Base(*this); }
    virtual ~Base() {}
private:
    int b;
};


class Derived1 : public Base {
public:
    Derived1() : Base(), d1(0) {}
    Derived1(int i) : Base(i), d1(i) {}
    Derived1(const Derived1& c) : Base(c), d1(c.d1) {}

    string name() const { return "Derived1"; }
    int value() const   { return d1; }
    Derived1* clone() const { return new Derived1(*this); }
    ~Derived1() {}
private:
    int d1;
};

class Derived2 : public Base {
public:
    Derived2() : Base(), d2(0) {}
    Derived2(int i) : Base(i), d2(i) {}
    Derived2(const Derived2& c) : Base(c), d2(c.d2) {}

    string name() const { return "Derived2"; }
    int value() const   { return d2; }
    Derived2* clone() const {return new Derived2(*this);}
    ~Derived2() {}
private:
    int d2;
};

int main() {

    Base* p1 = new Derived1(111);
    Base* p2 = new Derived2(222);

    cout << "Objects list: \n"
         << p1->name() << '\t'
         << p2->name() << endl;

    cout << "\nCalling clone(), resulting objects and pointers: ";
    Base* p11 = p1->clone();
    Base* p22 = p2->clone();

    cout << "\n\nObject adress: " << p1
         << "\nClone adress: " << p11
         << "\nClass name: " << p1->name()
         << "\nClone name: " <<  p11->name()
         << "\nClass value: " << p1->value()
         << "\nClone value: " <<  p11->value()

         << "\n\nObject adress: " << p2
         << "\nClone adress: " << p22
         << "\nClass name: " << p2->name()
         << "\nClone name: " << p22->name()
         << "\nClass value: " << p2->value()
         << "\nClone value: " <<  p22->value() << endl;

    delete p1;
    delete p2;
    delete p11;
    delete p22;

return 0;
}

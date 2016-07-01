/**
Use private and protected inheritance to create two new classes from a base class.
Then attempt to upcast objects of the derived class to the base class.
Explain what happens.
**/

class Base {
public:
    Base() {}
};

class Derived1 : protected Base {
public:
    Derived1() {}
};

class Derived2 : private Base {
public:
    Derived2() {}
};

void f(Base b) {}

int main() {

    Derived1 d1;
    Derived2 d2;

    //f(d1);
    //!error: 'Base' is an inaccessible base of 'Derived1'|
    //f(d2);
    //!error: 'Base' is an inaccessible base of 'Derived2'|

return 0;
}

/**
Create a class with a copy-constructor that announces itself. Make a
second class containing a member object of the first class, but do not
create a copy-constructor. Show that the synthesized copy-constructor
in the second class automatically calls the copy-constructor of the first class.
**/

#include <iostream>

using namespace std;

class A {
public:
    A() {}
    A(const A& a) { cout << "A() copy constructor." << endl; }
};

class B{
    A a;
};

void foo(B b) {}

int main() {

    B b;
    foo(b);

return 0;
}

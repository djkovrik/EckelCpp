/**
Create a class with two static member functions. Inherit from this class
and redefine one of the member functions. Show that the other is hidden
in the derived class.
**/

#include <iostream>

using namespace std;

class A {
public:
    static void foo()    { cout << "A::foo()" << endl; }
    static void foo(int) { cout << "A::foo(int)" << endl; }
};

class B : public A {
public:
    static void foo() { cout << "B::foo()" << endl; }
};

using namespace std;

int main() {

    B b;

    b.foo();
    //!b.foo(1);

return 0;
}

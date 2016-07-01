/**
Write code to prove that the compiler automatically synthesizes a copy-constructor
if you don’t create one yourself. Prove that the synthesized copy-constructor performs
a bitcopy of primitive types and calls the copy-constructor of user-defined types.
**/

#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "---Constructor for class A" << endl; }
    A(const A& a) { cout << "---Copy constructor for class A" << endl; }
};

class B {
public:
    B(int xxx = 999) : x(xxx), a() {}
    void print() { cout << "x=" << x << endl; }
private:
    int x;
    A a;
};

int main() {

    cout << "Creating first object..." << endl;
    B object1(123);
    cout << "Assignment operator calls copy constructor..." << endl;
    B object2 = object1;

    object1.print();
    object2.print();

return 0;
}

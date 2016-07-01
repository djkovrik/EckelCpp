/**
Create a class with some member functions, and make that the object
that is pointed to by the argument of Exercise 4. Make the pointer a
const and make some of the member functions const and prove that you
can only call the const member functions inside your function. Make
the argument to your function a reference instead of a pointer.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() : x(0) {}
    MyClass(MyClass& src) : x(src.x) {}
    void increase() { x++; }
    void print() { cout << "x=" << x << endl; }
    void constFunc() const { cout << "MyClass::constFunc()" << endl; }
private:
    int x;
};

MyClass& refAndPointer(MyClass* x) {

    MyClass& y = *x;
    y.print();
    y.increase();
    y.print();
    y.constFunc();
    return y;
}

const MyClass& refAndPointer2(const MyClass& x) {

    const MyClass& y = x;
    //y.print();
    //y.increase();
    //y.print();
    y.constFunc();
    return y;
}

int main() {

    MyClass m;
    refAndPointer(&m);
    refAndPointer2(m);

return 0;
}

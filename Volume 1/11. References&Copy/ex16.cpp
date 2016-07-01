/**
Write a class with a copy-constructor that announces itself to cout. Now create a
function that passes an object of your new class in by value and another one that
creates a local object of your new class and returns it by value. Call these
functions to prove to yourself that the copy-constructor is indeed quietly
called when passing and returning objects by value.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass& m) { cout << ">>>> MyClass copy constructor." << endl; }
};


void foo1(MyClass m) {
    cout << "foo1(MyClass) call." << endl;
}

MyClass foo2() {
    cout << "foo2() call." << endl;
    static MyClass m;
    return m;
}

int main() {

    MyClass obj;

    foo1(obj);
    obj = foo2();


return 0;
}

/**
Write a class that has a const member function and a non-const member function.
Write three functions that take an object of that class as an argument; the first
takes it by value, the second by reference, and the third by const reference.
Inside the functions, try to call both member functions of your class and explain
the results.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    void constFunc() const { cout << "MyClass::constFunc()" << endl; }
    void nonConstFunc()    { cout << "MyClass::nonConstFunc()" << endl; }
};

void func1(MyClass m) {

    cout << "--- func1(MyClass m)" << endl;
    m.constFunc();
    m.nonConstFunc();
}

void func2(MyClass& m) {

    cout << "--- func2(MyClass& m)" << endl;
    m.constFunc();
    m.nonConstFunc();
}

void func3(const MyClass& m) {

    cout << "--- func3(const MyClass& m)" << endl;
    m.constFunc();
    // error: passing 'const MyClass' as 'this' argument of 'void MyClass::nonConstFunc()' discards qualifiers
    // m.nonConstFunc();
}


int main() {

    MyClass obj;

    func1(obj);
    func2(obj);
    func3(obj);

return 0;
}

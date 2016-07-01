/**
Create a class with public, private, and protected data members and function members.
Create an object of this class and see what kind of compiler messages you get when
you try to access all the class members.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() : a(0), b(0), c(0) {}
    int a;
protected:
    int b;
private:
    int c;
};

int main() {

    MyClass m;

    m.a = 1;
    //m.b = 2; // int MyClass::b is protected
    //m.c = 3; // int MyClass::c is private


return 0;
}

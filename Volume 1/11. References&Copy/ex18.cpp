/**
Create a class with a constructor that looks like a copy-constructor,
but that has an extra argument with a default value. Show that this is
still used as the copy-constructor.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() { cout << "MyClass()" << endl; }
    MyClass(const MyClass& m, int x = 0) { cout << "MyClass() copy constructor with an argument." << endl; }
};

void foo1(MyClass m) {}

int main() {

    MyClass obj;
    foo1(obj);

return 0;
}

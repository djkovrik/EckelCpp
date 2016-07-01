/**
Create two classes, Apple and Orange. In Apple, create a constructor that
takes an Orange as an argument. Create a function that takes an Apple and
call that function with an Orange to show that it works. Now make the Apple
constructor explicit to demonstrate that the automatic type conversion is
thus prevented. Modify the call to your function so that the conversion is
made explicitly and thus succeeds.
**/

#include <iostream>

using namespace std;

class Orange;

class Apple {
public:
    //explicit
    Apple(Orange& o) { cout << "Apple(Orange)" << endl; }

};

class Orange {
public:
    Orange() { cout << "Orange()" << endl; }

};

void foo(Apple arg) { cout << "foo called()" << endl; }

int main() {
    Orange b;
    Apple a(b);
    cout << "foo calling..." << endl;
    foo(b);

return 0;
}

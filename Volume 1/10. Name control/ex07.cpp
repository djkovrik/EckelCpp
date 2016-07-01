/**
Create a class with a destructor that prints a message and then calls exit( ).
Create a global object of this class and see what happens.
**/

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
public:
    ~MyClass();
};

MyClass::~MyClass() {
    cout << "~MyClass() call..." << endl;
    exit(EXIT_FAILURE);
}

MyClass m;

int main() {

return 0;
}

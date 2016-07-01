/**
Create a struct that contains an int and a default constructor that
initializes the int to zero. Make this struct local to a function.
Inside that function, create an array of objects of your struct and
demonstrate that each int in the array has automatically been initialized
to zero.
**/

#include <iostream>

using namespace std;

void f() {

    struct MyStruct {
        MyStruct() : x(0) {}
        int x;
    };

    MyStruct m[5];

    for (int i = 0; i < 5; i++)
        cout << m[i].x << ' ';
}

int main() {

    f();

return 0;
}

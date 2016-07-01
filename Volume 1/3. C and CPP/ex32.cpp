/**
Define a function that takes a double argument and returns an int.
Create and initialize a pointer to this function, and call the function through your pointer.
**/

#include <iostream>

using namespace std;

int foo(double );

int main() {

    int (*fPtr)(double);
    fPtr = &foo;

    (*fPtr)(2.2);

return 0;
}


int foo(double d) {

    cout << "Called foo(" << d << ")" << endl;

return 0;
}

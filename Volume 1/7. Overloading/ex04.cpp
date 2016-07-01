/**
Create a class that contains four member functions,
with 0, 1, 2, and 3 int arguments, respectively.
Create a main( ) that makes an object of your class and
calls each of the member functions. Now modify the class
so it has instead a single member function with all the
arguments defaulted. Does this change your main( )?
**/

#include <iostream>

using namespace std;

class One {
public:
    void someFunc(int a) {}
    void someFunc(int a, int b) {}
    void someFunc(int a, int b, int c) {}
    void someFunc(int a, int b, int c, int d) {}
};

class Two {
public:
    void someFunc(int a = 1, int b = 2, int c = 3, int d = 4) {}
};

int main() {

    One testObject;
    //Two testObject;

    testObject.someFunc(1);
    testObject.someFunc(1, 2);
    testObject.someFunc(1, 2, 3);
    testObject.someFunc(1, 2, 3, 4);

return 0;
}

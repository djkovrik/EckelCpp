/**
Create a class with two inline member functions, such that the first
function that’s defined in the class calls the second function,
without the need for a forward declaration. Write a main
that creates an object of the class and calls the first function.
**/

#include <iostream>

using namespace std;

class Some {
public:
    void func1() { func2(); }
    void func2() { cout << "Some::func2()" << endl; }
};

int main() {

    Some s;
    s.func1();

return 0;
}

/**
Create a class without any constructors, and show that you can
create objects with the default constructor. Now create a
nondefault constructor (one with an argument) for the class,
and try compiling again. Explain what happened.
**/

#include <iostream>

using namespace std;

class Test {
    //!Test(int i) : x(i) {}
    //!error: no matching function for call to 'Test::Test()'
private:
    int x;
};

int main() {

    Test t;

return 0;
}

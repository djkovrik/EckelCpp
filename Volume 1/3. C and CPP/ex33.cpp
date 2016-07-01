/**
Declare a pointer to a function taking an int argument and returning
a pointer to a function that takes a char argument and returns a float.
**/

#include <iostream>

using namespace std;

int main() {

    float (*(*fPtr)(int))(char);

    // OR:

    typedef float (*fPtr1)(char);
    fPtr1 (*fPtr2)(int);


return 0;
}

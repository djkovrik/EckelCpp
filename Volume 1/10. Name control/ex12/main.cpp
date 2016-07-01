/**
Make the instance of the object in Exercise 11 static and verify that it cannot
be found by the linker because of this.

Exercise 11:
Create a simple class containing an int, a constructor that initializes the int
from its argument, a member function to set the int from its argument, and
a print( ) function that prints the int. Put your class in a header file,
and include the header file in two cpp files. In one cpp file make an instance
of your class, and in the other declare that identifier extern and test it
inside main( ). Remember, you’ll have to link the two object files or else
the linker won’t find the object.
**/

#include <iostream>
#include "ex12.h"

using namespace std;

int main() {

    extern MyClass m;

    m.print();

return 0;
}

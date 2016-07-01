/**
In two header files, create two namespaces, each containing a class
(with all inline definitions) with a name identical to that in the other namespace.
Create a cpp file that includes both header files. Create a function, and inside
the function use the using directive to introduce both namespaces. Try creating
an object of the class and see what happens. Make the using directives global
(outside of the function) to see if it makes any difference. Repair the problem
using scope resolution, and create objects of both classes.
**/

#include "header1.h"
#include "header2.h"

void someFunc() {

    // using namespace First;
    // using namespace Second;

    // error: reference to 'TestClass' is ambiguous|
    // TestClass t;

    First::TestClass t1;
    Second::TestClass t2;
}


int main() {}

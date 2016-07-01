/**
Declare a function in a header file. Define the function in one cpp file and
call it inside main( ) in a second cpp file. Compile and verify that it works.
Now change the function definition so that it is static and verify that the
linker cannot find it.
**/

#include <iostream>
#include "ex13.h"

using namespace std;

int main() {

    testFunc();

return 0;
}

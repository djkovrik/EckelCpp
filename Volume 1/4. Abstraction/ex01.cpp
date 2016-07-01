/**
In the Standard C library, the function puts( ) prints a char array to the console
(so you can say puts("hello")). Write a C program that uses puts( ) but does not
include <stdio.h> or otherwise declare the function. Compile this program with your
C compiler. (Some C++ compilers are not distinct from their C compilers;
in this case you may need to discover a command-line flag that forces a C compilation.)
Now compile it with the C++ compiler and note the difference.
**/


//!Compilation error:
//!error: 'puts' was not declared in this scope


#include <iostream>

using namespace std;

int main() {

    puts("hello");


return 0;
}

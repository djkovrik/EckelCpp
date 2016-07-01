/**
Create a file containing a function f( ) that takes an int argument and prints it to the console using the printf( ) function 
in <stdio.h> by saying: printf(“%d\n”, i) in which i is the int you wish to print. Create a separate file containing main( ), 
and in this file declare f( ) to take a float argument. Call f( ) from inside main( ). Try to compile and link your program 
with the C++ compiler and see what happens. Now compile and link the program using the C compiler, and see what happens when 
it runs. Explain the behavior.
**/

#include <iostream>
#include "ex09.h"

using namespace std;

void f(float x) {

    cout << x << endl;
}

int main() {

    f(2);

return 0;
}

/**
Create an extern const declaration in one file,
and put a main( ) in that file that prints the
value of the extern const. Provide an extern const
definition in a second file, then compile and link
the two files together.
**/

#include <iostream>
#include "ex07.h"

using namespace std;

extern const int a;

int main() {

    cout << "a = " << a << endl;

return 0;
}

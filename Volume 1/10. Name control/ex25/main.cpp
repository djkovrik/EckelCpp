/**
Create a header file that includes <string> and <iostream> but does not
use any using directives or using declarations. Add "include guards" as
you’ve seen in the header files in this book. Create a class with all
inline functions that contains a string member, with a constructor that
initializes that string from its argument and a print( ) function that
displays the string. Create a cpp file and exercise your class in main( ).
**/

#include "ex25.h"

int main() {

    MyClass m("test");
    m.print();

return 0;
}

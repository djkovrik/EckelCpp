/**
Create a header file containing a namespace. Inside the namespace create several
function declarations. Now create a second header file that includes the first
one and continues the namespace, adding several more function declarations. Now
create a cpp file that includes the second header file. Alias your namespace to
another (shorter) name. Inside a function definition, call one of your functions
using scope resolution. Inside a separate function definition, write a using
directive to introduce your namespace into that function scope, and show that
you don’t need scope resolution to call the functions from your namespace.
**/

#include "header2.h"

namespace My = MyNamespace;

void foo1 () {

    My::func1();
}

void foo2() {

    using namespace My;

    func2(1);
    func3('a');
    func4(2,3);
}

int main() {

    foo1();
    foo2();

return 0;
}

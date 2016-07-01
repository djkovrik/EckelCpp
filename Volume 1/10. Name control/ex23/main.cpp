/**
Repair the problem in Exercise 22 with a using declaration that forces the compiler to
choose one of the identical class names.
**/

#include "header1.h"
#include "header2.h"

void someFunc() {

    using namespace First;

    TestClass t1;
}


int main() {}

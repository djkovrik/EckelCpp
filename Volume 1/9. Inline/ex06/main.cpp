/**
Prove that inline functions default to internal linkage.
**/

//!Standart was changed, nowadays they have external linkage.

#include <iostream>

using namespace std;

int main() {

    extern void f();
    f();

return 0;
}

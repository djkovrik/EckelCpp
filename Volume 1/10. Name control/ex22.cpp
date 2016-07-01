/**
Repair the problem in OverridingAmbiguity.cpp, first with scope resolution,
then instead with a using declaration that forces the compiler to choose one
of the identical function names.
**/
#include "NamespaceMath.h"
#include "NamespaceOverriding2.h"
void s() {
    using namespace Math;
    using namespace Calculation;
    // Everything's ok until:
    //! divide(1, 2); // Ambiguity

    // Variant 1
    // Math::divide(1, 2);

    // Variant 2
    // using Calculation::divide;
    // divide(1, 2);

}
int main() {} ///:~

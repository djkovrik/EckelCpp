/**
In Arithmetic.cpp, demonstrate that the using directive does not extend
outside the function in which the directive was made.
**/
#include "NamespaceInt.h"
void arithmetic() {
      using namespace Int;
      Integer x;
      x.setSign(positive);
}

int main() {

    //Int::
    Integer y;

return 0;
}

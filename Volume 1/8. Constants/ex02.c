/**
Prove to yourself that the C and C++ compilers really do treat constants differently.
Create a global const and use it in a global constant expression;
then compile it under both C and C++.
**/

//!In C-mode we've got an error:
//!error: initializer element is not constant

const int a = 10;
const int b = a + a;

int main() {


return 0;
}

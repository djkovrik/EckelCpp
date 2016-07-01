/**
Determine how to get your compiler to generate assembly code.
Create a file containing a very small function and a main( )
that calls the function. Generate assembly code when the function
is inlined and not inlined, and demonstrate that the inlined
version does not have the function call overhead.
**/
/*
Compile with: g++ -S -masm=intel -g ex22.cpp -o ex22.s
*/

#include <iostream>

using namespace std;

//inline void MySmallFunction() {
//    cout << "Function call..." << endl;
//}

void MySmallFunction();

int main() {

    MySmallFunction();

return 0;
}

void MySmallFunction() {
    cout << "Function call..." << endl;
}

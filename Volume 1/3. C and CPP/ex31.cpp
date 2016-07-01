/**
Modify StringizingExpressions.cpp so that P(A) is conditionally #ifdefed to allow the
debugging code to be automatically stripped out by setting a command-line flag.
You will need to consult your compiler’s documentation to see how to define and undefine
preprocessor values on the compiler command line.
**/

/*
Compile with: g++ -DDEBUG ex31.cpp -o ex31.exe
*/


#include <iostream>

using namespace std;

#ifdef DEBUG
    #define P(A) cout << #A << " (debug version): " << (A) << endl;
#else
    #define P(A) cout << #A << ": " << (A) << endl;
#endif

int main() {
    int a = 1, b = 2, c = 3;
    P(a); P(b); P(c);
    P(a + b);
    P((c - a)/b);

return 0;
}

/**
Write a program with conditionally-compiled code in main( ), so that when
a preprocessor value is defined one message is printed, but when it is not
defined another message is printed. Compile this code experimenting with a
#define within the program, then discover the way your compiler takes preprocessor
definitions on the command line and experiment with that.
**/

/*
Compile WITH or WITHOUT next params: g++ -DTEST ex11.cpp -o ex11.exe
*/

#include <iostream>

using namespace std;

int main() {

    #ifdef TEST
        cout << "Constant was defined." << endl;
    #endif

    #ifndef TEST
        cout << "Constant wasn't defined." << endl;
    #endif

return 0;
}

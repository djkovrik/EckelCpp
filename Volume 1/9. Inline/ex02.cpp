/**
Write a program that uses the FLOOR( ) macro shown at
the beginning of the chapter. Show the conditions under
which it does not work properly.
**/

#include <iostream>

#define FLOOR(x,b) x>=b?0:1

using namespace std;

int main() {

    int a = 1;

    if (FLOOR(1,2))
        cout <<  "True" << endl;
    else
        cout << "False" << endl;


    if (FLOOR(a&0x0f,0x07))
        cout <<  "True" << endl;
    else
        cout << "False" << endl;

return 0;
}

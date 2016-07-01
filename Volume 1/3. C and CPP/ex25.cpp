/**
Define a float variable. Take its address, cast that address to
an unsigned char, and assign it to an unsigned char pointer.
Using this pointer and [ ], index into the float variable and
use the printBinary( ) function defined in this chapter to
print out a map of the float (go from 0 to sizeof(float)).
Change the value of the float and see if you can figure out
what’s going on (the float contains encoded data).
**/
#include <iostream>

using namespace std;

void printBinary(const unsigned char val) {
  for(int i = 7; i >= 0; i--)
    if(val & (1 << i))
      cout << "1";
    else
      cout << "0";
}

int main() {

    float f = 2.2;

    unsigned char *ucPtr = reinterpret_cast<unsigned char*>(&f);

    for(int i = sizeof(float)-1; i >= 0 ; i -= 2){
        printBinary(ucPtr[i-1]);
        printBinary(ucPtr[i]);
    }
    cout << endl;

    float a = -2.2;

    unsigned char *acPtr = reinterpret_cast<unsigned char*>(&a);

    for(int i = sizeof(float)-1; i >= 0 ; i -= 2){
        printBinary(acPtr[i-1]);
        printBinary(acPtr[i]);
    }


return 0;
}

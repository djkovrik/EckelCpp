/**
Modify Boolean.cpp and Bitwise.cpp so they use the explicit operators
(if your compiler is conformant to the C++ Standard it will support these).
**/

#include <iostream>
using namespace std;

// A macro to save typing:
#define PR(STR, EXPR) \
  cout << STR; printBinary(EXPR); cout << endl;

void printBinary(const unsigned char val) {
  for(int i = 7; i >= 0; i--)
    if(val bitand (1 << i))
      cout << "1";
    else
      cout << "0";
}

int main() {
  unsigned int getval;
  unsigned char a, b;
  cout << "Enter a number between 0 and 255: ";
  cin >> getval; a = getval;
  PR("a in binary: ", a);
  cout << "Enter a number between 0 and 255: ";
  cin >> getval; b = getval;
  PR("b in binary: ", b);
  PR("a bitor b = ", a bitor b);
  PR("a bitand b = ", a bitand b);
  PR("a xor b = ", a xor b);
  PR("compl a = ", compl a);
  PR("compl b = ", compl b);
  // An interesting bit pattern:
  unsigned char c = 0x5A;
  PR("c in binary: ", c);
  a or_eq c;
  PR("a or_eq c; a = ", a);
  b or_eq c;
  PR("b or_eq c; b = ", b);
  b xor_eq a;
  PR("b xor_eq a; b = ", b);
} ///:~

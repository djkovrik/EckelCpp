/**
Modify Bitwise.cpp to use the functions from Rotation.cpp.
Make sure you display the results in such a way that it’s
clear what’s happening during rotations.
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

unsigned char rol(unsigned char val) {
  int highbit;
  if(val bitand 0x80) // 0x80 is the high bit only
    highbit = 1;
  else
    highbit = 0;
  // Left shift (bottom bit becomes 0):
  val <<= 1;
  // Rotate the high bit onto the bottom:
  val or_eq highbit;
  return val;
}

unsigned char ror(unsigned char val) {
  int lowbit;
  if(val bitand 1) // Check the low bit
    lowbit = 1;
  else
    lowbit = 0;
  val >>= 1; // Right shift by one position
  // Rotate the low bit onto the top:
  val or_eq (lowbit << 7);
  return val;
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

  unsigned char d;
  cout << "\nEnter a number between 0 and 255: ";
  cin >> getval;
  d = getval;
  PR("d in binary: ", d);
  d = rol(d);
  PR("d after rol: ", d);

  d = ror(d);
  PR("d after ror: ", d);

}

/**
(Challenging) Modify FloatingAsBinary.cpp so that it prints out each part of the double as
a separate group of bits. You’ll have to replace the calls to printBinary( )
with your own specialized code (which you can derive from printBinary( ))
in order to do this, and you’ll also have to look up and understand the floating-point
format along with the byte ordering for your compiler (this is the challenging part).
**/

/*--------------------------------
1bit       11bits        53bits
*       ***********    *********
Sign     Exponent        Mantissa
--------------------------------*/

#include <iostream>
#include <string>

using namespace std;

string makeBinaryFromDouble (double num) {

    string result = "";

    unsigned char* charPtr =
    reinterpret_cast<unsigned char*>(&num);

    unsigned char val;

    int digit = 63;

    for(int index = sizeof(double)-1; index >= 0 ; index -= 1) {

        val = *(charPtr + index);

        for(int i = 7; i >= 0; i--) {
            if(val bitand (1 << i))
                result += "1";
            else
                result += "0";

        if (digit == 63 || digit == 52)
            result += " ";

        digit--;
        }
    }

return result;
}

int main() {

    cout << makeBinaryFromDouble(-2.1) << endl
         << makeBinaryFromDouble(5.6) << endl;

return 0;
}

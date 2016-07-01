/**
Write a program that evaluates the two expressions in the section labeled "precedence.":
    1) A = X + Y - 2/2 + Z;
    2) A = X + (Y - 2)/(2 + Z);
    (Try evaluating the result with X = 1, Y = 2, and Z = 3.)
**/

#include <iostream>

using namespace std;

int main() {

    int X = 1, Y = 2, Z = 3;

    cout << "X = 1, Y = 2, and Z = 3\n" << endl;
    cout << "A = X + Y - 2/2 + Z = " << X + Y - 2/2 + Z << endl;
    cout << "A = X + (Y - 2)/(2 + Z) = " << X + (Y - 2)/(2 + Z) << endl;

return 0;
}

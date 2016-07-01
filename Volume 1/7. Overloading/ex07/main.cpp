/**
Create a new version of the Stack class (from Chapter 6) that contains the
default constructor as before, and a second constructor that takes as its
arguments an array of pointers to objects and the size of that array.
This constructor should move through the array and push each pointer onto
the Stack. Test your class with an array of string.
**/


#include "Stack3.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

    string lines[] = {"one", "two", "three", "four", "five"};

    Stack textlines(lines, sizeof(lines) / sizeof(*lines));

    string* s;
    while((s = (string*)textlines.pop()) != 0) {
        cout << *s << endl;
        delete s;
    }

return 0;
}

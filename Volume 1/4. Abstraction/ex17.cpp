/**
Dynamically create pieces of storage of the following types, using new:
int, long, an array of 100 chars, an array of 100 floats.
Print the addresses of these and then free the storage using delete.
**/

#include <iostream>

using namespace std;

int main() {

    int *intPtr = new int(1);
    long *longPtr = new long(123);
    char *charPtr = new char[100];
    float *floatPtr = new float[100];

    cout << "Addresses: "
         << "\nInt pointer: \t\t" << intPtr
         << "\nLong pointer: \t\t" << longPtr
         << "\nChar[] pointer: \t" << (void*)charPtr     // Address output
         << "\nFloat[] pointer: \t" << floatPtr << endl;

    delete intPtr;
    delete longPtr;
    delete []charPtr;
    delete []floatPtr;


return 0;
}

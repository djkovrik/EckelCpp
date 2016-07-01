/**
Write a const pointer to a double, and point it at an array of double.
Show that you can change what the pointer points to, but you can’t
increment or decrement the pointer.
**/

#include <iostream>

using namespace std;

int main() {

    double d[2] = {1.1, 2.2};
    double* const dptr = d;

    cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << endl;
    cout << "Changing d[1] through pointer..." << endl;

    *(d + 1) = 3.3;

    cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << endl;

    //dptr++;
    //!error: increment of read-only variable 'dptr'

return 0;
}

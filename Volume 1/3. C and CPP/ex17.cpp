/**
Experiment with Union.cpp by removing various union elements to see the
effects on the size of the resulting union. Try assigning to one element
(thus one type) of the union and printing out a via a different element
(thus a different type) to see what happens.
**/

#include <iostream>
using namespace std;

union Packed {
    char i;
    short j;
    int k;
    long l;
    //float f;
    double d;
};

int main() {
    cout << "sizeof(Packed) = "
        << sizeof(Packed) << endl;
    Packed x;
    x.i = 'c';
    cout << x.i << endl;
    x.d = 1.23;
    cout << x.d << endl;

    x.j = 2;
    cout << x.k << ' ' << x.i << endl; // Prints ubdefined data
}

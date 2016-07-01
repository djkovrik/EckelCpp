/**
Apply the technique in ArrayAddresses.cpp to print out the size of the
struct and the addresses of the array elements in StructArray.cpp.
**/

#include <iostream>

using namespace std;

typedef struct {
    int i, j, k;
} ThreeDpoint;



int main() {
    const int SIZE = 4;
    ThreeDpoint p[SIZE];

    for(int i = 0; i < SIZE; i++) {
        p[i].i = i + 1;
        p[i].j = i + 2;
        p[i].k = i + 3;
    }

    cout << "Size of (ThreeDpoint): " << sizeof(ThreeDpoint) << endl;

    for (int i = 0; i < SIZE; i++) {

        cout << "&p[" << i << "] = " << (long)&p[i] << " "
             << "&p[" << i << "].i = " << (long)&p[i].i << " "
             << "&p[" << i << "].j = " << (long)&p[i].j << " "
             << "&p[" << i << "].k = " << (long)&p[i].k << endl;
    }

return 0;
}

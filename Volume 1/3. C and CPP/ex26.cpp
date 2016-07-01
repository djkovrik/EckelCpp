/**
Define an array of int. Take the starting address of that array and
use static_cast to convert it into an void*. Write a function that
takes a void*, a number (indicating a number of bytes), and a value
(indicating the value to which each byte should be set) as arguments.
The function should set each byte in the specified range to the specified
value. Try out the function on your array of int.
**/

#include <iostream>

using namespace std;


void printArray(int *ptr, const int s) {

    for (int i = 0; i < s; i++)
        cout << *(ptr+i) << '\t' << ptr+i << '\n';

    cout << endl;
}

void modifyValues(void* vPtr, int count, int val) {

    int *intPtr = static_cast<int*> (vPtr);

    for (int i = 0; i < count; i++)
        *(intPtr+i) = val;
}

int main() {

    const int SIZE = 6;

    int a[SIZE] = {0};

    void *vPtr = static_cast<void*> (a);

    printArray(a,SIZE);
    modifyValues(vPtr, 2, -1);
    printArray(a,SIZE);
return 0;
}

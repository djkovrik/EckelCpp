/**
Create a function that takes a pointer to an array of double and a value indicating
the size of that array. The function should print each element in the array. Now create
an array of double and initialize each element to zero, then use your function to print the array.
Next use reinterpret_cast to cast the starting address of your array to an unsigned char*,
and set each byte of the array to 1 (hint: you’ll need to use sizeof to calculate the number
of bytes in a double). Now use your array-printing function to print the results.
Why do you think each element was not set to the value 1.0?
**/

#include <iostream>

using namespace std;

void printArray(double* a, int arraySize) {
    cout << endl;

    for (int i = 0; i < arraySize; i++)
        cout <<*(a + i) << " ";

    cout << endl;
}

void printBinary(const unsigned char val) {
  for(int i = 7; i >= 0; i--)
    if(val bitand (1 << i))
      cout << "1";
    else
      cout << "0";

}

int main() {

    const int SIZE = 5;
    double a[SIZE] = {0};

    unsigned char* chPtr = reinterpret_cast<unsigned char*> (a);

    printArray(a, SIZE);

    for(int i = sizeof(double)-1; i >= 0 ; i--)
        printBinary(chPtr[i]);

    for (int i = 0; i < sizeof(double); i++)
        *(chPtr + i) = 1;

    printArray(a, SIZE);

    for(int i = sizeof(double)-1; i >= 0 ; i--)
        printBinary(chPtr[i]);


return 0;
}

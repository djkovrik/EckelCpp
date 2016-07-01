/**
Create a const array of double and a volatile array of double.
Index through each array and use const_cast to cast each element
to non-const and non-volatile, respectively, and assign a value to each element.
**/

#include <iostream>
#include <string>

using namespace std;

void printArray(double* a, int size, string name) {
    cout << "Array " << name << ": ";
    for (int i = 0; i < size; i++)
        cout <<*(a + i) << " ";

    cout << endl;
}

int main() {

    const int SIZE = 8;

    const double array1[SIZE] = {0};
    volatile double array2[SIZE] = {0};

    printArray(const_cast<double*> (array1), SIZE, "one");
    printArray(const_cast<double*> (array2), SIZE, "two");

    cout << "\nRemoving const and volatile modifiers, modifying...\n";

    double *modifyingPtr = 0;

    for (int i = 0; i < SIZE; i++) {

        modifyingPtr = const_cast<double*> (array1 + i);
        *modifyingPtr = i + 0.1 + 0.1 * i;

        modifyingPtr = const_cast<double*> (array2 + i);
        *modifyingPtr = i + 0.3 + 0.3 * i;
    }

    cout << "Modified arrays:\n";
    printArray(const_cast<double*> (array1), SIZE, "one");
    printArray(const_cast<double*> (array2), SIZE, "two");

return 0;
}

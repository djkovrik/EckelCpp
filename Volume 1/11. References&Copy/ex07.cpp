/**
Create a function that takes an argument of a reference to a pointer
to a pointer and modifies that argument. In main( ), call the function.
**/

#include <iostream>

using namespace std;

void modifyPtr(int**& refptr) {

    (*refptr)++;
}

int main() {

    int my_array[] = {1, 2, 3};

    int* iPtr = my_array;   // ptr to arrays head
    int** iPtrPtr = &iPtr;  // ptr to ptr to arrays head

    cout << *(*iPtrPtr) << endl;
    // modifies ptr so it points to next element
    modifyPtr(iPtrPtr);
    cout << *(*iPtrPtr) << endl;


return 0;
}

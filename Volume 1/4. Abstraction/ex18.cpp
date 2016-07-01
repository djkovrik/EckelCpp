/**
Write a function that takes a char* argument. Using new, dynamically allocate
an array of char that is the size of the char array that’s passed to the function.
Using array indexing, copy the characters from the argument to the dynamically allocated
array (don’t forget the null terminator) and return the pointer to the copy.
In your main( ), test the function by passing a static quoted character array,
then take the result of that and pass it back into the function. Print both
strings and both pointers so you can see they are different storage. Using delete,
clean up all the dynamic storage.
**/

#include <iostream>

using namespace std;

void printArray(const char *arrayPtr);
char* createCharArray(char *arrayPtr);

int main() {

    char* str1 = "This is a test line.";
    char* str2 = createCharArray(str1);
    char* str3 = createCharArray(str2);

    cout << "Array 1: " << (void*)str2 << endl;
    printArray(str1);

    cout << "\nArray 2: " << (void*)str3 << endl;
    printArray(str2);

    delete str2;
    delete str3;

return 0;
}

void printArray(const char *arrayPtr) {

    int array_size = 0;
    while ( *(arrayPtr + array_size++ ) != '\0');

    for (int i = 0; i < array_size; i++)
        cout << *(arrayPtr + i);

    cout << endl;
}

char* createCharArray(char *arrayPtr) {

    int array_size = 0;
    while ( *(arrayPtr + array_size++ ) != '\0');

    char* result = new char[array_size];

    for (int i = 0; i < array_size; i++)
        *(result + i) = *(arrayPtr + i);

    *(result + array_size) = '\0';

return result;
}

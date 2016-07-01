/**
Create a struct with a single int data member, and two global functions,
each of which takes a pointer to that struct. The first function has
a second int argument and sets the struct’s int to the argument value,
the second displays the int from the struct. Test the functions.
**/
#include <iostream>

using namespace std;

struct MyStruct {
    int s_value;
};

// Global functions

void changeValue(MyStruct* sPtr, int x) {
    sPtr->s_value = x;
}

void printValue(MyStruct* sPtr) {
    cout << "MyStruct: s_value = " << sPtr->s_value << endl;
}

// Main

int main() {

    MyStruct s;
    changeValue(&s, 123);
    printValue(&s);

return 0;
}

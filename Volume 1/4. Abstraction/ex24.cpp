/**
Create a struct that holds an int and a pointer to another instance
of the same struct. Write a function that takes the address of one of
these structs and an int indicating the length of the list you want
created. This function will make a whole chain of these structs
(a linked list), starting from the argument (the head of the list),
with each one pointing to the next. Make the new structs using new,
and put the count (which object number this is) in the int. In the
last struct in the list, put a zero value in the pointer to indicate
that it’s the end. Write a second function that takes the head of
your list and moves through to the end, printing out both the pointer
value and the int value for each one.
**/
#include <iostream>

using namespace std;

struct MyStruct {
    MyStruct() : value(0), nextPtr(nullptr) {}
    int value;
    MyStruct* nextPtr;
};

void createLinkedList(MyStruct* sPtr, int howMany);
void printandDestoyList(MyStruct* sPtr);

int main() {

    MyStruct m;
    cout << "Initial struct address: " << &m << '\n' << endl;

    // Creates list with 11 items (m + 10 new elements)
    createLinkedList(&m, 10);
    printandDestoyList(&m);

return 0;
}

void createLinkedList(MyStruct* sPtr, int howMany) {

    MyStruct* tempPtr = sPtr;

    for (int i = 1; i <= howMany; i++) {

        MyStruct* newStruct = new MyStruct;
        newStruct->value = i;
        newStruct->nextPtr = nullptr;
        tempPtr->nextPtr = newStruct;

        tempPtr = newStruct;
    }
}

void printandDestoyList(MyStruct *sPtr) {

    MyStruct *tempPtr = sPtr;

    while (tempPtr != nullptr) {
        cout << tempPtr << ": " << tempPtr->value << endl;
        tempPtr = tempPtr->nextPtr;
    }

    MyStruct *deletePtr;
    tempPtr = sPtr;

    while (tempPtr != nullptr) {
        deletePtr = tempPtr;
        tempPtr = tempPtr->nextPtr;
        cout << "Deleting " << deletePtr << ": " << deletePtr->value << "..." << endl;
        delete deletePtr;
    }
}

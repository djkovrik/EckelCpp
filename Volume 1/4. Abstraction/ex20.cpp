/**
How big is a structure? Write a piece of code that prints the size of various structures.
Create structures that have data members only and ones that have data members and function
members. Then create a structure that has no members at all. Print out the sizes of all these.
Explain the reason for the result of the structure with no data members at all.
**/

#include <iostream>

using namespace std;

struct MyStruct1 {
    int a;
    char b;
};

struct MyStruct2 {
    int a;
    int b;
    char c;
    void initialize() {}
};

struct MyStruct3 {
    void initialize() {}
};

struct MyStruct4 {};

int main() {

    cout << "sizeof(MyStruct1): " << sizeof(MyStruct1)
         << "\nsizeof(MyStruct2): " << sizeof(MyStruct2)
         << "\nsizeof(MyStruct3): " << sizeof(MyStruct3)
         << "\nsizeof(MyStruct4): " << sizeof(MyStruct4) << endl;
         // Struct4 has minimal non-zero size

return 0;
}

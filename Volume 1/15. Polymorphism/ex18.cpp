/**
Create a class that has a data member and a derived class that adds
another data member. Write a non-member function that takes an object
of the base class by value and prints out the size of that object using
sizeof. In main( ) create an object of the derived class, print out its
size, and then call your function. Explain what happens.
**/

#include <iostream>

using namespace std;

class Base {
    int b;
};

class Child : public Base {
    int c;
};

void printSize(Base b) {
    cout << "printSize(): " << sizeof(b) << endl;
}

int main() {

    Child c;

    cout << "sizeof Child: " << sizeof(c) << endl;
    printSize(c);

return 0;
}

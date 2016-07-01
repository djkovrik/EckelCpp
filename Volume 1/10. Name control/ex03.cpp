/**
Create a class that holds an array of ints. Set the size of the array using
static const int inside the class. Add a const int variable, and initialize
it in the constructor initializer list; make the constructor inline. Add a
static int member variable and initialize it to a specific value. Add a
static member function that prints the static data member. Add an inline
member function called print( ) to print out all the values in the array
and to call the static member function. Exercise this class in main( ).
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() : value (20) {}
    static void printNumber();
    inline void printArray();
private:
    static const int array_size = 10;
    const int value;
    static int number;
    int my_array[array_size] = {0,1,2,3,4,5,6,7,8,9};
};

int MyClass::number = 30;

void MyClass::printNumber() {
    cout << "static int: " << number << endl;
}

void MyClass::printArray() {
    cout << "Array: ";

    for (int i = 0; i < array_size; i++)
        cout << my_array[i] << ' ';

    cout << endl;

    printNumber();
}

int main() {

    MyClass m;

    m.printArray();

return 0;
}

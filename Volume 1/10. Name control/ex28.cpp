/**
Create a class containing both a const and a non-const static array of int.
Write static methods to print out the arrays. Exercise your class in main( ).
**/

#include <iostream>

using namespace std;

class ArraysClass {
public:
    ArraysClass() {}
    static void print_a();
    static void print_b();
private:
    static const int array_a[];
    static int array_b[];
};

const int ArraysClass::array_a[] = {1,2,3,4};
int ArraysClass::array_b[] = {4,3,2,1,0};


void ArraysClass::print_a() {

    for (int i = 0; i < sizeof(array_a) / sizeof(*array_a); i++ )
        cout << array_a[i] << ' ';
    cout << endl;
}

void ArraysClass::print_b() {

    for (int i = 0; i < sizeof(array_b) / sizeof(*array_b); i++ )
        cout << array_b[i] << ' ';
    cout << endl;
}

int main() {

    ArraysClass obj;

    obj.print_a();
    obj.print_b();

return 0;
}

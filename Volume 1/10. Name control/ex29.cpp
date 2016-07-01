/**
Create a class containing a string, with a constructor that initializes
the string from its argument, and a print( ) function to display the string.
Create another class that contains both const and non-const static arrays of
objects of the first class, and static methods to print out these arrays.
Exercise this second class in main( ).
**/

#include <iostream>
#include <string>

using namespace std;

class StringClass {
public:
    StringClass(string x) : str (x) {}
    void print() const { cout << str << ' '; }
private:
    string str;
};

class ArraysClass {
public:
    ArraysClass() {}
    static void print_a();
    static void print_b();
private:
    static const StringClass array_a[];
    static StringClass array_b[];
};

const StringClass ArraysClass::array_a[] = {StringClass("one"), StringClass("two"),StringClass("three")};
StringClass ArraysClass::array_b[] = {StringClass("four"), StringClass("three"),StringClass("two"),StringClass("one")};


void ArraysClass::print_a() {

    for (int i = 0; i < sizeof(array_a) / sizeof(*array_a); i++ )
        array_a[i].print();
    cout << endl;
}

void ArraysClass::print_b() {

    for (int i = 0; i < sizeof(array_b) / sizeof(*array_b); i++ )
        array_b[i].print();
    cout << endl;
}


int main() {

    ArraysClass obj;

    obj.print_a();
    obj.print_b();

return 0;
}

/**
Create a class that contains an array of char. Add an inline constructor
that uses the Standard C library function memset( ) to initialize the
array to the constructor argument (default this to ‘ ’), and an inline
member function called print( ) to print out all the characters in the array.
**/

#include <iostream>
#include <cstring>
using namespace std;

class MyClass {
public:
    MyClass(char c = ' ') { memset(array, c, size); }

    void print() {
        for (size_t i = 0; i < size; i++)
            cout << array[i] <<  ' ';
        cout << endl;
    }
private:
    enum {size = 10};
    char array[size];
};

int main() {

    MyClass m('z');
    m.print();

    return 0;
}

/**
Create a class containing an int, a constructor that initializes the int
from its argument, and a print( ) function to display the int. Now create
a second class that contains a static object of the first one. Add a static
member function that calls the static object’s print( ) function.
Exercise your class in main( ).
**/

#include <iostream>

using namespace std;

class IntClass {
public:
    IntClass(int i) : x(i) {}
    void print() { cout << x << endl; }
private:
    int x;
};

class StaticIntClass {
public:
    StaticIntClass() {}
    void print() { object.print(); }
private:
    static IntClass object;
};

IntClass StaticIntClass::object(6);

int main() {

    StaticIntClass s;

    s.print();

return 0;
}

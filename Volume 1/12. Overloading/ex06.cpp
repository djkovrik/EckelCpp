/**
Change the print( ) function in Exercise 2 so that it is the overloaded
operator<< as in IostreamOperatorOverloading.cpp.

Ex 2:
Create a simple class containing an int and overload the operator+ as a
member function. Also provide a print( ) member function that takes an
ostream& as an argument and prints to that ostream&. Test your class to
show that it works correctly.
**/

#include <iostream>

using namespace std;

class SimpleInt {
    friend ostream& operator<< (ostream& out, const SimpleInt& s);
public:
    SimpleInt() : i(0) {}
    SimpleInt(int iii) : i(iii) {}

    const SimpleInt operator+(const SimpleInt& right) const { return SimpleInt(i + right.i); }
private:
    int i;
};

ostream& operator<< (ostream& out, const SimpleInt& s) {
    out << s.i;
    return out;
}

int main() {

    SimpleInt a(1), b(2);
    SimpleInt c = a + b;
    cout << c << endl;

return 0;
}

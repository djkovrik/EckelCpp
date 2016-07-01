/**
Add an operator++ and operator-- to Exercise 2, both the prefix and the
postfix versions, such that they return the incremented or decremented object.
Make sure that the postfix versions return the correct value.

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

    //Prefix
    const SimpleInt& operator++() {
        i++;
        return *this;
    }

    const SimpleInt& operator--() {
        i--;
        return *this;
    }

    //Postfix
    const SimpleInt operator++(int) {
        SimpleInt s(i);
        i++;
        return s;
    }

     const SimpleInt operator--(int) {
        SimpleInt s(i);
        i--;
        return s;
    }

    void print(ostream& out) { out << i << endl; }
private:
    int i;
};

ostream& operator<< (ostream& out, const SimpleInt& s) {
    out << s.i;
    return out;
}

int main() {

    SimpleInt a(1), b(2), c(3), d(4);

    cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;

    cout << "cout ++a: " << ++a << endl;
    cout << "cout --b: " << --b << endl;
    cout << "cout c++: " << c++ << endl;
    cout << "cout d--: " << d-- << endl;

    cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;

return 0;
}

/**
Add a binary operator- to Exercise 2 as a member function.
Demonstrate that you can use your objects in complex expressions like
a + b – c.

Ex 2:
Create a simple class containing an int and overload the operator+ as a
member function. Also provide a print( ) member function that takes an
ostream& as an argument and prints to that ostream&. Test your class to
show that it works correctly.
**/

#include <iostream>

using namespace std;

class SimpleInt {
    friend const SimpleInt operator+(const SimpleInt& left, const SimpleInt& right);
    friend const SimpleInt operator-(const SimpleInt& left, const SimpleInt& right);
public:
    SimpleInt() : i(0) {}
    SimpleInt(int iii) : i(iii) {}

    void print(ostream& out) { out << i << endl; }
private:
    int i;
};

const SimpleInt operator+(const SimpleInt& left, const SimpleInt& right) {
    return SimpleInt(left.i + right.i);
}

const SimpleInt operator-(const SimpleInt& left, const SimpleInt& right) {
    return SimpleInt(left.i - right.i);
}

int main() {

    SimpleInt a(3), b(2), c(4);

    SimpleInt d = a + b - c;

    d.print(cout);

return 0;
}

/**
Add the unary operator- to Exercise 2 and demonstrate that it works correctly.

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
    const SimpleInt operator-() const { return SimpleInt(-i); }

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

    cout << -c << endl;

return 0;
}

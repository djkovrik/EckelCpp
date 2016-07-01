/**
Modify Exercise 11 so that the return value optimization is used, if you have not already done so.

Ex 11:
Write a Number class that holds a double, and add overloaded operators
for +, –, *, /, and assignment. Choose the return values for these
functions so that expressions can be chained together, and for efficiency.
Write an automatic type conversion operator intdouble( ).
**/

#include <iostream>

using namespace std;

class Number {
    friend ostream& operator<<(ostream& os, const Number& obj);

public:
    Number() : d(0) {}
    explicit Number(double ddd) : d(ddd) { cout << "Number(" << ddd << ") called." << endl; }

    const Number operator+(const Number& right) const { return Number(d + right.d); }
    const Number operator-(const Number& right) const { return Number(d - right.d); }
    const Number operator*(const Number& right) const { return Number(d * right.d); }
    const Number operator/(const Number& right) const { return Number(d / right.d); }

    Number& operator=(const Number& right) {
        if (this == &right)
            return *this;

        d = right.d;
        return *this;
    }

    Number& operator=(const double& right) {
        if (this->d == right)
            return *this;

        d = right;
        return *this;
    }

    operator double() {
        cout << "operator double() called." << endl;
        return double(d);
    }

private:
    double d;
};

void someFunc(double d) { cout << "someFunc() called." << endl; }

ostream& operator<<(ostream& os, const Number& obj) {
    os << obj.d;
return os;
}

int main() {

    Number a, b, c, d(4.5);

    a = 1.2;
    b = 2.3;
    c  = 3.45;

    someFunc(a);

    cout << "\na = " << a
         << "\nb = " << b
         << "\nc = " << c
         << "\nd = " << d
         << "\na + b = " << a + b
         << "\nd - c = " << d - c
         << "\na * d = " << a * d
         << "\nd / b = " << d / b
         << "\n(a + b * c) - d / a = " << (a + b * c) - d / a
         << endl;

return 0;
}

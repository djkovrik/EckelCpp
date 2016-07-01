/**
Create two classes and create an operator+ and the conversion functions
such that addition is reflexive for the two classes.
**/

#include <iostream>

using namespace std;

class First {
    friend const First operator+(const First& left, const First& right);
public:
    First(int xxx = 0) : x(xxx) {}
private:
    int x;
};

class Second {
public:
    explicit Second(int yyy = 0) : y(yyy) {}

    operator First() const {
        cout << "operator First() called." << endl;
        return First(y);
    }
private:
    int y;
};

const First operator+(const First& left, const First& right) {
  return First(left.x + right.x);
}

int main() {

    First f;
    Second s;

    f + 1;
    2 + f;

    s + 3;
    4 + s;

    f + s;
    s + f;

return 0;
}

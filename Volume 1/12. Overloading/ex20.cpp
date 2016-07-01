/**
Attempt to create a non-member operator= for a class and see what kind of compiler message you get.
**/

#include <iostream>

using namespace std;

class Simple {
public:
    Simple(int x = 0) : data(x) {}
private:
    int data;
};

Simple& operator=(const Simple& left, const Simple& right) {

    if (&left == &right)
        return left;

    left.data = right.data;
    return left;
}

/// error: 'Simple& operator=(const Simple&, const Simple&)' must be a nonstatic member function

int main() {


return 0;
}

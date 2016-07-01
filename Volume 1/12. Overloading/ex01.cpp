/**
Create a simple class with an overloaded operator++. Try calling this
operator in both pre- and postfix form and see what kind of compiler
warning you get.
**/

#include <iostream>

using namespace std;

class Simple {
public:
    Simple() : i(0) {}
    Simple(int iii) : i(iii) {}

    const Simple& operator++() {
        i++;
        return *this;
    }

private:
    int i;

};

int main() {

    Simple s;

    ++s;
    ///error: no 'operator++(int)' declared for postfix '++'
    ///s++;

return 0;
}

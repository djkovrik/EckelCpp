/**
Create a class that contains a pointer, and demonstrate that if you
allow the compiler to synthesize the operator= the result of using
that operator will be pointers that are aliased to the same storage.
Now fix the problem by defining your own operator= and demonstrate
that it corrects the aliasing. Make sure you check for self-assignment
and handle that case properly.
**/

#include <iostream>

using namespace std;

class PointerClass {
public:
    PointerClass() : xPtr(new int) {}
    void showAddress() const { cout << "pointer: " << xPtr << endl; }
    /*
    PointerClass& operator=(const PointerClass& right) {
        if (this == &right)
            return *this;

        xPtr = new int(*right.xPtr);

        return *this;
    }
    */
private:
    int* xPtr;
};

int main() {

    PointerClass a, b;
    a = b;

    a.showAddress();
    b.showAddress();

return 0;
}

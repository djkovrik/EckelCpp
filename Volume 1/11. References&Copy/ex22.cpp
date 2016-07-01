/**
This exercise creates an alternative to using the copy-constructor.
Create a class X and declare (but don’t define) a private copy-constructor.
Make a public clone( ) function as a const member function that returns a copy
of the object that is created using new. Now write a function that takes as an
argument a const X& and clones a local copy that can be modified. The drawback
to this approach is that you are responsible for explicitly destroying the
cloned object (using delete) when you’re done with it.
**/

#include <iostream>

using namespace std;

class X {
public:
    X() : x(0) {}
    void inc() { x++; }
    X* clone() const;
private:
    X(const X& x) : x(0) {}
    int x;
};

X* X::clone() const {
    X* ptr = new X(*this);
    ptr->x = x;
    return ptr;
}

void modifyX(const X& x) {
    X* y = x.clone();
    //x.inc();
    y->inc();
    delete y;
}


int main() {

    X x;
    modifyX(x);

return 0;
}

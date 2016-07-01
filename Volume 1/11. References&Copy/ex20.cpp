/**
Create a very simple class, and a function that returns an object of that class
by value. Create a second function that takes a reference to an object of your
class. Call the first function as the argument of the second function, and
demonstrate that the second function must use a const reference as its argument.
**/

#include <iostream>

using namespace std;

class X {
public:
    X() : x(0) {}
    X(int xxx) : x(xxx) {}
private:
    int x;
};

X func1() {
    cout << "func1()" << endl;
    return X();
}

//void func2(X& x) {
//error: invalid initialization of non-const reference of type 'X&' from an rvalue of type 'X'
void func2(const X& x) {
    cout << "func2()" << endl;
}

int main() {

    func2( func1() );


return 0;
}

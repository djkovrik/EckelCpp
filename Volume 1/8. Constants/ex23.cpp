/**
Create a class with both const and non-const member functions.
Create const and non-const objects of this class, and try calling
the different types of member functions for the different types of objects.
**/

#include <iostream>

using namespace std;

class MyClass {
public:
    void constFunc() const { cout << "Const function called." << endl; }
    void nonConstFunc() { cout << "Non-const function called." << endl; }
};

using namespace std;

int main() {

    MyClass m1;
    const MyClass m2;

    m1.constFunc();     // OK
    m1.nonConstFunc();  // OK

    m2.constFunc();     // OK
    m2.nonConstFunc();  //! error: no matching function for call to 'MyClass::nonConstFunc() const'
                        //! note: no known conversion for implicit 'this' parameter from 'const MyClass*' to 'MyClass*'
return 0;
}

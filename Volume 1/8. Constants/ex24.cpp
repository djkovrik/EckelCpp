/**
Create a class with both const and non-const member functions.
Try to call a non-const member function from a const member
function to see what kind of compiler error message you get.
**/

#include <iostream>

class M {
public:
    void nonConstFunc() {}
    void constFunc() const { nonConstFunc(); }
    //! error: no matching function for call to 'M::nonConstFunc() const'
    //! note: no known conversion for implicit 'this' parameter from 'const M* const' to 'M*'

};

int main() {

return 0;
}

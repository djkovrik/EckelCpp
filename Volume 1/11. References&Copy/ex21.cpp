/**
Create a simple class without a copy-constructor, and a simple function
that takes an object of that class by value. Now change your class by
adding a private declaration (only) for the copy-constructor. Explain
what happens when your function is compiled.
**/

#include <iostream>

using namespace std;

class SimpleClass {
public:
    SimpleClass() {}
private:
    ///SimpleClass(const SimpleClass& s);
    ///error: 'SimpleClass::SimpleClass(const SimpleClass&)' is private|

};

void foo(SimpleClass s) {}

int main() {

    SimpleClass s;
    foo(s);

return 0;
}

/**
Create a function that takes a float by value. Inside the function,
bind a const float& to the argument, and only use the reference from
then on to ensure that the argument is not changed.
**/

#include <iostream>

using namespace std;

void foo(float );

int main() {

    float f = 2.2;

    cout << "f: " << f << endl;
    foo(f);
    cout << "f after foo(): " << f << endl;

return 0;
}

void foo(float f) {

    //const
    //!error: increment of read-only reference 'flink'
    float& flink = f;
    flink++;
}

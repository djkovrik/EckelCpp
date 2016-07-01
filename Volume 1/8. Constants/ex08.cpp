/**
Write two pointers to const long using both forms of the declaration.
Point one of them to an array of long. Demonstrate that you can
increment or decrement the pointer, but you can’t change what it points to.
**/

#include <iostream>

using namespace std;

int main() {

    const long a = 111111;
    const long b[3] = {111, 222,333};

    const long* cla = &a;
    long const* clb = b;

    cout << "*clb = " << *clb << endl;
    cout << "Pointer incrementation..." << endl;
    clb++;
    cout << "*clb = " << *clb << endl;

    //*(clb+1) = 444;
    //!error: assignment of read-only location '*(clb + 4u)'

return 0;
}

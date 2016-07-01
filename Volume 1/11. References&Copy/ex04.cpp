/**
Write a function that takes a pointer argument, modifies
what the pointer points to, and then returns the destination
of the pointer as a reference.
**/

#include <iostream>

using namespace std;

int& refAndPointer(int* x) {
    int& y = *x;
    y++;
    return y;
}

int main() {

    int i = 10;
    cout << i << endl;
    cout << refAndPointer(&i) << endl;

return 0;
}

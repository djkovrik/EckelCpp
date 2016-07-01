/**
Write a const pointer to a const object. Show that you can
only read the value that the pointer points to, but you can’t
change the pointer or what it points to.
**/

#include <iostream>

int main() {

    int a[2] = {1, 2};
    const int* const aptr = a;

    //aptr++;
    //!error: increment of read-only variable 'aptr'

    //*(aptr + 1) = 3;
    //!error: assignment of read-only location '*(((const int*)aptr) + 4u)'

return 0;
}

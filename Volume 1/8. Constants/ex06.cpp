/**
Create a const array of char, then try to change one of the chars.
**/

#include <iostream>

int main() {

    const char array[] = "Test";
    array[0] = 't';
    //!error: assignment of read-only location 'array[0]'

return 0;
}

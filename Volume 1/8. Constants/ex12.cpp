/**
Create a character array literal with a pointer that points to the
beginning of the array. Now use the pointer to modify elements in
the array. Does your compiler report this as an error? Should it?
If it doesn’t, why do you think that is?
**/

#include <iostream>

using namespace std;

int main() {

    char literal[] = "text";
    char* cp = literal;

    cout << literal << endl;

    *cp = 'T'; //!No errors

    cout << literal << endl;

return 0;
}

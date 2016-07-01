/**
Write two for loops that print out values from zero to 10.
In the first, define the loop counter before the for loop,
and in the second, define the loop counter in the control
expression of the for loop. For the second part of this
exercise, modify the identifier in the second for loop
so that it as the same name as the loop counter for the
first and see what your compiler does.
**/
#include <iostream>

using namespace std;

int main() {

    int i;

    for (i = 0; i <= 10; i++)
        cout << i << " ";

    cout << '\n';

    for (int i = 0; i <= 10; i++)
        cout << i << " ";

    cout << endl;

return 0;
}

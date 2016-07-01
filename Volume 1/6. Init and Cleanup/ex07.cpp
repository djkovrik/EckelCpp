/**
Use aggregate initialization to create an array of double in
which you specify the size of the array but do not provide
enough elements. Print out this array using sizeof to determine
the size of the array. Now create an array of double using
aggregate initialization and automatic counting. Print out the array.
**/
#include <iostream>

using namespace std;

int main() {

    double a[5] = {1.1, 2.2, 3.3};
    int array_size_a = sizeof(a) / sizeof(*a);

    for (int i = 0; i < array_size_a; i++)
        cout << a[i] << '\t';
    cout << endl;

    double b[] = {4.4, 5.5, 6.6, 7.7};
    int array_size_b = sizeof(b) / sizeof(*b);

    for (int i = 0; i < array_size_b; i++)
        cout << b[i] << '\t';
    cout << endl;

return 0;
}

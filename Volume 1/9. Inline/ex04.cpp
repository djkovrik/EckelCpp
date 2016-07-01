/**
Create two identical functions, f1( ) and f2( ). Inline f1( ) and
leave f2( ) as an non-inline function. Use the Standard C Library
function clock( ) that is found in <ctime> to mark the starting
point and ending points and compare the two functions to see which
one is faster. You may need to make repeated calls to the functions
inside your timing loop in order to get useful numbers.
**/

#include <iostream>
#include <ctime>

using namespace std;

void f1(int );
void f2(int );

int main() {

    clock_t t;
    float timing1, timing2;

    t = clock();

    for (long i = 0; i < 100000000; i++)
        f1(i);

    timing1 = static_cast<float>((clock() - t)) / CLOCKS_PER_SEC;

    t = clock();

    for (long i = 0; i < 100000000; i++)
        f2(i);

    timing2 = static_cast<float>((clock() - t)) / CLOCKS_PER_SEC;

    cout << "f1() timing: " << timing1 << endl;
    cout << "f2() timing: " << timing2 << endl;
return 0;
}

inline void f1(int x) {
    int y = x * x;
}

void f2(int x) {
    int y = x * x;
}

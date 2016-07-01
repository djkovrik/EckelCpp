/**
Experiment with the size and complexity of the code inside the functions
in Exercise 4 to see if you can find a break-even point where the inline
function and the non-inline function take the same amount of time.
If you have them available, try this with different compilers and
note the differences.
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

    for (long i = 0; i < 100000; i++)
        f1(i);

    timing1 = static_cast<float>((clock() - t)) / CLOCKS_PER_SEC;

    t = clock();

    for (long i = 0; i < 100000; i++)
        f2(i);

    timing2 = static_cast<float>((clock() - t)) / CLOCKS_PER_SEC;

    cout << "f1() timing: " << timing1 << endl;
    cout << "f2() timing: " << timing2 << endl;
return 0;
}

inline void f1(int x) {
    int y = x * x;
    int a[10000] = {0};

}

void f2(int x) {
    int y = x * x;
    int a[10000] = {0};
}

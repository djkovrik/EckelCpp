/**
Correct the TRACE( ) macro as specified in this chapter, and prove that it works correctly.
**/

#include <iostream>

// #define TRACE(s) cerr << #s << endl; s
#define TRACE(s) cerr << #s << endl, s

using namespace std;

int main() {

    int x;
    TRACE(x = 2);
    cout << x << endl;
    TRACE(++x);
    cout << x << endl;

return 0;
}

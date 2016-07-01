/**
Templatize the fibonacci( ) function on the type of value that it produces
(so it can produce long, float, etc. instead of just int).
**/

#include <iostream>

using namespace std;

template <class T>
T fibonacci(T n) {
    const int sz = 100;
    static T f[sz];
    f[0] = f[1] = 1;

    int i;
    for(i = 0; i < sz; i++)
        if(f[i] == 0) break;
    while(i <= n) {
        f[i] = f[i-1] + f[i-2];
        i++;
    }
    return f[n];
}


int main() {

    cout << fibonacci(11) << endl;

return 0;
}

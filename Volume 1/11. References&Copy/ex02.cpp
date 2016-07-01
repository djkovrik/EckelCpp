/**
Take the code fragments in the beginning of the section titled
"References in C++" and put them into a main( ). Add statements
to print output so that you can prove to yourself that references
are like pointers that are automatically dereferenced.
**/

#include <iostream>

using namespace std;

int main() {
    int y;
    int& r = y;

    const int& q = 12;

    int x = 0;
    int& a = x;

    cout << "x = " << x << ", a = " << a << endl;
    a++;
    cout << "x = " << x << ", a = " << a << endl;
return 0;
}

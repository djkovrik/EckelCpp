/**
Write a program that takes a string as the command-line argument.
Write a for loop that removes one character from the string with
each pass, and use the DEBUG( ) macro from this chapter to print
the string each time.
**/

#include <iostream>

using namespace std;

#define DEBUG(x) cout << #x " = " << x << endl

int main(int argc, char* argv[]) {

    if (argc > 1) {

        string s(argv[1]);
        size_t sz = s.size();

        for (size_t n = 0; n < sz; ++n) {
            s = s.erase(sz - n - 1, 1);
            DEBUG(s);
        }
    }

return 0;
}

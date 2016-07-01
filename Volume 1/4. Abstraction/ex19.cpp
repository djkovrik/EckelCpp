/**
Show an example of a structure declared within another structure (a nested structure).
Declare data members in both structs, and declare and define member functions in both structs.
Write a main( ) that tests your new types.
**/

#include <iostream>

using namespace std;

struct External {
    struct Internal {
        int x;
        void printInternalX() {cout << "Internal X: " << x << endl; }
    } data;
    int x;
    void printExternalX() {cout << "External X: " << x << endl; }
};

int main() {

    External e;

    e.x = 6;
    e.data.x = 666;

    e.printExternalX();
    e.data.printInternalX();

return 0;
}

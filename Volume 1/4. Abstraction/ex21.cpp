/**
C++ automatically creates the equivalent of a typedef for structs, as you’ve seen
in this chapter. It also does this for enumerations and unions.
Write a small program that demonstrates this.
**/
#include <iostream>

using namespace std;

int main() {

    struct MyStruct() {
    int x;
    void initialize() {cout << "MyStruct initialized." << endl; }
    } s;

    union MyUnion {
        int a;
        char b;
    } u;

    enum COLORS {RED = 1, GREEN = 2;} c;

return 0;
}

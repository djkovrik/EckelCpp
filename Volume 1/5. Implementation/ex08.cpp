/**
Create a class with data members distributed among numerous public, private,
and protected sections. Add a member function showMap( ) that prints the
names of each of these data members and their addresses.
If possible, compile and run this program on more than one compiler
and/or computer and/or operating system to see if there are
layout differences in the object.
**/
#include <iostream>

using namespace std;

class Mapper {
public:
    Mapper() : a(1), b(2.2), c(3), d(4.4), e(5), f('z') {}
    void showMap();

    int a;
    double b;
protected:
    int c;
    double d;
private:
    int e;
    char f;
};

void Mapper::showMap() {

    cout << "Public: "
         << "\n&a: " << (long)&a
         << "\n&b: " << (long)&b
         << "\nProtected: "
         << "\n&c: " << (long)&c
         << "\n&d: " << (long)&d
         << "\nPrivate: "
         << "\n&e: " << (long)&e
         << "\n&f: " << (long)&f
         << endl;
}

int main() {

    Mapper m;
    m.showMap();

return 0;
}

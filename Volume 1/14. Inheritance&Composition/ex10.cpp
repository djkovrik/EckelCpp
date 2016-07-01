/**
Write a class containing a long and use the psuedo-constructor call syntax in the constructor to initialize the long.
**/

#include <iostream>
#include <clocale>

using namespace std;

class SomeLong {
public:
    SomeLong() : a(1234567890) {}
    void print() const { cout << "a = " << a << endl; }
private:
    long a;
};

int main() {

    SomeLong x;
    x.print();

return 0;
}

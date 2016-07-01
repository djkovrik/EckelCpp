/**
Create a class containing a static double and long. Write a static member function that prints out the values.
**/

#include <iostream>

using namespace std;

class StaticMembersClass {
public:
    StaticMembersClass() {}
    static void print() { cout << d << '\n' << l << endl; }
private:
    static double d;
    static long l;
};

double StaticMembersClass::d = 2.2d;
long StaticMembersClass::l = 1000000000L;

int main() {

    StaticMembersClass s;
    s.print();

return 0;
}

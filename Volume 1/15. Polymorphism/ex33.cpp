/**
Create a class with data members and virtual functions. Write a
function that looks at the memory in an object of your class and
prints out the various pieces of it. To do this you will need to
experiment and iteratively discover where the VPTR is located in the object.
**/

#include <iostream>
#include <algorithm>

using namespace std;

class Test {
public:
    Test() : i(0), d(0), c('-') {}
    Test(int ii, double dd, char cc) : i(ii), d(dd), c(cc) {}
    virtual void f() { cout << "Test::f()" << endl; }

    int getInt() const { return i; }
    double getDouble() const { return d; }
    char getChar() const { return c; }
private:
    int i;
    double d;
    char c;
};

void dumpAndPrint(Test& t) {

    int offset_i = 0, offset_d = 0, offset_c = 0;

    size_t sz = sizeof(t);
    unsigned char* data = new unsigned char[sz];
    const char* const cPtr = reinterpret_cast<char*>(&t);

    fill(data, data + sz, 0);
    copy(cPtr, cPtr + sz, data);

    for (size_t i = 0; i < sz; i++) {

        if ( *(int*)(data + i) == t.getInt() ) {
            offset_i = i;
            cout << "Found integer! Offset: " << offset_i <<  ", value: " << *(int*)(data + offset_i) << endl;
        }

        if ( *(double*)(data + i) == t.getDouble() ) {
            offset_d = i;
            cout << "Found double! Offset: " << offset_d <<  ", value: " << *(double*)(data + offset_d) << endl;
        }

        if ( *(char*)(data + i) == t.getChar() ) {
            offset_c = i;
            cout << "Found char! Offset: " << offset_c <<  ", value: " << *(char*)(data + offset_c) << endl;
        }

    }
}

int main() {

    Test t(12345, 6.789, 'z');

    dumpAndPrint(t);

return 0;
}

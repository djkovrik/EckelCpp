/**
Modify OStackTest.cpp by creating your own class, then multiply-inheriting
it with Object to create something that can be placed into the Stack.
Test your class in main( ).
**/
#include "_OStack.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


class Int {
friend ostream& operator<< (ostream& out, const Int& s);
public:
    Int() : i(0) {}
    Int(int iii) : i(iii) {}
private:
    int i;
};

ostream& operator<< (ostream& out, const Int& i) {
    out << i.i;
    return out;
}

class MyInt: public Int, public Object {
public:
    MyInt(int i) : Int(i) {}
    ~MyInt() {
        cout << "deleting integer: " << *this << endl;
    }
};

int main() {

    Stack ints;

    for (int i = 1; i <= 5; i++)
        ints.push(new MyInt(i * 10));

    MyInt* m;
    for(int i = 0; i < 10; i++) {
        if( ( m = (MyInt*)ints.pop() )==0 ) break;
        cout << *m << endl;
        delete m;
    }
}

/**
Create a class containing a string as a data member. Initialize the string
in the constructor, but do not create a copy-constructor or operator=. Make
a second class that has a member object of your first class; do not create a
copy-constructor or operator= for this class either. Demonstrate that the
copy-constructor and operator= are properly synthesized by the compiler.
**/

#include <iostream>
#include <string>

using namespace std;

class One {
public:
    One(string s = "") : str(s) {}
    string getStr() const { return str; }
private:
    string str;
};

class Two {
public:
    Two(string str) : o(str) {}
    void print() const { cout << o.getStr() << endl; }
private:
    One o;
};

int main() {

    Two t1("first");
    Two t2(t1);

    t1.print();
    t2.print();

    Two t3("third");
    Two t4 = t3;

    t3.print();
    t4.print();

return 0;
}

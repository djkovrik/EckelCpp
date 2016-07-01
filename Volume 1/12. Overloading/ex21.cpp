/**
Create a class with an assignment operator that has a second argument,
a string that has a default value that says "op= call." Create a function
that takes assigns an object of your class to another one and show that your
assignment operator is called correctly.
**/

#include <iostream>
#include <string>

using namespace std;

class Simple {
    friend ostream& operator<<(ostream& os, const Simple& obj);
public:
    Simple(int xxx, string str = "op= call.") : x(xxx), s(str) {}

    Simple& operator= (const Simple& right) {
        if (this == &right) return *this;

        x = right.x;
        s = right.s;

        return *this;
    }
private:
    int x;
    string s;
};

ostream& operator<<(ostream& os, const Simple& obj) {
    os << obj.x << " - " << obj.s;
}

int main() {

    Simple a(10, "test"), b(20);

    cout << "a = " << a
         << "\nb = " << b << endl;

    a = b;

    cout << "a = b;"
         << "\na = " << a
         << "\nb = " << b << endl;


return 0;
}

/**
Create a class and a global friend function that manipulates the private data in the class.
**/
#include <iostream>

using namespace std;

class SomeClass {
friend void changePrivateValue (SomeClass &, int );
public:
    SomeClass() : x (123) {}
    int getX() { return x; }
private:
    int x;
};

void changePrivateValue (SomeClass &s, int y) {
    cout << "changePrivateValue ( ) called with y = " << y << endl;
    s.x = y;
}

int main() {

    SomeClass s;
    cout << "x = " << s.getX() << endl;
    changePrivateValue(s, 456);
    cout << "x = " << s.getX() << endl;

return 0;
}

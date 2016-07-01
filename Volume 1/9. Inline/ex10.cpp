/**
Create an enum called Hue containing red, blue, and yellow.
Now create a class called Color containing a data member of
type Hue and a constructor that sets the Hue from its argument.
Add access functions to "get" and "set" the Hue. Make all of
the functions inlines.
**/

#include <iostream>
#include <string>

using namespace std;

enum Hue {red = 1, blue, yellow};

class Color {
public:
    Color(Hue v = red)   { setColor(v); }
    void setColor(Hue v) { h = v; }
    Hue getColor() const { return h; }
private:
    Hue h;
};

void printColor(const Color &, const string &);

int main() {

    Color c1, c2(blue);

    printColor(c1, "c1");
    printColor(c2, "c2");

    c2.setColor(yellow);
    printColor(c2, "updated c2");

return 0;
}

void printColor(const Color &c, const string &text) {

    cout << "Current color from " << text << ": ";

    if ( 1 == c.getColor() )
        cout << "red" << endl;
    else if ( 2 == c.getColor() )
        cout << "blue" << endl;
    else
        cout << "yellow" << endl;
}

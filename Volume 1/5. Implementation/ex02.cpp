/**
Part 1:
Write a struct called Lib that contains three string objects a, b, and c.
In main( ) create a Lib object called x and assign to x.a, x.b, and x.c.
Print out the values. Now replace a, b, and c with an array of string s[3].
Show that your code in main( ) breaks as a result of the change.

Part 2:
Now create a class called Libc, with private string objects a, b, and c,
and member functions seta( ), geta( ), setb( ), getb( ), setc( ), and getc( )
to set and get the values. Write main( ) as before. Now change the
private string objects a, b, and c to a private array of string s[3].
Show that the code in main( ) does not break as a result of the change.
**/
#include <iostream>
#include <string>

using namespace std;

////// Part 1:

struct Lib {
    string a;
    string b;
    string c;

    //!if a, b, c replaced with string abc[3];
    //!we'll get an error: Lib has no member named a/b/c
};

////// Part 2:

struct Libc {
private:
    string a;
    string b;
    string c;
public:
    void seta(string str)   { a = str; }
    string geta()           { return a; }
    void setb(string str)   { b = str; }
    string getb()           { return b; }
    void setc(string str)   { c = str; }
    string getc()           { return c; }
};

// Can be replaced with:
/*
struct Libc {
private:
    string s[3];

public:
    void seta(string str)   { s[0] = str; }
    string geta()           { return s[0]; }
    void setb(string str)   { s[1] = str; }
    string getb()           { return s[1]; }
    void setc(string str)   { s[2] = str; }
    string getc()           { return s[2]; }
};
*/

int main() {

////// Part 1:

    Lib x;

    x.a = "one";
    x.b = "two";
    x.c = "three";

    cout << "x.a = " << x.a
         << "\nx.b = " << x.b
         << "\nx.c = " << x.c << endl;

////// Part 2:

    Libc y;

    y.seta("four");
    y.setb("five");
    y.setc("six");

    cout << "\ny.a = " << y.geta()
         << "\ny.b = " << y.getb()
         << "\ny.c = " << y.getc() << endl;
return 0;
}

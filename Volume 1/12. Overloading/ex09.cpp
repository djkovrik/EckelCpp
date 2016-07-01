/**
Create a class that contains a single private char. Overload the iostream
operators << and >> (as in IostreamOperatorOverloading.cpp) and test them.
You can test them with fstreams, stringstreams, and cin and cout.
**/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class MyCharClass {
    friend ostream& operator<<(ostream& os, const MyCharClass& obj);
    friend istream& operator>>(istream& is, MyCharClass& obj);
public:
    MyCharClass() : c(' ') {}
    MyCharClass(char symbol) : c(symbol) {}
private:
    char c;
};

ostream& operator<<(ostream& os, const MyCharClass& obj) {
    os << obj.c;
return os;
}

istream& operator>>(istream& is, MyCharClass& obj) {
    is >> obj.c;
return is;
}

int main() {

    MyCharClass a('z');
    MyCharClass b;

    cout << "Please type a single character: ";
    cin >> b;

    cout << "a = " << a << ", b = " << b << endl;

    stringstream s;

    s << a << b;

    cout << "stringstream = " << s.str() << endl;

    stringstream s1("y");

    MyCharClass c;

    s1 >> c;

    cout << "c = " << c << endl;

    ofstream file1;
    file1.open("ex09.txt");

    MyCharClass d('d');

    file1 << d;

    file1.close();

    MyCharClass e;

    ifstream file2;
    file2.open("ex09.txt");

    file2 >> e;

    cout << "e = " << e << endl;

return 0;
}

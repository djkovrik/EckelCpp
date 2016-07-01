/**
Write a class called Bird that contains a string member and a static int.
In the default constructor, use the int to automatically generate an identifier
that you build in the string, along with the name of the class (Bird #1, Bird #2, etc.).
Add an operator<< for ostreams to print out the Bird objects. Write an assignment
operator= and a copy-constructor. In main( ), verify that everything works correctly.
**/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Bird {
    friend ostream& operator<<(ostream& os, const Bird& obj);
public:

    Bird() {
        ostringstream ss;
        ss << "Bird#" << ++count;
        name = ss.str();

        cout << name << ": constructor called." << endl;
        countObjects();
    }

    Bird(const Bird& b) {
        name = b.name;
        ++count;
        cout << name << ": copy constructor called." << endl;
        countObjects();
    }

    ~Bird() {
        --count;
        cout << name << ": destructor called." << endl;
        countObjects();
    }

    Bird& operator=(const Bird& right) {
        cout << name << ": operator=() called." << endl;

        if (this == &right)
            return *this;

        name = right.name;
        countObjects();
    }

    void countObjects() { cout << "Bird instanses: " << count << endl; }

private:
    string name;
    static int count;
};

int Bird::count = 0;

ostream& operator<<(ostream& os, const Bird& obj) {
    os << obj.name;
}

void someFunc(Bird b) {}

int main() {

    Bird a;
    Bird b;
    Bird c;

    cout << a << ", " << b << ", " << c << endl;
    c = a;
    someFunc(b);
    cout << a << ", " << b << ", " << c << endl;
return 0;
}

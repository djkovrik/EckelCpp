/**
Write a class called BirdHouse that contains an object, a pointer and a reference
for class Bird from Exercise 14. The constructor should take the three Birds as arguments.
Add an operator<< for ostreams for BirdHouse. Disallow the assignment operator=
and a copy-constructor. In main( ), verify that everything works correctly.

Ex 14:
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

        ///cout << name << ": constructor called." << endl;
        ///countObjects();
    }

    Bird(const Bird& b) {
        name = b.name;
        ++count;
        ///cout << name << ": copy constructor called." << endl;
        ///countObjects();
    }

    ~Bird() {
        --count;
        ///cout << name << ": destructor called." << endl;
        ///countObjects();
    }

    Bird& operator=(const Bird& right) {
        ///cout << name << ": operator=() called." << endl;

        if (this == &right)
            return *this;

        name = right.name;
        ///countObjects();

        return *this;
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

class BirdHouse {
friend ostream& operator<< (ostream& out, const BirdHouse& obj);
public:
    BirdHouse(Bird a, Bird* b, Bird& c) : bObj(a), bPtr(b), bRef(c) {}

private:
    BirdHouse(const BirdHouse& r);
    BirdHouse& operator=(const BirdHouse& right);

    Bird  bObj;
    Bird* bPtr;
    Bird& bRef;
};

ostream& operator<<(ostream& out, const BirdHouse& obj) {
    out << "\nObject: " << obj.bObj
        << "\nPointer: " << *obj.bPtr
        << "\nReference: " << obj.bRef;
    return out;
}


int main() {

    Bird a;
    Bird b;
    Bird c;
    BirdHouse h(a, &b, c);

    cout << h << endl;

    c = b = a;

    cout << "\nc = b = a;\n"
         << h << endl;

return 0;
}

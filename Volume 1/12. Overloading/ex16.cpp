/**
Add an int data member to both Bird and BirdHouse in Exercise 15. Add member
operators +, -, *, and / that use the int members to perform the operations on
the respective members. Verify that these work.

Ex 15:
Write a class called BirdHouse that contains an object, a pointer and a reference
for class Bird from Exercise 14. The constructor should take the three Birds as arguments.
Add an operator<< for ostreams for BirdHouse. Write anDisallow the assignment operator=
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

    Bird() : data(0) {
        ostringstream ss;
        ss << "Bird#" << ++count;
        name = ss.str();
        ///cout << name << "(" << data << ") created." << endl;
    }

    Bird(int x) : data(x) {
        ostringstream ss;
        ss << "Bird#" << ++count;
        name = ss.str();

        ///cout << name << "(" << data << ") created." << endl;
    }

    Bird(const Bird& b) {
        name = b.name;
        data = b.data;
        ++count;
    }

    ~Bird() { --count; }

    Bird& operator=(const Bird& right) {

        if (this == &right)
            return *this;

        name = right.name;
        return *this;
    }

    const Bird operator+(const Bird& right) const { return Bird(data + right.data); }
    const Bird operator-(const Bird& right) const { return Bird(data - right.data); }
    const Bird operator*(const Bird& right) const { return Bird(data * right.data); }
    const Bird operator/(const Bird& right) const { return Bird(data / right.data); }

private:
    string name;
    static int count;
    int data;
};

int Bird::count = 0;

ostream& operator<<(ostream& os, const Bird& obj) {
    os << obj.name << "(" << obj.data << ")";
}

class BirdHouse {
friend ostream& operator<< (ostream& out, const BirdHouse& obj);
public:
    BirdHouse(Bird a, Bird* b, Bird& c, int x = 0) : bObj(a), bPtr(b), bRef(c) {}

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

    Bird a(2);
    Bird b(3);
    Bird c(6);

    Bird d = a + b;
    Bird e = c - a;
    Bird f = b * c / a;

    BirdHouse h1(a, &b, c);
    BirdHouse h2(d, &e, f);

    cout << h1 << endl;
    cout << h2 << endl;


return 0;
}

/**
In CopyingWithPointers.cpp, remove the operator= in DogHouse and show that the
compiler-synthesized operator= correctly copies the string but simply aliases the Dog pointer.
**/

#include <string>
#include <iostream>
using namespace std;

class Dog {
    string nm;
public:
    Dog(const string& name) : nm(name) {
        cout << "Creating Dog: " << *this << endl;
  }
  // Synthesized copy-constructor & operator=
  // are correct.
  // Create a Dog from a Dog pointer:
    Dog(const Dog* dp, const string& msg)
        : nm(dp->nm + msg) {
        cout << "Copied dog " << *this << " from "
             << *dp << endl;
    }

    ~Dog() {
        cout << "Deleting Dog: " << *this << endl;
    }

    void rename(const string& newName) {
        nm = newName;
    cout << "Dog renamed to: " << *this << endl;
    }

friend ostream& operator<<(ostream& os, const Dog& d) {
        return os << "[" << d.nm << "]";
    }

void bark() { cout << "My name is " << nm << ", my adress is " << this << endl; }
};

class DogHouse {
    Dog* p;
    string houseName;
public:

DogHouse(Dog* dog, const string& house) : p(dog), houseName(house) {}

DogHouse(const DogHouse& dh) : p(new Dog(dh.p, " copy-constructed")), houseName(dh.houseName + " copy-constructed") {}

/**
DogHouse& operator=(const DogHouse& dh) {
// Check for self-assignment:
    if(&dh != this) {
        p = new Dog(dh.p, " assigned");
        houseName = dh.houseName + " assigned";
    }
    return *this;
  }
**/
void renameHouse(const string& newName) {
    houseName = newName;
}

Dog* getDog() const { return p; }

~DogHouse() { delete p; }

friend ostream& operator<<(ostream& os, const DogHouse& dh) {
    return os << "[" << dh.houseName
        << "] contains " << *dh.p;
  }
};

int main() {

    Dog d1("Fido"), d2("Max");

    d1.bark();
    d2.bark();

    d2 = d1;

    d1.bark();
    d2.bark();
}

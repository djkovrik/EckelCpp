/**
Repeat Exercise 5 using a PStash.

Ex 5:
Repeat Exercise 4, but add a member function f( ) to Counted that
prints a message. Move through the vector and call f( ) for each object.

Ex 4:
Create a vector< Counted*> and fill it with pointers to new Counted
objects (from Exercise 1). Move through the vector and print the
Counted objects, then move through again and delete each one.

Ex 1:
Create a class Counted that contains an int id and a static int count.
The default constructor should begin:
Counted( ) : id(count++) {.
It should also print its id and that it’s being created. The destructor
should print that it’s being destroyed and its id. Test your class.
**/

#include <iostream>
#include "PStash.h"

using namespace std;

class Counted {
friend ostream& operator<< (ostream& out, const Counted& o);
public:
    Counted() : id(count++) { cout << "+++ Counted created, id: " << id << endl; }
    void f()   { cout << "f() called, id: " << id << endl; }
    ~Counted() { cout << "--- Counted destroyed, id: " << id << endl; }
private:
    int id;
    static int count;
};

int Counted::count = 0;

ostream& operator<< (ostream& out, const Counted& o) {
    out << o.id;
    return out;
}

int main() {

    PStash countedStash;

    /// Filling PStash
    for (int i = 0; i < 10; i++)
        countedStash.add(new Counted);

    cout << "\nStash created, elements: " << countedStash.count() << endl;

    /// Printing PStash
    for (int i = 0; i < countedStash.count(); i++)
        cout << *((Counted*)countedStash[i]) << ' ';

    cout << "\nFunction calls... " << endl;

    /// f() calls...
    for (int i = 0; i < countedStash.count(); i++)
        ((Counted*)countedStash[i])->f();


    cout << "\n\nDestroying... " << endl;

    /// Deleting
    for (int i = 0; i < countedStash.count(); i++)
        delete (Counted*) countedStash.remove(i);

return 0;
}

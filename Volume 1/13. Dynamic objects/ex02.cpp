/**
Prove to yourself that new and delete always call the constructors and
destructors by creating an object of class Counted (from Exercise 1)
with new and destroying it with delete. Also create and destroy an array
of these objects on the heap.

Ex 1:
Create a class Counted that contains an int id and a static int count.
The default constructor should begin:
Counted( ) : id(count++) {.
It should also print its id and that it’s being created. The destructor
should print that it’s being destroyed and its id. Test your class.
**/

#include <iostream>

using namespace std;

class Counted {
public:
    Counted() : id(count++) { cout << "+++ Counted created, id: " << id << endl; }
    ~Counted() { cout << "--- Counted destroyed, id: " << id << endl; }
private:
    int id;
    static int count;
};

int Counted::count = 0;

int main() {

    Counted* cPtr = new Counted;
    Counted* const array_ptr = new Counted[5];

    delete []array_ptr;
    delete cPtr;
return 0;
}

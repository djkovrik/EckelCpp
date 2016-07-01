/**
Dynamically create an array of objects of class Counted (from Exercise 1).
Call delete for the resulting pointer, without the square brackets.
Explain the results.

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

    Counted* array_ptr = new Counted[5];
    delete array_ptr;

return 0;
}

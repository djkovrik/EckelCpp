/**
Create a PStash object and fill it with new objects from Exercise 1.
Observe what happens when this PStash object goes out of scope and
its destructor is called.

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
public:
    Counted() : id(count++) { cout << "+++ Counted created, id: " << id << endl; }
    ~Counted() { cout << "--- Counted destroyed, id: " << id << endl; }
private:
    int id;
    static int count;
};

int Counted::count = 0;

int main() {

    PStash countedStash;


    for(int i = 0; i < 10; i++)
        countedStash.add(new Counted);

    for(int j = 0; j < countedStash.count(); j++)
        cout << "countedStash[" << j << "] created." << endl;

    cout << "Stash filled sucessfully." << endl;

    for(int k = 0; k < countedStash.count(); k++)
        delete (Counted*)countedStash.remove(k);

return 0;
}

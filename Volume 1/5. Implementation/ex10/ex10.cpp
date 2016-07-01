/**
Place objects of the Hen class from Exercise 6 in a Stash. Fetch them out and print them
(if you have not already done so, you will need to add Hen::print( )).
**/
#include <iostream>
#include "Stash.h"

using namespace std;

class Nest {
public:
    Nest() {}
    void display() {cout << "display() from Nest" << endl; }

    class Hen {
    public:
        Hen(){}
        void display() {cout << "display() from Hen" << endl; }
        void print() {cout << "print() from Hen" << endl; }

        class Egg {
        public:
            Egg() {}
            void display() {cout << "display() from Egg" << endl; }
        };

    };

};

int main() {

    Stash henStash;
    henStash.initialize(sizeof(Nest::Hen));

    Nest::Hen *aPtr = new Nest::Hen;
    Nest::Hen *bPtr = new Nest::Hen;
    Nest::Hen *cPtr = new Nest::Hen;

    henStash.add(aPtr);
    henStash.add(bPtr);
    henStash.add(cPtr);

    size_t count = henStash.count();

    for (size_t i = 0; i < count; i++) {
        Nest::Hen *tempPtr = (Nest::Hen*)henStash.fetch(i);
        tempPtr->print();
        delete tempPtr;
    }

return 0;
}

/**
Place objects of the Hen class from Exercise 6 in a Stack. Fetch them out and print them
(if you have not already done so, you will need to add Hen::print( )).
**/
#include <iostream>
#include "Stack.h"

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

    Stack henStack;
    henStack.initialize();

    Nest::Hen *aPtr = new Nest::Hen;
    Nest::Hen *bPtr = new Nest::Hen;
    Nest::Hen *cPtr = new Nest::Hen;

    henStack.push(aPtr);
    henStack.push(bPtr);
    henStack.push(cPtr);

    Nest::Hen *tempPtr = (Nest::Hen*)henStack.pop();

    while ( tempPtr != 0 ) {
        tempPtr->print();
        delete tempPtr;
        tempPtr = (Nest::Hen*)henStack.pop();
    }

return 0;
}

/**
Create a class called SpaceShip with a fly( ) method. Inherit Shuttle from
SpaceShip and add a land( ) method. Create a new Shuttle, upcast by pointer
or reference to a SpaceShip, and try to call the land( ) method.
Explain the results.
**/

#include <iostream>

using namespace std;

class SpaceShip {
public:
    void fly() { cout << "SpaceShip::fly()" << endl; }
};

class Shuttle : public SpaceShip {
public:
    void land() { cout << "Shuttle::land()" << endl; }
};

int main() {

    Shuttle sh;
    SpaceShip* sPtr = &sh;

    sPtr->fly();
    //sPtr->land();
    //!error: 'class SpaceShip' has no member named 'land'|

return 0;
}

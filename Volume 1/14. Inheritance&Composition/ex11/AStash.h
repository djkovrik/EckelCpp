#ifndef ASTASH_H_INCLUDED
#define ASTASH_H_INCLUDED


#include "PStash.h"

class Asteroid {
public:
    Asteroid() : data(0) {}
    Asteroid(int a) : data(a) {}
private:
    int data;
};

class AStash : public PStash {
public:
    AStash() : PStash() {}
    int add(Asteroid* element) { return PStash::add( static_cast<void*>(element) ); }
    Asteroid* operator[](int i) const { return static_cast<Asteroid*> ( PStash::operator[](i) ); }
    Asteroid* remove(int i) { return static_cast<Asteroid*> ( PStash::remove(i) ); }
};

/** - PStash like a member object
class AStash {
public:
    AStash() : p() {}
    int add(Asteroid* element) { return p.add( static_cast<void*>(element) ); }
    Asteroid* operator[](int i) const { return static_cast<Asteroid*> ( p.operator[](i) ); }
    Asteroid* remove(int i) { return static_cast<Asteroid*> ( p.remove(i) ); }
    int count() const { return p.count(); }
private:
    PStash p;
};
**/

#endif // ASTASH_H_INCLUDED

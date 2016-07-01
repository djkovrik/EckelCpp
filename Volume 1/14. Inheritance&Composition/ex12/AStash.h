#ifndef ASTASH_H_INCLUDED
#define ASTASH_H_INCLUDED


#include <vector>

class Asteroid {
public:
    Asteroid() : data(0) {}
    Asteroid(int a) : data(a) {}
private:
    int data;
};

class AStash : public std::vector<Asteroid*> {
public:
    AStash() : vector() {}
    void add(Asteroid* element) { vector::push_back(element); }
    Asteroid* operator[](int i) const { return vector::operator[](i); }
    void remove() { vector::pop_back(); }
    int count() const { return vector::size(); }
};

/** - vector like a member object
class AStash {
public:
    AStash() : va() {}
    void add(Asteroid* element) { va.push_back(element); }
    Asteroid* operator[](int i) const { return va.operator[](i); }
    void remove() { va.pop_back(); }
    int count() const { return va.size(); }
private:
    std::vector<Asteroid*> va;
};
**/

#endif // ASTASH_H_INCLUDED

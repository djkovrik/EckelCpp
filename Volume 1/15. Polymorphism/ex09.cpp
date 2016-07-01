/**
Starting with the previous Rodent hierarchy, add a non virtual destructor,
create an object of class Hamster using new, upcast the pointer to a Rodent*,
and delete the pointer to show that it doesn’t call all the destructors in the
hierarchy. Change the destructor to be virtual and demonstrate that the
behavior is now correct.

Ex 6:
Create an inheritance hierarchy of Rodent: Mouse, Gerbil, Hamster, etc.
In the base class, provide methods that are common to all Rodents,
and redefine these in the derived classes to perform different
behaviors depending on the specific type of Rodent. Create an
array of pointers to Rodent, fill it with different specific
types of Rodents, and call your base-class methods to see what happens.
**/

#include <iostream>
#include <vector>

using namespace std;

class Rodent {
public:
    virtual void speak() { cout << "Rodent::speak()" << endl; }
    virtual void eat() { cout << "Rodent::eat()" << endl; }
    virtual void sleep() { cout << "Rodent::sleep()" << endl; }
    //virtual
    ~Rodent() { cout << "~Rodent()" << endl; }
};

class Mouse : public Rodent {
public:
    void speak() { cout << "Mouse::speak()" << endl; }
    void eat() { cout << "Mouse::eat()" << endl; }
    void sleep() { cout << "Mouse::sleep()" << endl; }
    ~Mouse() { cout << "~Mouse()" << endl; }
};

class Gerbil : public Rodent {
public:
    void speak() { cout << "Gerbil::speak()" << endl; }
    void eat() { cout << "Gerbil::eat()" << endl; }
    void sleep() { cout << "Gerbil::sleep()" << endl; }
    ~Gerbil() { cout << "~Gerbil()" << endl; }
};

class Hamster : public Rodent {
public:
    void speak() { cout << "Hamster::speak()" << endl; }
    void eat() { cout << "Hamster::eat()" << endl; }
    void sleep() { cout << "Hamster::sleep()" << endl; }
    ~Hamster() { cout << "~Hamster()" << endl; }
};

int main() {

    Rodent* r = new Hamster;

    delete r;

return 0;
}

/**
Create an inheritance hierarchy of Rodent: Mouse, Gerbil, Hamster, etc.
In the base class, provide methods that are common to all Rodents,
and redefine these in the derived classes to perform different
behaviors depending on the specific type of Rodent. Create an
array of pointers to Rodent, fill it with different specific
types of Rodents, and call your base-class methods to see what happens.
**/

#include <iostream>

using namespace std;

class Rodent {
public:
    virtual void speak() { cout << "Rodent::speak()" << endl; }
    virtual void eat() { cout << "Rodent::eat()" << endl; }
    virtual void sleep() { cout << "Rodent::sleep()" << endl; }
};

class Mouse : public Rodent {
public:
    void speak() { cout << "Mouse::speak()" << endl; }
    void eat() { cout << "Mouse::eat()" << endl; }
    void sleep() { cout << "Mouse::sleep()" << endl; }
};

class Gerbil : public Rodent {
public:
    void speak() { cout << "Gerbil::speak()" << endl; }
    void eat() { cout << "Gerbil::eat()" << endl; }
    void sleep() { cout << "Gerbil::sleep()" << endl; }
};

class Hamster : public Rodent {
public:
    void speak() { cout << "Hamster::speak()" << endl; }
    void eat() { cout << "Hamster::eat()" << endl; }
    void sleep() { cout << "Hamster::sleep()" << endl; }
};

int main() {

    Rodent* r[] = {new Mouse, new Gerbil, new Hamster};

    for (size_t i = 0; i < sizeof(r) / sizeof(*r); i++) {
        r[i]->speak();
        r[i]->eat();
        r[i]->sleep();
    }

    /** WE HAVE TO DELETE POINTERS! **/
return 0;
}

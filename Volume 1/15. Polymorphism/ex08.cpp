/**
Starting with the previous Rodent hierarchy, inherit BlueHamster from
Hamster (yes, there is such a thing; I had one when I was a kid),
override the base-class methods, and show that the code that calls
the base-class methods doesn’t need to change in order to accommodate the new type.

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
    virtual ~Rodent() { cout << "~Rodent()" << endl; }
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

class BlueHamster : public Hamster {
public:
    void speak() { cout << "BlueHamster::speak()" << endl; }
    ~BlueHamster() { cout << "~BlueHamster()" << endl; }
};

int main() {

    Rodent* r = new BlueHamster;

    r->speak();
    r->eat();
    r->sleep();

    delete r;

return 0;
}

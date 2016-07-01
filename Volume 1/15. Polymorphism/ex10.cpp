/**
Starting with the previous Rodent hierarchy, modify Rodent so it is a pure abstract base class.

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
    virtual void speak() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual ~Rodent() = 0;
};

Rodent::~Rodent() { cout << "~Rodent()" << endl; }

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

    vector<Rodent*> r;
    r.push_back(new Mouse);
    r.push_back(new Gerbil);
    r.push_back(new Hamster);

    for (size_t i = 0; i < r.size(); i++) {
        r[i]->speak();
        r[i]->eat();
        r[i]->sleep();
    }

    Rodent* temp;

    while ( !r.empty() ) {
        temp = r.back();
        r.pop_back();
        delete temp;
    }

return 0;
}

/**
Create an air-traffic control system with base-class Aircraft and
various derived types. Create a Tower class with a vector<Aircraft*>
that sends the appropriate messages to the various aircraft under its control.
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aircraft {
public:
    Aircraft() : flight("00000") { cout << "+ Base Aircraft(" << flight << ") created." << endl; }
    Aircraft(string str) : flight(str) { cout << "+ Base Aircraft(" << flight << ") created." << endl; }

    string getFlight() const { return flight; }

    virtual void fly() = 0;
    virtual void land() = 0;
    virtual void introduce() = 0;
    virtual ~Aircraft() = 0;
private:
    string flight;
};

Aircraft::~Aircraft() { cout << "- Aircraft(" << getFlight() << ") deleted." << endl; }


class Boeing : public Aircraft {
public:
    Boeing(string str) : Aircraft(str) { cout << "+++ Boeing(" << getFlight() << ") created." << endl; }

    void fly() { cout << "~~~ Boeing(" << getFlight() << ") flies!" << endl; }
    void land() { cout << "~~~ Boeing(" << getFlight() << ") lands!" << endl; }
    void introduce() { cout << "~~~ I am Boeing(" << getFlight() << ")." << endl; }

    ~Boeing() { cout << "--- Boeing(" << getFlight() << ") deleted." << endl; }
};

class Airbus : public Aircraft {
public:
    Airbus(string str) : Aircraft(str) { cout << "+++ Airbus(" << getFlight() << ") created." << endl; }

    void fly() { cout << "~~~ Airbus(" << getFlight() << ") flies!" << endl; }
    void land() { cout << "~~~ Airbus(" << getFlight() << ") lands!" << endl; }
    void introduce() { cout << "~~~ I am Airbus(" << getFlight() << ")." << endl; }

    ~Airbus() { cout << "--- Airbus(" << getFlight() << ") deleted." << endl; }
};


class Tower {
public:
    Tower() : controler() {}
    void add_plane(Aircraft* ptr) {
        controler.push_back(ptr);
        cout << "!Tower: flight " << ptr->getFlight() << " has been added. " << endl;
    }

    void release_plane() {
        Aircraft* temp = controler.back();
        controler.pop_back();
        cout << "!Tower: flight " << temp->getFlight() << " has been released. " << endl;
        delete temp;
    }

    void ping_planes() const {
        cout << "!Tower: checking current flights... " << endl;
        for (size_t i = 0; i < controler.size(); i++)
            controler[i]->introduce();
    }

    Aircraft* operator[](size_t index) { return controler[index]; }

    size_t size() const { return controler.size(); }

    ~Tower() {
        if (size() != 0 )
            cout << "VECTOR IS NOT EMPTY!!!" << endl;
        else
            controler.clear();
    }

private:
    vector<Aircraft*> controler;
};



int main() {

    Tower t;

    t.add_plane( new Boeing("B3461") );
    t.add_plane( new Boeing("B9012") );
    t.add_plane( new Airbus("A2215") );

    t.ping_planes();

    for (size_t i = 0; i < t.size(); i++)
        t[i]->fly();

    t[1]->land();

    t.release_plane();
    t.release_plane();
    t.release_plane();

return 0;
}

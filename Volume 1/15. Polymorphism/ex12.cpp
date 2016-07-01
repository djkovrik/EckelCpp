/**
Create a model of a greenhouse by inheriting various types of Plant
and building mechanisms into your greenhouse that take care of the plants.
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Plant {
public:
    Plant(string n) : name(n) { cout << '\t' << getName() << " has been planted!" << endl; }
    string getName() const { return name; }

    virtual void fertilise() = 0;
    virtual void watering() = 0;
    virtual ~Plant() { cout << '\t' << getName() << " has been harvested." << endl; }
private:
    string name;
};

class Cucumber : public Plant {
public:
    Cucumber(string str) : Plant(str) {}
    void fertilise() { cout << "\tCucumber fertilising: " << getName() <<  endl;  }
    void watering() { cout << "\tCucumber watering: " << getName() <<  endl;  }
    ~Cucumber() { cout << "\tCucumber harvesting: " << getName() << endl; }
};

class Tomato : public Plant {
public:
    Tomato(string str) : Plant(str) {}
    void fertilise() { cout << "\tTomato fertilising: " << getName() <<  endl;  }
    void watering() { cout << "\tTomato watering: " << getName() <<  endl;  }
    ~Tomato() { cout << "\tTomato harvesting: " << getName() << endl; }
};

class GreenHose {
public:
    GreenHose() : garden() { cout << "+ GreenHouse created +" << endl; }

    void add(Plant* p) { garden.push_back(p); }

    void feed() {
        cout << "GreenHose: feeding..." << endl;
        for (size_t i = 0; i < garden.size(); i++)
            garden[i]->fertilise();
    }

    void water() {
        cout << "GreenHose: watering..." << endl;
        for (size_t i = 0; i < garden.size(); i++)
            garden[i]->watering();
    }

    void harvest() {
        cout << "GreenHose: harvesting..." << endl;

        Plant* temp;
        while ( !garden.empty() ) {
            temp = garden.back();
            garden.pop_back();
            delete temp;
        }
    }

     ~GreenHose() {
        if ( !garden.empty() )
            cout << "VECTOR IS NOT EMPTY!!!" << endl;
        else
            garden.clear();
    }

private:
    vector<Plant*> garden;
};

int main() {

    GreenHose g;

    g.add( new Cucumber("Tasty cucumber") );
    g.add( new Cucumber("Big cucumber") );
    g.add( new Tomato("Nasty tomato") );

    g.water();
    g.feed();
    g.harvest();

return 0;
}

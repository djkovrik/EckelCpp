/**
Create two classes called Traveler and Pager without default constructors,
but with constructors that take an argument of type string, which they simply
copy to an internal string variable. For each class, write the correct
copy-constructor and assignment operator. Now inherit a class BusinessTraveler
from Traveler and give it a member object of type Pager. Write the correct
default constructor, a constructor that takes a string argument, a copy-constructor,
and an assignment operator.
**/

#include <iostream>
#include <string>

using namespace std;

class Traveler {
public:
    Traveler(string str) : t(str) { cout << "Traveler(string)" << endl; }
    Traveler(const Traveler& right) : t(right.t) { cout << "Traveler(const Traveler&)" << endl; }
    Traveler& operator=(const Traveler& right) { cout << "Traveler& operator=" << endl; t = right.t; return *this; }
private:
    string t;
};

class Pager {
public:
    Pager(string str) : p(str) { cout << "Pager(string)" << endl; }
    Pager(const Pager& right) : p(right.p) { cout << "Pager(const Pager&)" << endl; }
    Pager& operator=(const Pager& right) { cout << "Pager& operator=" << endl; p = right.p; return *this; }
private:
    string p;
};

class BusinessTraveler : public Traveler {
public:
    BusinessTraveler() : Traveler("John"), device("my_pager") { cout << "BusinessTraveler()" << endl; }
    BusinessTraveler(string name, string ppp) : Traveler(name), device(ppp) { cout << "BusinessTraveler(string, string)" << endl; }

    BusinessTraveler(const BusinessTraveler& right) : Traveler(right), device(right.device) {
        cout << "BusinessTraveler(const BusinessTraveler& )" << endl;
    }

    BusinessTraveler& operator=(const BusinessTraveler& right) {
        cout << "BusinessTraveler& operator=" << endl;
        Traveler::operator=(right);
        device = right.device;
        return *this;
    }

private:
    Pager device;
};

int main() {

    BusinessTraveler t1;
    BusinessTraveler t2("James Bond", "007");
    BusinessTraveler t3 = t2;

    t1 = t3;

return 0;
}

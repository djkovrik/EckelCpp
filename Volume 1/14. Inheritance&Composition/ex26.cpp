/**
Create a class Rock with a default constructor, a copy-constructor,
an assignment operator, and a destructor, all of which announce to
cout that they’ve been called. In main( ), create a vector<Rock>
(that is, hold Rock objects by value) and add some Rocks. Run the
program and explain the output you get. Note whether the destructors
are called for the Rock objects in the vector. Now repeat the exercise
with a vector<Rock*>. Is it possible to create a vector<Rock&>?
**/

#include <iostream>
#include <vector>

using namespace std;

class Rock {
public:
    Rock() { cout << "Rock()" << endl; }

    Rock(const Rock& r) { cout << "Rock(const Rock&)" << endl; }

    Rock& operator=(const Rock& r) {
        cout << "Rock::operator=" << endl;
        return *this;
    }

    ~Rock() { cout << "~Rock()" << endl; }
};

void v() {

    cout << "Creating values vector..." << endl;

    vector<Rock> values;
    Rock r1, r2;

    values.push_back(r1);
    values.push_back(r2);
    cout << "Values vector created." << endl;
}

void p() {
    cout << "\nCreating pointers vector..." << endl;

    vector<Rock*> pointers;

    pointers.push_back(new Rock);

    cout << "Pointers vector created." << endl;
}

int main() {

    v();
    p();

//!error: forming pointer to reference type 'Rock&'|
/*
    Rock r1;
    vector<Rock&> refs;
    refs.push_back(r1);
*/
return 0;
}

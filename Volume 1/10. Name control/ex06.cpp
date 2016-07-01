/**
Make a global object of Monitor2 and see what happens.

Exercise 5:
Modify the Monitor class from Exercise 4 so that you can decrement( ) the incident count.
Make a class Monitor2 that takes as a constructor argument a pointer to a Monitor1,
and which stores that pointer and calls incident( ) and print( ).
In the destructor for Monitor2, call decrement( ) and print( ).
Now make a static object of Monitor2 inside a function.
Inside main( ), experiment with calling the function and not calling the function to see
what happens with the destructor of Monitor2.

Exercise 4:
Create a class called Monitor that keeps track of the number of times that
its incident( ) member function has been called. Add a print( ) member
function that displays the number of incidents. Now create a global
function (not a member function) containing a static Monitor object.
Each time you call the function it should call incident( ), then print( )
member function to display the incident count. Exercise the function in main( ).
**/

#include <iostream>

using namespace std;

class Monitor1 {
public:
    Monitor1()        { cout << "Monitor1() call..." << endl; }
    ~Monitor1()       { cout << "~Monitor1() call..." << endl; }
    void incident()   { ++count; }
    void decrement()  { --count; }
    void print()      { cout << "Incidents: " << count << endl; }
private:
    static int count;
};

int Monitor1::count = 0;

class Monitor2 {
public:
    Monitor2() : mPtr(new Monitor1) {}

    Monitor2(Monitor1* m) : mPtr(m) {
        cout << "Monitor2(Monitor1& ) call..." << endl;
        mPtr->incident();
        mPtr->print();
    }

    ~Monitor2() {
        cout << "~Monitor2() call..." << endl;
        mPtr->decrement();
        mPtr->print();
    }
private:
    Monitor1* mPtr;
};

void globalFunc() {

    static Monitor1 m1;

    m1.incident();
    m1.print();

    static Monitor2 m2(&m1);
}

Monitor2 m2;

int main() {

    //globalFunc();

return 0;
}

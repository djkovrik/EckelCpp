/**
Create a class called Monitor that keeps track of the number of times that
its incident( ) member function has been called. Add a print( ) member
function that displays the number of incidents. Now create a global
function (not a member function) containing a static Monitor object.
Each time you call the function it should call incident( ), then print( )
member function to display the incident count. Exercise the function in main( ).
**/

#include <iostream>

using namespace std;

class Monitor {
public:
    Monitor(){}
    void incident() { ++count; }
    void print()    { cout << "Incidents: " << count << endl; }
private:
    static int count;
};

int Monitor::count = 0;

void globalFunc() {

    static Monitor m;

    m.incident();
    m.print();
}

int main() {

    globalFunc();
    globalFunc();
    globalFunc();

return 0;
}

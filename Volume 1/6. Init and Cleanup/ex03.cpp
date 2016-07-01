/**
Ex 1:
Write a simple class called Simple with a constructor that prints
something to tell you that it's been called.
In main( ) make an object of your class.

Ex 2:
Add a destructor to Exercise 1 that prints out a message to tell you that it's been called.

Ex 3:
Modify Exercise 2 so that the class contains an int member. Modify the
constructor so that it takes an int argument that it stores in the class member.
Both the constructor and destructor should print out the int value as part of
their message, so you can see the objects as they are created and destroyed.
**/
#include <iostream>

using namespace std;

class Simple {
public:
    Simple(int n) : x(n) { cout << "Simple(" << x << ") called." << endl; }
    ~Simple() { cout << "~Simple(" << x << ") called." << endl; }
private:
    int x;
};

int main() {

    Simple a(1);
    Simple b(2);

return 0;
}

/**
Write a simple class called Simple with a constructor that prints
something to tell you that it's been called.
In main( ) make an object of your class.
**/
#include <iostream>

using namespace std;

class Simple {
public:
    Simple() { cout << "Simple() called." << endl; }
};

int main() {

    Simple s;

return 0;
}

/**
Create a function with two arguments and call it from main( ).
Now make one of the arguments a "placeholder" (no identifier)
and see if your call in main( ) changes.
**/

#include <iostream>

using namespace std;

void testFunction(int , double );

int main() {

    testFunction(1, 2.2);

return 0;
}

//void testFunction(int a, double b) {
void testFunction(int a, double ) {
    cout << "testFunction called." << endl;
}

/**
Repeat Exercise 11 with a vector instead of a PStash.

Ex 11:
Create a class called Asteroid. Use inheritance to specialize the PStash
class in Chapter 13 (PStash.h & PStash.cpp) so that it accepts and returns
Asteroid pointers. Also modify PStashTest.cpp to test your classes.
Change the class so PStash is a member object.
**/
#include "AStash.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    AStash AsteroidStash;

    for(int i = 0; i < 5; i++)
        AsteroidStash.add(new Asteroid(i));

    for(int j = 0; j < AsteroidStash.count(); j++)
        cout << "AsteroidStash[" << j << "] = "
             << *((int*)AsteroidStash[j]) << endl;

    for(int k = 0; k < AsteroidStash.count(); k++)
        AsteroidStash.remove();

return 0;
}

/**
Modify YourPets2.cpp so that it uses various different data types
(char, int, float, double, and their variants). Run the program
and create a map of the resulting memory layout
**/

#include <iostream>
using namespace std;

char dog;
int cat;
float bird;
double fish;

void f(int pet) {
  cout << "pet id number: " << pet << endl;
}

int main() {
  long int i;
  short int j;
  long double k;
  cout << "f(): " << (long)&f << endl;
  cout << "dog: " << (long)&dog << endl;
  cout << "cat: " << (long)&cat << endl;
  cout << "bird: " << (long)&bird << endl;
  cout << "fish: " << (long)&fish << endl;
  cout << "i: " << (long)&i << endl;
  cout << "j: " << (long)&j << endl;
  cout << "k: " << (long)&k << endl;
}

/**
Modify TPStash.h so that the increment value used by inflate( )
automatically resizes itself to reduce the number of times it
needs to be called. For example, each time it is called it could
double the increment value for use in the next call. Demonstrate
this functionality by reporting whenever an inflate( ) is called,
and write test code in main( ).
**/

#include "TPStash.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream in("TPStashTest.cpp");
  PStash<string> stringStash;
  string line;
  while(getline(in, line))
    stringStash.add(new string(line));
  // Print out the strings:
  for(int u = 0; stringStash[u]; u++)
    cout << "stringStash[" << u << "] = "
         << *stringStash[u] << endl;
} ///:~

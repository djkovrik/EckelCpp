/**
Write a program that uses the IFOPEN( ) macro to open a file as an input stream. Note the creation of the ifstream object and its scope.
**/

#include <iostream>
#include "require.h"

#define IFOPEN(VAR, NAME) \
  ifstream VAR(NAME); \
  assure(VAR, NAME);

using namespace std;

int main(int argc, char* argv[]) {

    IFOPEN(in, argv[1]);

return 0;
}

/**
Create two new programs starting from ArgsToInts.cpp so they use atol( ) and atof( ), respectively.
**/
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  for(int i = 1; i < argc; i++)
    cout << atoi(argv[i]) << " " << atol(argv[i]) << " " << atof(argv[i]) << endl;

return 0;
}

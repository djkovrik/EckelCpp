/**
Write a program that takes two command-line arguments: the first is an int
and the second is a file name. Use require.h to ensure that you have the
right number of arguments, that the int is between 5 and 10, and that the
file can successfully be opened.
**/

#include <iostream>
#include "require.h"

using namespace std;

int main(int argc, char* argv[]) {

    requireArgs(argc, 2);
    require(atoi(argv[1]) >=5 && atoi(argv[1]) <= 10, "int value must be between 5 and 10");

    ifstream in(argv[2]);
    assure(in, argv[2]);


return 0;
}

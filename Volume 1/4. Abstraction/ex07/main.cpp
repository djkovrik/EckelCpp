/**
Make a Stash that holds doubles. Fill it with 25 double values,
then print them out to the console.
**/

#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include "CLib.h"

using namespace std;

int main() {

	CStash doubleStash;
	int i;
	char* cp;
	ifstream in;
	string line;
	const int bufsize = 80;

	initialize(&doubleStash, sizeof(double));

	for(i = 0; i < 100; i++) {
        double d = i + 1;
		add(&doubleStash, &d);
	}

	for(i = 0; i < count(&doubleStash); i++)
		cout << "fetch(&doubleStash, " << i << ") = "
				 << *(double*)fetch(&doubleStash, i)
				 << endl;

	cleanup(&doubleStash);

return 0;
}

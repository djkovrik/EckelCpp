/**
Modify Exercise 22 so that you create a struct that encapsulates the
Stack of Stashes. The user should only add and get lines via member
functions, but under the covers the struct happens to use a Stack of Stashes.
**/

#include "External.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printStash(Stash *s);

int main() {

	ExternalStruct e;

	const int bufsize = 200;
	ifstream in("main.cpp");
	string line;
	int counter = 0;

	Stash *stashPtr = new Stash;
	stashPtr->initialize(sizeof(char) * bufsize);

	while(getline(in, line)) {
        stashPtr->add(line.c_str());
        counter++;

        if (counter % 5 == 0) {
            e.add_stash(stashPtr);
            stashPtr = new Stash;
            stashPtr->initialize(sizeof(char) * bufsize);
        }
	}

    // Adds remainig lines
    e.add_stash(stashPtr);

	Stash *sPointer = 0;

	e.reverse();

	while((sPointer = (Stash*)e.remove_stash()) != 0) {
		printStash(sPointer);
		delete sPointer;
	}

return 0;
}

void printStash(Stash *s) {
    int k = 0;
    char* cp;
    while((cp =(char*)s->fetch(k++)) != 0)
        cout << cp << endl;
}

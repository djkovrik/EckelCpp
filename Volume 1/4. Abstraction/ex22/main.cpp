/**
Create a Stack that holds Stashes. Each Stash will hold five lines from an
input file. Create the Stashes using new. Read a file into your Stack, then
reprint it in its original form by extracting it from the Stack.
**/

#include "Stack.h"
#include "Stash.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printStash(Stash *s);

int main() {

	Stack stashStack;
    stashStack.initialize();

    Stack reverseStack;
    reverseStack.initialize();

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
            stashStack.push(stashPtr);
            stashPtr = new Stash;
            stashPtr->initialize(sizeof(char) * bufsize);
        }
	}

    // Adds remainig lines
    stashStack.push(stashPtr);

	Stash *sPointer = 0;

	while((sPointer = (Stash*)stashStack.pop()) != 0)
		reverseStack.push(sPointer);

	while((sPointer = (Stash*)reverseStack.pop()) != 0) {
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

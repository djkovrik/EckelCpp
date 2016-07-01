/**
Modify Stash to use a vector<char> as its underlying data structure.
**/

#include "CLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {

	CStash intStash, stringStash;
	int i;
	char* cp;
	ifstream in;
	string line;
	const int bufsize = 80;

	initialize(&intStash, sizeof(int));
	for(i = 0; i < 100; i++)
		add(&intStash, &i);
	for(i = 0; i < count(&intStash); i++)
		cout << "fetch(&intStash, " << i << ") = "
				 << *(int*)fetch(&intStash, i)
				 << endl;
	// Holds 80-character strings:
	initialize(&stringStash, sizeof(char)*bufsize);
	in.open("CLibTest.cpp");
	assert(in);
	while(getline(in, line))
		add(&stringStash, line.c_str());
	i = 0;
	while((cp = (char*)fetch(&stringStash,i++))!=0)
		cout << "fetch(&stringStash, " << i << ") = "
				 << cp << endl;
	cleanup(&intStash);
	cleanup(&stringStash);
}

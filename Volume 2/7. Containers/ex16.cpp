/*
Open a file and read it into a single string. Turn
the string into a stringstream. Read tokens from the
stringstream into a list<string> using a TokenIterator.
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <list>
#include "TokenIterator.h"

int main() {

	std::ifstream source("ex16.cpp", std::ios::in);
	std::string line;
	std::string content;

	while (std::getline(source, line))
		content = content + line + "\n";

	std::stringstream os(content);

	typedef std::istreambuf_iterator<char> IsbIt;
	IsbIt begin(os), isbEnd;

	Delimiters delimiters(" \t\n~;()'\"<>:{}[]+-=&*#.,/\\");

	TokenIterator<IsbIt, Delimiters>
	wordIter(begin, isbEnd, delimiters), end;

	std::list<std::string> wordlist;
	std::copy(wordIter, end, std::back_inserter(wordlist));

	for(auto w : wordlist)
		std::cout << w << '\n';

return 0;
}

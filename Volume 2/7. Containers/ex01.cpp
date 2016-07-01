/*
Create a set<char>, open a file (whose name is provided
on the command line), and read that file in a char at a
time, placing each char in the set. Print the results,
and observe the organization. Are there any letters in the
alphabet that are not used in that particular file?
*/

#include <iostream>
#include <fstream>
#include <set>

int main() {

	std::ifstream source("ex01.cpp", std::ios::in);
	std::set<char> symbols;

	char c;
	while (source >> c)
		symbols.insert(c);

	for (const auto& s : symbols)
		std::cout << s << ' ';

return 0;
}

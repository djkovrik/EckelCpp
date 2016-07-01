/*
Write a program that takes as a command-line argument
the name of a text file. Open this file and read it a
word at a time (hint: use >>). Store each word into a
vector<string>. Force all the words to lowercase, sort
them, remove all the duplicates, and print the results.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

std::string lower_case(const std::string& s) {
	std::string lower(s);
	for(size_t i = 0; i < s.length(); ++i)
		lower[i] = std::tolower(lower[i]);
	return lower;
}

int main() {

	std::ifstream source("ex10.txt", std::ios::in);
	std::vector<std::string> words;

	std::string buf;
	while (source >> buf)
		words.push_back( lower_case(buf) );

	std::sort(words.begin(), words.end());

	auto last = std::unique(words.begin(), words.end());
	std::unique(words.begin(), words.end());
	words.erase(last, words.end());

	for(const auto& w : words)
		std::cout << w << '\n';

return 0;
}

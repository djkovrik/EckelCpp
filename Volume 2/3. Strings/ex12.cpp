/*
Write a program that takes a filename from the command
line and profiles the character usage, including punctuation
and spaces (all character values of 0x21 [33] through 0x7E [126],
as well as the space character). That is, count the number of
occurrences of each character in the file, then display the
results sorted either sequentially (space, then !, ", #, etc.)
or by ascending or descending frequency based on user input at
the beginning of the program. For space, display the word "Space"
instead of the character ' '. A sample run might look something
like this:
Format sequentially, ascending, or descending (S/A/D): D
t:  526
r:  490
etc.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {

	std::ifstream source("ex12.txt", std::ios::in);
	char symbol;
	std::unordered_map<char, int> stats;

	while (source >> symbol)
		stats[symbol]++;

	std::vector<std::pair<char, int>> sorted(stats.begin(), stats.end());

	auto ascending = [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
		return a.first < b.first;
	};

	auto descending = [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
			return a.first > b.first;
	};

	std::cout << "Format sequentially, ascending, or descending (S/A/D): ";
	char mode;
	std::cin >> mode;

	switch(mode) {
	case 'A':
		std::sort(sorted.begin(), sorted.end(), ascending);
		break;
	case 'D':
		std::sort(sorted.begin(), sorted.end(), descending);
		break;
	default:
		std::cout << "Sorting disabled.\n";
		break;
	}

	for (const auto& element : sorted)
		std::cout << element.first << " - " << element.second << '\n';

return 0;
}

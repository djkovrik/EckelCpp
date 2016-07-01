/*
Write an anagram generator that takes a word as
a command-line argument and produces all possible
permutations of the letters.
*/

#include <iostream>
#include <algorithm>
#include <string>

int main() {

	std::string str;

	std::cout << "Type a string: ";
	std::cin >> str;

	std::cout << "Anagrams: \n";

	std::sort(str.begin(), str.end());



	do {
		 std::cout << str << '\n';
	} while(std::next_permutation(str.begin(), str.end()));

return 0;
}

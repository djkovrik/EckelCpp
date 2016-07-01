/*
Write a "sentence anagram generator" that takes a
sentence as a command-line argument and produces
all possible permutations of the words in the sentence.
(It leaves the words alone and just moves them around.)
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

template<typename T, typename Container = std::vector<T>>
void print(const Container& data) {

	for(auto element : data)
		std::cout << element << ' ';

	std::cout << '\n';
}

int main() {

	std::string sentence;

	std::cout << "Type a sentence: ";
	std::getline(std::cin, sentence);

	size_t pos = sentence.find_first_of(".,?!");
	if (pos != std::string::npos)
		sentence.erase(pos,1);

	std::istringstream ss(sentence);

	std::vector<std::string> words;
	std::string w;

	while (ss >> w)
		words.push_back(w);

	std::sort(words.begin(), words.end());

	do {
		print<std::string>(words);
	} while(std::next_permutation(words.begin(), words.end()));

return 0;
}

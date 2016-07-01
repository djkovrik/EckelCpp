/*
Write a program that accepts two command-line arguments
(a filename and a number) and scrambles each word in the
file by randomly switching two of its letters the number
of times specified in the second argument. (That is, if 0
is passed into your program from the command-line, the
words should not be scrambled; if 1 is passed in, one
pair of randomly-chosen letters should be swapped, for an
input of 2, two random pairs should be swapped, etc.).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>

std::string swapper(const std::string& word, int count) {

	if (word.size() <= 2)
		return word;

	std::string temp(word);

	std::srand(std::time(0));

	int word_size = word.size();
	int index1, index2;

	for (int i = 0; i < count; i++) {
		index1 = std::rand() % word_size;
		index2 = std::rand() % word_size;
		std::swap(temp[index1], temp[index2]);
	}

	return temp;
}

int main() {

	std::ifstream source("ex16.txt", std::ios::in);
	std::ofstream result("ex16_result.txt", std::ios::out);
	std::string buf;
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::cout << "Please enter how many swaps should be applied: ";
	int swaps;
	std::cin >> swaps;

	size_t word_start, word_end;
	std::string temp_word, new_word;

	while ( getline(source, buf) ) {
		word_start = buf.find_first_of(alphabet);

		while (word_start != std::string::npos) {
			word_end = buf.find_first_not_of(alphabet, word_start+1);
			temp_word = buf.substr(word_start, word_end - word_start);
			new_word = swapper(temp_word, swaps);
			buf.replace(word_start, temp_word.size(), new_word);
			word_start = buf.find_first_of(alphabet, word_end);
		}
		result << buf << '\n';
	}
	std::cout << "All operations completed.\n";

return 0;
}

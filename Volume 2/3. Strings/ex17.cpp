/*
Write a program that accepts a filename from the command
line and displays the number of sentences (defined as the
number of periods in the file), average number of
characters per sentence, and the total number of
characters in the file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::ifstream source("ex17.txt", std::ios::in);
	std::string buf;

	size_t sentence_start = 0, sentence_end;
	std::vector<int> average;
	std::string full_string, full_sentence;

	while ( getline(source, buf) )
		full_string += buf;

	sentence_end = full_string.find(".");

	while (sentence_end != std::string::npos) {
		full_sentence.clear();
		full_sentence = full_string.substr(sentence_start, sentence_end - sentence_start);
		average.push_back(full_sentence.size());
		sentence_start = sentence_end + 2;
		sentence_end = full_string.find(".", sentence_start);
	}

	std::cout << "Total number of characters: " << full_string.size()
			  << "\nSentences detected: " << average.size();


	if (average.size() != 0) {
		int lengths = 0;
		for(const auto& a : average)
			lengths += a;

		std::cout << "\nAverage sentence length: " << lengths / average.size() << '\n';
	}

return 0;
}

/*
Write a program that takes two command-line arguments
(a filename and a string) and counts the number of times
the string occurs in the file, even as a substring
(but ignoring overlaps). For example, an input string
of “ba” would match twice in the word “basketball,” but
an input string of “ana” would match only once in the
word “banana.” Display to the console the number of
times the string is matched in the file, as well as
the average length of the words where the string occurred.
(If the string occurs more than once in a word, only count
the word once in figuring the average.)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {

	std::ifstream source("ex11.txt", std::ios::in);
	std::string str;

	std::cout << "Please enter a string for search: ";
	std::cin >> str;

	std::string buf;
	size_t pos;
	int s_count = 0;
	std::set<std::string> words;

	while (source >> buf) {
		pos = buf.find(str);

		while (pos != std::string::npos) {
			++s_count;
			words.insert(buf);
			pos = buf.find(str, pos + str.size());
		}
	}

	std::cout << "String " << str << " appears " << s_count << " times in a given file.\n";

	int lengths = 0;
	for (const auto& s : words) {
		lengths += s.size();
	}

	if (words.size() != 0)
		std::cout << "Average words length: " << lengths / words.size() << '\n';

return 0;
}

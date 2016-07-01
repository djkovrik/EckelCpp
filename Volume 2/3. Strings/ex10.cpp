/*
Write a program that takes three command-line arguments
(a filename and two strings) and displays to the console
all lines in the file that have both strings in the line,
either string, only one string, or neither string, based
on user input at the beginning of the program (the user
will choose which matching mode to use). For all but
the "neither string" option, highlight the input string(s)
by placing an asterisk (*) at the beginning and end of
each string’s occurrence when it is displayed.
*/

#include <iostream>
#include <fstream>
#include <string>

enum Modes {Both = 1, Either = 2, Neither = 3};

bool should_print(bool flag1, bool flag2, Modes mode) {

	if ( (mode == Both) && (flag1 == true) && (flag2 == true) )
		return true;

	if ( (mode == Either) && (flag1 == !flag2) )
		return true;

	if ( (mode == Neither) && (flag1 == false) && (flag2 == false) )
		return true;

return false;
}

void highlight_words(std::string& line, std::string word) {
	size_t offset;
	size_t p = line.find(word);
	while (p != std::string::npos) {
		offset = p + word.size() + 1;
		line.insert(p, "*");
		line.insert(offset, "*");
		p = line.find(word, offset);
	}
}

int main() {

	std::ifstream source("ex10.txt", std::ios::in);
	std::string str1, str2;

	std::cout << "Please enter the first string: ";
	std::cin >> str1;
	std::cout << "Please enter the second string: ";
	std::cin >> str2;
	std::cout << "Please define the search mode\n (1: Both, 2: Either, Other: Neither): ";

	Modes current_mode;
	int mode;

	std::cin >> mode;

	switch(mode) {
		case 1:
			current_mode = Both;
			break;
		case 2:
			current_mode = Either;
			break;
		default:
			current_mode = Neither;
			break;
	}

	std::cout << "First string: " << str1 << ", second string: " << str2 << ", mode: " << current_mode << '\n';

	std::string buf;
	size_t pos;
	bool word1, word2;

	while (getline(source, buf)) {

		word1 = word2 = false;

		pos = buf.find(str1);
			if (pos != std::string::npos)
				word1 = true;

		pos = buf.find(str2);
			if (pos != std::string::npos)
				word2 = true;

		if ( should_print(word1, word2, current_mode) ) {
			if (current_mode != Neither) {
				highlight_words(buf, str1);
				highlight_words(buf, str2);
			}
			std::cout << buf << '\n';
		}
	}

return 0;
}

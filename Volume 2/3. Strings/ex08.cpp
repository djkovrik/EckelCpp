/*
Make your program from Exercise 3 take a filename from
the command-line, and then display all words that are
palindromes (ignoring case) in the file. Do not display
duplicates (even if their case differs). Do not try to
look for palindromes that are larger than a word
(unlike in Exercise 4).

Exercise 3:
Make your program from Exercise 2 return true even if
symmetric letters differ in case. For example, "Civic"
would still return true although the first letter is capitalized.

Exercise 2:
A palindrome is a word or group of words that read the
same forward and backward. For example "madam" or "wow."
Write a program that takes a string argument from the
command line and, using the function from the previous
exercise, prints whether the string was a palindrome or not.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>

std::string reverse(const std::string& str) {
	return std::string(str.rbegin(), str.rend());
}

std::string lower_case(const std::string& s) {
	std::string lower(s);
	for(size_t i = 0; i < s.length(); ++i)
		lower[i] = std::tolower(lower[i]);
	return lower;
}

std::string erase_extra_symbols (const std::string& s) {
	std::string temp = s;
	auto p = temp.find_first_of(",.!/\?:");

	while(p != std::string::npos) {
		temp.erase(p, 1);
		p = temp.find_first_of(",.!/\?:", p);
	}
	return temp;
}

bool is_palindrome(const std::string& s) {
	std::string temp = lower_case(s);
	temp = erase_extra_symbols(temp);
	return reverse(temp) == temp;
}

int main() {
	std::string buf;
	std::ifstream source("ex08.txt", std::ios::in);
	std::set<std::string> pals;

	while (source >> buf) {
		buf = erase_extra_symbols(buf);
		if ( is_palindrome(buf) )
			pals.insert( lower_case(buf) );
	}

	for (const auto& p : pals)
		std::cout << p << '\n';

return 0;
}

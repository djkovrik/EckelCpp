/*
Change your program from Exercise 3 to ignore punctuation
and spaces as well. For example "Able was I, ere I saw Elba."
would report true.

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
#include <string>
#include <cctype>

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
	auto p = temp.find_first_of(" ,.!/\?:");

	while(p != std::string::npos) {
		temp.erase(p, 1);
		p = temp.find_first_of(" ,.!/\?:", p);
	}
	return temp;
}

bool is_palindrome(const std::string& s) {
	std::string temp = lower_case(s);
	temp = erase_extra_symbols(temp);
	return reverse(temp) == temp;
}

int main() {
	std::string str;
	std::cout << "Type a string: ";
	std::getline(std::cin, str);

	if ( is_palindrome(str) )
		std::cout << "Palindrome!\n";
	else
		std::cout << "Not a palindrome!\n";

return 0;
}

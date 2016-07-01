/*
A palindrome is a word or group of words that read the
same forward and backward. For example "madam" or "wow."
Write a program that takes a string argument from the
command line and, using the function from the previous
exercise, prints whether the string was a palindrome or not.
*/

#include <iostream>
#include <string>

std::string reverse(const std::string& str) {
	return std::string(str.rbegin(), str.rend());
}

bool is_palindrome(const std::string& s) {
	return reverse(s) == s;
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

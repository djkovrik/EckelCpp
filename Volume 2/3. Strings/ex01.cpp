/*
Write and test a function that reverses the order of
the characters in a string.
*/

#include <iostream>
#include <string>

std::string reverse(const std::string& str) {
	return std::string(str.rbegin(), str.rend());
}

int main() {
	std::string s = "Abc de f.";
	std::cout << "Initial string: " << s
			  << "\nReversed string: " << reverse(s) << '\n';

return 0;
}

/*
Using transform( ) and toupper( ) (in <cctype>), write
a single function call that will convert a string
to all uppercase letters.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

std::string to_upper(const std::string str) {

	std::string result(str);

	std::transform(result.begin(), result.end(), result.begin(),
			[](char c) { return std::toupper(c); }
	);

	return result;
}

int main() {

	std::cout << "Type a string: ";
	std::string s;
	std::cin >> s;
	std::cout << "Result: " << to_upper(s) << '\n';

return 0;
}

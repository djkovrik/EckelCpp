/*
Using the find_first_of "family" of functions (but not exclusively),
write a program that will remove all non-alphanumeric
characters except spaces and periods from a file, then
capitalize the first letter following a period.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void capitalize(std::string& s) {

	size_t dot_pos = s.find(".");

	while( dot_pos != std::string::npos ) {
		if (dot_pos + 2 < s.size())
			s[dot_pos+2] = toupper(s[dot_pos+2]);
		dot_pos = s.find(".", dot_pos + 2);
	}
}

int main() {

	std::ifstream source("ex14.txt", std::ios::in);
	std::string buf;

	while ( getline(source, buf) ) {
		size_t pos = buf.find_first_of(",!@#$%^&*()\"\'№;%:<>?~+-\\[]{}");

		while (pos != std::string::npos) {
			buf.erase(pos, 1);
			pos = buf.find_first_of(",!@#$%^&*()\"\'№;%:<>?~+-\\[]{}");
		}

		capitalize(buf);
		std::cout << buf << '\n';
	}

return 0;
}

/*
Open a file by creating an ifstream object. Make an
ostringstream object and read the entire contents into
the ostringstream using the rdbuf( ) member function.
Extract a string copy of the underlying buffer and
capitalize every character in the file using the
Standard C toupper( ) macro defined in <cctype>.
Write the result out to a new file.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>

int main() {
	/*Some command line arguments parsing here*/
	std::ifstream source("ex01.cpp", std::ios::in);
	std::ofstream result("ex01.txt", std::ios::out);
	std::ostringstream ss;

	ss << source.rdbuf();
	std::string content = ss.str();

	for (auto& s : content)
		s = toupper(s);

	result << content;

return 0;
}

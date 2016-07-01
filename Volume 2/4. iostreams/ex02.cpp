/*
Create a program that opens a file (the first argument
on the command line) and searches it for any one of a
set of words (the remaining arguments on the command line).
Read the input a line at a time, and write out the lines
(with line numbers) that match to the new file.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int main() {
	/*Some command line arguments parsing here*/
	std::ifstream source("ex02.cpp", std::ios::in);
	std::ofstream result("ex02.txt", std::ios::out);

	std::vector<std::string> arguments;

	arguments.emplace_back("command");
	arguments.emplace_back("file");
	arguments.emplace_back("=");

	std::ostringstream ss;
	int line_counter = 0;
	std::string buf;
	bool flag;

	while (getline(source, buf)) {
		++line_counter;
		flag = false;

		for (const auto& s : arguments) {
			if ( buf.find(s) != std::string::npos ) {
				flag = true;
				break;
			}
		}
		if (flag)
			ss << line_counter << ": " << buf << '\n';

	}

	result << ss.str();

return 0;
}

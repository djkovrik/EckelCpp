/*
Write a program that adds a copyright notice to the beginning
of all source-code files indicated by the program’s command-line arguments.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
	/*Some command line arguments parsing here*/
	std::ifstream source("ex03.cpp", std::ios::in);
	std::ofstream result("ex03_.cpp", std::ios::out);

	const std::string notice = "/**\n* Author: XXX\n* Date: xx.xx.xxxx\n* All rights reserved.\n*/\n\n";

	std::ostringstream ss;

	ss << notice << source.rdbuf();

	result << ss.str();

return 0;
}

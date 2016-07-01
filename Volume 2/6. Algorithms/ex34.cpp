/*
Given a file with data similar to the following,
pull all the state acronyms from the file and put
them in a separate file. (Note that you can’t depend
on the line number for the type of data. The data is
on random lines.)

ALABAMA
AL
AK
ALASKA
ARIZONA
AZ
ARKANSAS
AR
CA
CALIFORNIA
CO
COLORADO
etc.

When complete, you should have a file with all the
state acronyms.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::ifstream source("ex34.txt", std::ios::in);
	std::vector<std::string> data;
	std::string buf;

	while (std::getline(source, buf))
		data.push_back(buf);

	auto middle = std::stable_partition(data.begin(), data.end(),
		[](const std::string& str) { return str.size() == 2; }
	);

	std::ofstream acronyms("ex34_acronyms.txt", std::ios::out);
	std::ofstream names("ex34_names.txt", std::ios::out);

	std::for_each(data.begin(), middle, [&acronyms](const std::string& str)  { acronyms << str << ' '; });
	std::for_each(middle, data.end(), [&names](const std::string& str)  { names << str << '\n'; });

return 0;
}

/*
Write a program that will take phone numbers
from a file (that also contains names and other
suitable information) and change the numbers
that begin with 222 to 863. Be sure to save the
old numbers. The file format is as follows:

222 8945
756 3920
222 8432
etc.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

std::string make_mask(const std::string& line) {
	std::string result(line);

	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) {
			if (std::isdigit(c) != 0)
				return '#';

			if (c == ' ')
				return ' ';

			return '*';
		}
	);

	return result;
}

int main() {

	std::ifstream source("ex32.txt", std::ios::in);
	std::ostringstream os;
	os << source.rdbuf();
	std::string content = os.str();

	std::string mask = "### ####";

	auto pos = content.begin();

	while (pos != content.end() - mask.size() + 1) {
		std::string temp = std::string(pos, pos + mask.size());

		if ( mask == make_mask(temp) ) {
			//std::cout << "Detected: " + temp + "\n";
			if ( temp.substr(0, 3) == "222" )
				content.replace(pos, pos + 3, "863");
		}

		pos++;
	}

	std::ofstream result("ex32_result.txt", std::ios::out);

	result << content;

return 0;
}

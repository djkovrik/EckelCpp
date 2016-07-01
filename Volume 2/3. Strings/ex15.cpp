/*
Again using the find_first_of "family" of functions,
write a program that accepts a filename as a command-line
argument and then formats all numbers in the file to
currency. Ignore decimal points after the first until
a non-numeric character is found, and round to the
nearest hundredth. For example, the string
12.399abc29.00.6a would be formatted (in the USA)
to $12.40abc$29.01a.
*/

#include <iostream>
#include <string>
#include <cmath>

double round(double v) {
    if(v < 0)
    	return ceil(v - 0.5);

    return floor(v + 0.5);
}

void convert_to_currency(std::string& str) {

	if (str.back() == '.')
		return;

	size_t pos = str.find(".");
	while (pos != std::string::npos) {
		pos = str.find(".", pos + 1);
		if (pos != std::string::npos)
			str.erase(pos, 1);
	}

	double d = stod(str);
	d = round(d * 100.0 ) / 100.0;
	str = std::to_string(d);
	str.insert(0,"$");
	pos = str.find(".");
	str.erase(pos + 3);
}

int main() {

	std::string source = "oil1.63200chips12.399abc29.00.6soap0.2.5.6.coin7.628i9.a";
	std::cout << "Initial string:\n" << source << '\n';

	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string digits = "0123456789";

	size_t start_pos = source.find_first_of(digits);
	std::string extracted_num;

	while (start_pos != std::string::npos) {
		size_t end_pos = source.find_first_of(alphabet, start_pos);
		extracted_num = source.substr(start_pos, end_pos - start_pos);
		source.erase(start_pos, extracted_num.size());
		convert_to_currency(extracted_num);
		source.insert(start_pos, extracted_num);
		start_pos = source.find_first_of(digits, end_pos);
	}

	std::cout << "\nFormated string:\n" << source << '\n';

return 0;
}

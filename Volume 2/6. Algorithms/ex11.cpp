/*
Write a program that finds all the words that are in
common between two input files, using set_intersection( ).
Change it to show the words that are not in common,
using set_symmetric_difference( ).
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cctype>

int main() {

	std::ifstream file1("ex11_1.txt", std::ios::in);
	std::ifstream file2("ex11_2.txt", std::ios::in);

	std::vector<std::string> words1;
	std::vector<std::string> words2;

	std::string buf;

	while (file1 >> buf)
		words1.push_back(buf);

	while (file2 >> buf)
		words2.push_back(buf);

	std::sort(words1.begin(), words1.end());
	std::sort(words2.begin(), words2.end());

	auto last = std::unique(words1.begin(), words1.end());
	std::unique(words1.begin(), words1.end());
	words1.erase(last, words1.end());

	last = std::unique(words2.begin(), words2.end());
	std::unique(words2.begin(), words2.end());
	words2.erase(last, words2.end());

	std::vector<std::string> intersection;
	std::vector<std::string> difference;

	std::set_intersection(words1.begin(), words1.end(),
						  words2.begin(), words2.end(),
						  std::back_inserter(intersection));

	std::set_symmetric_difference(words1.begin(), words1.end(),
								  words2.begin(), words2.end(),
								  std::back_inserter(difference));


	std::cout << "Intersection: ";
	for (const auto& i : intersection)
		std::cout << i << ' ';

	std::cout << "\nDifference: ";
		for (const auto& d : difference)
			std::cout << d << ' ';

	std::cout << std::endl;

return 0;
}

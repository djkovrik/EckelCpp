/*
Open a text file whose name is provided on the
command line. Read the file a word at a time,
and use a multiset<string> to create a word
count for each word.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>

int main() {

	std::ifstream source("ex09.txt", std::ios::in);
	std::multiset<std::string> words;

	std::string buf;

	while (source >> buf)
		words.insert(buf);

	auto it = words.begin();
		while(it != words.end()) {
			auto p = words.equal_range(*it);
			int count = std::distance(p.first, p.second);
			std::cout << *it << ": " << count << '\n';
				it = p.second;
		  }

return 0;
}

/*
Create a generator that produces random int
values between 0 and 20 inclusive, and use
it to fill a multiset<int>. Count the occurrences
of each value, following the example given
in MultiSetWordCount.cpp.
*/

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <set>

int main() {

	std::multiset<int> mi;

	std::generate_n(inserter(mi, mi.begin()), 25,
		[]() { return std::rand()%20 + 1; }
	);

	auto it = mi.begin();
	while(it != mi.end()) {
		auto p = mi.equal_range(*it);
		int count = std::distance(p.first, p.second);
		std::cout << *it << ": " << count << '\n';
			it = p.second;
	  }

return 0;
}

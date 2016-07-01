/*
Create a program that, given an integer on the command
line, creates a "factorial table" of all the factorials
up to and including the number on the command line. To
do this, write a generator to fill a vector<int>, and
then use partial_sum( ) with a standard function object.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <functional>
#include <iterator>

int main() {

	int limit = 0;
	std::cout << "Please enter the upper limit: ";
	std::cin >> limit;

	std::vector<int> nums;
	int i = 1;
	std::generate_n(back_inserter(nums), limit, [&i]() { return i++; } );

	std::vector<int> results;

	std::partial_sum(nums.begin(), nums.end(), back_inserter(results), std::multiplies<int>());

	for (size_t i = 0; i < results.size(); i++)
		std::cout << i + 1 << "! = " << results.at(i) << '\n';

return 0;
}

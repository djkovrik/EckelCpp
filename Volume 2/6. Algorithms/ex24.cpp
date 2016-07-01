/*
Determine how much faster binary_search( ) is to find( )
when it comes to searching sorted ranges.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {

	std::srand(std::time(0));

	std::vector<int> numbers;

	std::generate_n(std::back_inserter(numbers), 20000000,
			[]() { return std::rand() % 10000000; }
	);

	int key = numbers.at(5000000);

	std::sort(numbers.begin(), numbers.end());

	clock_t t0 = clock();
	auto f = std::find(numbers.begin(), numbers.end(), key);
	clock_t t1 = clock();

	std::cout << "find() timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

	t0 = clock();
	auto b = std::binary_search(numbers.begin(), numbers.end(), key);
	t1 = clock();

	std::cout << "binary_search() timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

return 0;
}

/*
Race sort( ), partial_sort( ), and nth_element( )
against each other and find out if it’s really worth
the time saved to use one of the weaker sorts if
they’re all that’s needed.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {

	std::srand(std::time(0));

	std::vector<int> numbers1;

	std::generate_n(std::back_inserter(numbers1), 2000000,
		[]() { return std::rand() % 1000000; }
	);

	clock_t t0 = clock();
	std::sort(numbers1.begin(), numbers1.end());
	clock_t t1 = clock();
	std::cout << "sort() timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

	std::vector<int> numbers2;

	std::generate_n(std::back_inserter(numbers2), 2000000,
		[]() { return std::rand() % 1000000; }
	);

	t0 = clock();
	std::partial_sort(numbers2.begin(), numbers2.begin() + 100000, numbers2.end());
	t1 = clock();
	std::cout << "partial_sort() timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

	std::vector<int> numbers3;

	std::generate_n(std::back_inserter(numbers3), 2000000,
		[]() { return std::rand() % 1000000; }
	);

	t0 = clock();
	std::nth_element(numbers3.begin(), numbers3.begin() + numbers3.size()/2, numbers3.end());
	t1 = clock();
	std::cout << "nth_element() timing: " << (double)(t1 - t0) / CLOCKS_PER_SEC  << '\n';

return 0;
}

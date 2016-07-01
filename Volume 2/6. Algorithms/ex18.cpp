/*
Create an STL-style algorithm that is an overloaded
version of for_each( ) which follows the second form
of transform( ) and takes two input ranges so it can
pass the objects of the second input range a to a
binary function that it applies to each object of
the first range.
*/

#include <iostream>
#include <algorithm>
#include <vector>

template<class InputIt1, class InputIt2, class BinaryOperation>
InputIt1 for_each_my(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryOperation binary_op)
{
    while (first1 != last1) {
        *first1 = binary_op(*first1, *first2);
        first1++;
        first2++;
    }
    return first1;
}

int main() {

	std::vector<int> numbers{1, 2, 3, 4, 5};
	std::vector<int> multipliers{10, 100, 1000, 10000, 100000};

	for (auto n : numbers)
		std::cout << n << ' ';

	std::cout << '\n';

	for_each_my(numbers.begin(), numbers.end(), multipliers.begin(),
			[](int x, int y) { return x * y; }
	);

	for (auto n : numbers)
		std::cout << n << ' ';

return 0;
}

/*
Write a function template that takes a single type
parameter (T) and accepts four function arguments:
an array of T, a start index, a stop index (inclusive),
and an optional initial value. The function returns the
sum of all the array elements in the specified range and
the initial value. Use the default constructor of T for
the default initial value.
*/

#include <iostream>

template<typename T>
T sum_elements(T arrray[], int from, int to, T initial = T() ) {
	T sum = initial;

	for (int i = from; i <= to; ++i)
		sum += arrray[i];

	return sum;
}

int main() {

	int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Sum from 1st to 4th elements: " << sum_elements(test_array, 1, 4) << '\n';

	std::cout << "Initial = 100, the same sum: " << sum_elements(test_array, 1, 4, 100) << '\n';

return 0;
}

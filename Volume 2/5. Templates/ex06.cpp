/*
Repeat the previous exercise but use explicit instantiation
to manually create specializations for int and double, following
the technique explained in this chapter.

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
	//std::cout << "common template\n";
	for (int i = from; i <= to; ++i)
		sum += arrray[i];

	return sum;
}

template<>
int sum_elements<int>(int arrray[], int from, int to, int initial ) {
	int sum = initial;
	//std::cout << "int spec\n";
	for (int i = from; i <= to; ++i)
		sum += arrray[i];

	return sum;
}

template<>
double sum_elements<double>(double arrray[], int from, int to, double initial ) {
	double sum = initial;
	//std::cout << "double spec\n";
	for (int i = from; i <= to; ++i)
		sum += arrray[i];

	return sum;
}


int main() {

	int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Sum from 1st to 4th elements: " << sum_elements<>(test_array, 1, 4) << '\n';
	std::cout << "Initial = 100, the same sum: " << sum_elements<>(test_array, 1, 4, 100) << '\n';

	double test_array2[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.1};

	std::cout << "Sum from 1st to 3th elements: " << sum_elements<>(test_array2, 1, 3) << '\n';
	std::cout << "Initial = 0.1, the same sum: " << sum_elements<>(test_array2, 1, 3, 0.1) << '\n';

	float test_array3[] = {1.1f, 2.2f, 3.3f};
	std::cout << "Sum from 1st to 2th elements: " << sum_elements(test_array3, 1, 2) << '\n';
	std::cout << "Initial = 0.5, the same sum: " << sum_elements(test_array3, 1, 2, 0.5f) << '\n';
return 0;
}

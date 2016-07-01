/*
Create a valarray<int> with 12 random values.
Create another valarray<int> with 20 random values.
You will interpret the first valarray as a 3 x 4 matrix
of ints and the second as a 4 x 5 matrix of ints, and
multiply them by the rules of matrix multiplication.
Store the result in a valarray<int> of size 15,
representing the 3 x 5 result matrix. Use slices to multiply
the rows of the first matrix time the columns of the second.
Print the result in rectangular matrix form.
*/

#include <iostream>
#include <valarray>
#include <cstdlib>
#include <ctime>
#include <iomanip>

template<class T>
std::valarray<T>
mult_matrix(const std::valarray<T>& a, size_t a_rows, size_t a_cols,
		const std::valarray<T>& b, size_t b_rows, size_t b_cols) {

	std::valarray<T> result(a_rows * b_cols);
	for(size_t i = 0; i < a_rows; ++i)
		for(size_t j = 0; j < b_cols; ++j) {
			std::valarray<T> row = a[std::slice(a_cols*i, a_cols, 1)];
			std::valarray<T> col = b[std::slice(j, b_rows, b_cols)];
			result[i*b_cols + j] = (row * col).sum();
    }
	return result;
}

template<class T>
void print_matrix(const std::valarray<T>& a, size_t rows, size_t cols) {
	size_t sz = rows*cols;

	for(size_t i = 0; i < sz; ++i) {
		std::cout << std::setw(5) << a[i];
		std::cout << ((i+1)%cols ? ' ' : '\n');
  }
	std::cout << '\n';
}


int main() {

	std::srand(std::time(0));

	const size_t size1 = 12;		// 3(r) x 4(c)
	const size_t size2 = 20;		// 4(r) x 5(c)
									// result is 3x5
	int array1[size1] = {0};
	int array2[size2] = {0};

	for (int& a1 : array1) a1 = std::rand()%100 + 1;
	for (int& a2 : array2) a2 = std::rand()%100 + 1;

	std::valarray<int> a1(array1, size1);
	std::valarray<int> a2(array2, size2);

	std::valarray<int> result(mult_matrix(a1, 3, 4, a2, 4, 5));

	print_matrix(a1, 3, 4);
	print_matrix(a2, 4, 5);
	print_matrix(result, 3, 5);

return 0;
}

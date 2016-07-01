/*
Create a Matrix class template that is made
from a vector<vector<T> >. Provide it with a
friend ostream& operator<<(ostream&, const Matrix&)
to display the matrix. Create the following binary
operations using the STL function objects where
possible: operator+(const Matrix&, const Matrix&)
for matrix addition, operator*(const Matrix&,
const vector<int>&) for multiplying a matrix by
a vector, and operator*(const Matrix&, const Matrix&)
for matrix multiplication. (You might need to look
up the mathematical meanings of the matrix operations
if you don’t remember them.)
Test your Matrix class template using int and float.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>
#include <stdexcept>

// Forward declarations
template<typename T> class Matrix;

template<typename T>
std::ostream& operator<<(std::ostream&, const Matrix<T>& );

template<typename T>
Matrix<T> operator+(const Matrix<T>& , const Matrix<T>& );

template<typename T>
Matrix<T> operator*(const Matrix<T>& , const std::vector<T>& );

template<typename T>
Matrix<T> operator*(const Matrix<T>& , const Matrix<T>& );

// Class definition
template<typename T>
class Matrix {
	friend std::ostream& operator<< <>(std::ostream& , const Matrix<T>& );
	friend Matrix operator+ <>(const Matrix& , const Matrix& );
	friend Matrix operator* <>(const Matrix& , const std::vector<T>& );
	friend Matrix operator* <>(const Matrix& , const Matrix& );

public:
	Matrix(size_t r = 0, size_t c = 0);
	Matrix(std::initializer_list<std::initializer_list<T>> );
	Matrix& operator=(const Matrix& );

private:
	size_t rows;
	size_t columns;
	std::vector<std::vector<T>> data;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
	for (const auto& row : m.data) {
		for (const auto& element : row)
			out << element << '\t';
		out << '\n';
	}
	return out;
}

template<typename T>
Matrix<T>::Matrix(size_t r, size_t c) : rows(r), columns(c) {
	data.reserve(r);

	for (auto row : data)
		row.reserve(c);
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
	rows = list.size();
	auto p = list.begin();
	columns = (*p).size();

	std::vector<T> temp;
	for (const auto& row : list) {
		temp.clear();
		temp.insert(temp.begin(), row.begin(), row.end());
		data.push_back(temp);
	}
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& right) {
	rows = right.rows;
	columns = right.columns;
	data = right.data;

	return *this;
}

template<typename T>
Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right) {

	Matrix<T> result (left.rows, left.columns);

	std::vector<T> temp;

	for (size_t i = 0; i < left.rows; i++) {
		temp.clear();
		auto lvec = left.data.at(i);
		auto rvec = right.data.at(i);
		std::transform(lvec.begin(), lvec.end(), rvec.begin(), std::back_inserter(temp),
				[](T a, T b) { return a + b; }
		);
		result.data.push_back(temp);
	}

	return result;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& left, const std::vector<T>& right) {

	Matrix<T> result(1, left.rows);
	std::vector<T> temp;

	for (size_t i = 0; i < left.rows; i++) {
		temp.clear();

		auto vec = left.data.at(i);
		int sum = 0;

		for (size_t index = 0; index < left.columns; index++)
			sum += vec.at(index) * right.at(index);

		temp.push_back(sum);
		result.data.push_back(temp);
	}

	return result;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right) {

	Matrix<T> result(left.rows, right.columns);

	std::vector<T> temp;
	for (size_t i_left = 0; i_left < left.rows; i_left++) {
		temp.clear();
		for (size_t j_right = 0; j_right < right.columns; j_right++) {
			int sum = 0;
			for (size_t j_left = 0; j_left < left.columns; j_left++)
				sum += left.data.at(i_left).at(j_left) * right.data.at(j_left).at(j_right);
			temp.push_back(sum);
		}
		result.data.push_back(temp);
	}

	return result;
}

int main() {

	Matrix<int> a = { {1, 2, 3},
					  {4, 5, 6},
					  {7, 8, 7} };

	Matrix<int> b = { {2, 2, 2},
					  {2, 2, 2},
					  {2, 2, 2} };

	std::cout << "a: \n" << a;
	std::cout << "b: \n" << b;
	std::cout << "a + b: \n" << a + b;

	Matrix<int> x = { {1, 2, 3},
			  	      {4, 5, 6},
				      {7, 8, 9},
				      {2, 4, 6} };

	std::vector<int> y = {1, 2, 3};

	std::cout << "x: \n" << x;
	std::cout << "y: \n";
	for (auto element : y) std::cout << element << '\n';
	std::cout << "x * y: \n" << x * y;

	Matrix<int> m1 = { {1, 2, 3},
					   {4, 5, 6} };

	Matrix<int> m2 = { {9, 8},
			           {7, 6},
					   {5, 4} };

	std::cout << "m1: \n" << m1;
	std::cout << "m2: \n" << m2;
	std::cout << "m1 * m2: \n" << m1 * m2;

return 0;
}

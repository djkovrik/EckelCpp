/*
Write a program that reads real numbers from a file
and prints their sum, average, minimum, and maximum.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {

	std::ifstream source("ex13.txt", std::ios::in);
	std::stringstream ss;

	ss << source.rdbuf();

	double d;
	std::vector<double> doubles;

	while (ss >> d)
		doubles.push_back(d);

	double sum = 0;
	double min, max;

	min = max = doubles.front();

	for (const auto& d : doubles) {
		sum += d;
		if (d > max)
			max = d;
		else if (d < min)
			min = d;
	}


	std::cout << "Sum: " << sum
			  << "\nAverage: " << sum / doubles.size()
			  << "\nMin: " << min
			  << "\nMax: " << max << '\n';

return 0;
}

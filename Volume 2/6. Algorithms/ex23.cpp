/*
A travel company wants to find out the average number
of days people take to travel from one end of the continent
to another. The problem is that in the survey, some people
did not take a direct route and took much longer than is
needed (such unusual data points are called "outliers").
Using the following generator, generate travel days into
a vector. Use remove_if( ) to remove all the outliers in
your vector. Take the average of the data in the vector
to find out how long people generally take to travel.

int travelTime() {
        // The "outlier"
        if(rand() % 10 == 0)
          return rand() % 100;
        // Regular route
        return rand() % 10 + 10;
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <numeric>
#include <ctime>

int travelTime() {
	// The "outlier"
	if(rand() % 10 == 0)
		return std::rand() % 100;
	// Regular route
		return std::rand() % 10 + 10;
}

int main() {

	std::srand(std::time(0));

	std::vector<int> routes;

	std::generate_n(std::back_inserter(routes), 50, travelTime);

	std::cout << "Initial routes data: \n";
	for (auto& r : routes)
		std::cout << r << ' ';

	routes.erase( std::remove_if(routes.begin(), routes.end(),
			[](int x) { return x > 20; }
	), routes.end());

	std::cout << "\nCleared routes data: \n";
	for (auto& r : routes)
		std::cout << r << ' ';

	int sum = std::accumulate(routes.begin(), routes.end(), 0);

	std::cout << "\nAverage time: " << sum / routes.size();

return 0;
}

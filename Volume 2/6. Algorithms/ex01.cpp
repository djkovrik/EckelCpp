/*
Create a generator that returns the current value of
clock( ) (in <ctime>). Create a list<clock_t>, and fill
it with your generator using generate_n( ). Remove any
duplicates in the list and print it to cout using copy( ).
*/

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <ctime>

int main() {

	std::list<clock_t> my_list;

	std::generate_n( std::back_inserter(my_list), 100000, []() { return clock(); } );

	my_list.sort();
	my_list.unique();

	std::copy(my_list.begin(), my_list.end(), std::ostream_iterator<clock_t>(std::cout, "\n"));

return 0;
}

/*
Write a test program using the TestSuite Framework for
the standard vector class that thoroughly tests the following
member functions with a vector of integers: push_back( )
(appends an element to the end of the vector), front( )
(returns the first element in the vector), back( )
(returns the last element in the vector), pop_back( )
(removes the last element without returning it), at( )
(returns the element in a specified index position),
and size( ) (returns the number of elements).
Be sure to verify that vector::at( ) throws a
std::out_of_range exception if the supplied index
is out of range.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include "TestSuite/Suite.h"

class TestVector : public TestSuite::Test {
public:
	TestVector() : Test() {}

	void testOps() {
		v.push_back(6);
		test_(v.back() == 6);
		test_(v.front() == 1);
		v.pop_back();
		test_(v.back() == 5);
		test_(v.at(1) == 2);
		test_(v.size() == 5);
	}

	void testExceptions() {
		try {
			v.at(10) = 10;
			fail_("Invalid index wasn't detected.");
		} catch (std::out_of_range& ex) {
			succeed_();
		}
	}

	void run() {
		testOps();
		testExceptions();
	}
private:
	std::vector<int> v = {1,2,3,4,5};
};


int main() {

	TestVector test;
	test.run();
	return test.report();
}

/*
Create an STL-style algorithm transform_if( ) following
the first form of transform( ) that performs transformations
only on objects that satisfy a unary predicate. Objects that
don’t satisfy the predicate are omitted from the result.
It needs to return a new "end" iterator.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

template<class InputIt, class OutputIt, class UnaryOperation, class UnaryPredicate>
OutputIt transform_if(InputIt first1, InputIt last1, OutputIt d_first,
                   UnaryOperation unary_op, UnaryPredicate pred) {
    while (first1 != last1) {

    	if (pred(*first1))
    		*d_first = unary_op(*first1);
    	d_first++;
    	first1++;
    }
    return d_first;
}

int main() {

	std::string str = "This is a test string.";
	std::cout << str << '\n';

	transform_if( str.begin(), str.end(), str.begin(),
		[](char c) { return std::toupper(c); }, // operation
		[](char s) { return s == 's'; }			// predicate
	);

	std::cout << str << '\n';

return 0;
}

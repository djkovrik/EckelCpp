/*
Demonstrate to yourself that if the fail or bad bit
is set, and you subsequently turn on stream exceptions,
that the stream will immediately throw an exception.
*/

#include <iostream>
#include <fstream>

int main() {

	try {
		std::ifstream my_stream("not found");
		my_stream.exceptions(std::ios::failbit);
	} catch(std::ios_base::failure& e) {
		std::cout << "Exception detected: " << e.what() << '\n';
	}




return 0;
}

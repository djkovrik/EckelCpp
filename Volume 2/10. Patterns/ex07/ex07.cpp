#include <iostream>
#include "ex07.h"


int main(int argc, char** argv) {

	ToLower tl;
	Searcher sr;

	Context c1(tl), c2(sr);

	std::cout << "Choose default behaviour: \n"
			  << "1) Convert all the letters in each file to uppercase.\n"
			  << "2) Search the files for words given in the first file.\n";

	int x = 0;
	std::cin >> x;

	if (x == 1)
		c1.handler(argc, argv);
	else
		c2.handler(argc, argv);

return 0;
}

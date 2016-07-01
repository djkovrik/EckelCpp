/*
Write size_t(-1) (the largest unsigned int on your platform)
to a text file 1,000,000 times. Repeat, but write to a binary file.
Compare the size of the two files, and see how much room is saved
using the binary format. (You may first want to calculate how much
will be saved on your platform.)
*/

#include <iostream>
#include <fstream>

int main() {

	std::ofstream bin("ex11.bin", std::ios::binary);
	std::ofstream txt("ex11.txt", std::ios::out);

	size_t z = size_t(-1);

	for (int i = 0; i < 1'000'000; ++i) {
		txt << z;
		bin.write(reinterpret_cast<const char*>(&z), sizeof(z));
	}

return 0;
}

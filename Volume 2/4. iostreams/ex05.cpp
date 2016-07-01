/*
We know that setw( ) allows for a minimum of characters
read in, but what if you wanted to read a maximum?
Write an effector that allows the user to specify a
maximum number of characters to extract. Have your
effector also work for output, in such a way that output
fields are truncated, if necessary, to stay within width
limits.
*/

#include <iostream>
#include <string>

class SetMax {
public:
	SetMax(const std::string& s = "", int max_width = 0) : data(s, 0, max_width) {}

	friend std::ostream& operator<<(std::ostream& os, const SetMax& o) {
		return os << o.data;
	}

	friend std::istream& operator>>(std::istream& is, SetMax& o) {
		std::string str;
		int size;
		is >> str >> size;
		o.data = str.substr(0, size);
		return is;
	}

	//std::string str() const { return data; }
private:
	std::string data;
};

int main() {

	SetMax obj1("Something", 3);
	std::cout << obj1 << '\n';

	SetMax obj2;
	std::cin >> obj2;
	std::cout << obj2 << '\n';

return 0;
}

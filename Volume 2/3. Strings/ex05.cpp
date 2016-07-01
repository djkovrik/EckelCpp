/*
* Using the following string declarations and only chars
* (no string literals or magic numbers):
  string one("I walked down the canyon with the moving mountain bikers.");
  string two("The bikers passed by me too close for comfort.");
  string three("I went hiking instead.");
* produce the following sentence:

I moved down the canyon with the mountain bikers. The mountain bikers
passed by me too close for comfort. So I went hiking instead.
*/

#include <iostream>
#include <string>

int main() {

	std::string one("I walked down the canyon with the moving mountain bikers.");
	std::string two("The bikers passed by me too close for comfort.");
	std::string three("I went hiking instead.");

	auto pos = one.find("walked");
	one.replace(pos, 6, "moved");
	pos = one.find("moving ");
	one.erase(pos, 7);

	pos = two.find("bikers");
	two.insert(pos, "mountain ");

	three.insert(0, "So ");

	std::cout << one + ' ' + two + ' ' + three << '\n';

return 0;
}

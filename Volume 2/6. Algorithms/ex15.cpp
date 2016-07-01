/*
Fill a vector<double> with numbers representing
angles in radians. Using function object composition,
take the sine of all the elements in your vector
(see <cmath>).
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

const double pi = std::acos(-1);

void print_sinus(double d) {
	std::cout << "sin(" << d << ") = " << std::sin(d * pi / 180) << '\n';
}

int main() {

	double d[] = {30.0, 45, 90, 65.4, 15};
	std::vector<double> vd(d, d + sizeof(d)/sizeof(d[0]));

	//std::for_each(vd.begin(), vd.end(), print_sinus);

	std::for_each(vd.begin(), vd.end(),
		[](double d) {
			std::cout << "sin(" << d << ") = " << std::sin(d * pi / 180) << '\n';
		}
	);

return 0;
}

/*
We need to place an airport in a certain altitude,
but location is not a problem. Organize your list
of towns so that there are no duplicate (duplicate
meaning that no two altitudes are within the same
100 ft range. Such classes would include [100, 199),
[200, 199), etc. altitudes. Sort this list in ascending
order in at least two different ways using the function
objects in <functional>. Do the same for descending order.
Implement relational operators for Town as needed.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

enum class Weather { RAINY, SNOWY, CLOUDY, CLEAR };

class Town {
public:
	Town(std::string nm = "", int ppl = 1, int at = 1, Weather wthr = Weather::RAINY)
		: name(nm), population(ppl), altitude(at), weather_type(wthr) {}

	bool operator<(const Town& right) const { return altitude < right.altitude; }
	bool sorter(const Town& right) const { return population < right.population; }

	std::string name;
	int population;
	int altitude;
	Weather weather_type;
};

std::ostream& operator <<(std::ostream& out, const Town& t) {
	out << t.name << '\t' << t.population << '\t' << t.altitude << '\t';

	switch (t.weather_type) {
	case Weather::RAINY:
		out << "RAINY";
		break;
	case Weather::SNOWY:
		out << "SNOWY";
		break;
	case Weather::CLOUDY:
		out << "CLOUDY";
		break;
	case Weather::CLEAR:
		out << "CLEAR";
		break;
	default:
		out << "NOT DEFINED!";
		break;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Town& t) {

	std::string line;

	getline(in, line);

	if (line == "")
		return in;

	auto pos1 = line.find('\t');
	t.name = line.substr(0, pos1);

	auto pos2 = line.find('\t', pos1 + 1);
	std::string pop = line.substr(pos1 + 1, pos2 - pos1 - 1);
	std::istringstream ss_pop(pop);
	ss_pop >> t.population;

	auto pos3 = line.find('\t', pos2 + 1);
	std::string alt = line.substr(pos2 + 1, pos3 - pos2 - 1);
	std::istringstream ss_alt(alt);
	ss_alt >> t.altitude;

	std::string wthr = line.substr(pos3 + 1);

	if (wthr == "RAINY")
		t.weather_type = Weather::RAINY;
	else if (wthr == "SNOWY")
		t.weather_type = Weather::SNOWY;
	else if (wthr == "CLOUDY")
		t.weather_type = Weather::CLOUDY;
	else
		t.weather_type = Weather::CLEAR;

	return in;
}

int main() {

	std::ifstream source("ex27_towns_data.txt", std::ios::in);

	std::vector<Town> towns;

	Town temp;

	while (source >> temp)
		towns.push_back(temp);

	std::sort(towns.begin(), towns.end(),
		[](const Town& a, const Town& b) { return a < b; }
	);

	//std::cout << "Sorted towns:\n";
	//for (const auto& t : towns)
	//	std::cout << t << '\n';

	std::vector<Town> results;

	int current_altitude = towns.front().altitude;

	results.push_back( towns.front() );

	std::copy_if(towns.begin() + 1, towns.end(), back_inserter(results),
		[&current_altitude](const Town& t) {
			if ( (t.altitude - current_altitude) > 100) {
				current_altitude = t.altitude;
				return true;
			}
			return false;
		}
	);

	std::cout << "Filtered towns:\n";
	for (const auto& r : results)
			std::cout << r << '\n';

	std::sort(results.begin(), results.end(),
		[](const Town& a, const Town& b) { return a.sorter(b); }
	);

	std::cout << "Sorted by population:\n";
	for (const auto& r : results)
		std::cout << r << '\n';

return 0;
}

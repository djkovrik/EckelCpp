/*
Find the towns with the highest and lowest
population. For this exercise, implement
operator< for your Town class. Also try
implementing a function that returns true
if its first parameter is less than its
second. Use it as a predicate to call the
algorithm you use.
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

	bool operator<(const Town& right) const { return population < right.population; }

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

	std::cout << "Lowest population: " << towns.front();
	std::cout << "\nHighest population: " << towns.back();

return 0;
}

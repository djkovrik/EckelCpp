/*
There was a baby boom, resulting in a 10% population
increase in every town. Update your town data using
transform( ), rewrite your data back out to file.

Previous exercise:
Make a class called Town with population, altitude,
and weather data members. Make the weather an enum
with { RAINY, SNOWY, CLOUDY, CLEAR }. Make a class
that generates Town objects. Generate town names
(whether they make sense or not it doesn’t matter)
or pull them off the Internet. Ensure that the whole
town name is lower case and there are no duplicate
names. For simplicity, we recommend keeping your
town names to one word. For the population, altitudes,
and weather fields, make a generator that will randomly
generate weather conditions, populations within the
range [100 to 1,000,000) and altitudes between [0, 8000)
feet. Fill a vector with your Town objects. Rewrite the
vector out to a new file called Towns.txt.
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

	std::ifstream source("ex26_towns_data.txt", std::ios::in);

	std::vector<Town> towns;

	Town temp;

	while (source >> temp)
		towns.push_back(temp);

	std::transform(towns.begin(), towns.end(), towns.begin(),
		[](Town t) {
			t.population += t.population * 0.1;
			return t;
		}
	);

	std::ofstream result("ex27_towns_data.txt", std::ios::out);

	for (const auto& t : towns)
		result << t << '\n';

return 0;
}

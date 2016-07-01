/*
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
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

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

std::ostream& operator<<(std::ostream& out, const Town& t) {
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

class TownsGenerator {
public:
	TownsGenerator(std::string filename);
	Town operator()();
private:
	std::string filename;
	std::vector<bool> generated;
	std::vector<std::string> towns;
	int lines_count;
};

TownsGenerator::TownsGenerator(std::string filename) {
	std::ifstream towns_source(filename, std::ios::in);

	lines_count = std::count(std::istreambuf_iterator<char>(towns_source),
	             	  std::istreambuf_iterator<char>(), '\n');

	generated.reserve(lines_count);
	std::generate_n(std::back_inserter(generated), lines_count, []() { return false; });

	towns_source.clear();
	towns_source.seekg(0, std::ios::beg);

	std::string buf;

	while ( getline(towns_source, buf) )
		towns.push_back(buf);
}

Town TownsGenerator::operator()() {
	int pop = std::rand() % 999900 + 100;
	int alt = std::rand() % 8000;
	int w_int = std::rand() % 4;

	Weather w;

	switch(w_int) {
	case 1:
		w = Weather::SNOWY;
		break;
	case 2:
		w = Weather::CLOUDY;
		break;
	case 3:
		w = Weather::CLEAR;
		break;
	default:
		w = Weather::RAINY;
		break;
	}

	int town_num = 0;

	do {
		town_num = std::rand() % lines_count;
	} while (generated[town_num]);

	generated[town_num] = true;

	std::string town_name = towns.at(town_num);

	return Town(town_name, pop, alt, w);
}

int main() {

	std::srand(std::time(0));

	TownsGenerator town_gen("ex26_towns_ireland.txt");

	std::vector<Town> vt(100);
	std::generate(vt.begin(), vt.end(), town_gen);

	std::ofstream result("ex26_towns_data.txt", std::ios::out);

	for (const auto& t : vt)
		result << t << '\n';

	std::cout << "Generation completed.\n";

return 0;
}

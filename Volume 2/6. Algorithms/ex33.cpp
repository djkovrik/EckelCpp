/*
Write a program that, given a last name, will
find everyone with that last name with his or
her corresponding phone number. Use the algorithms
that deal with ranges (lower_bound, upper_bound,
equal_range, etc.). Sort with the last name
acting as a primary key and the first name
acting as a secondary key. Assume that you
will read the names and numbers from a file
where the format will be as follows. (Be sure
to order them so that the last names are ordered,
and the first names are ordered within the last names.):

John Doe	345 9483
Nick Bonham	349 2930
Jane Doe	283 2819
etc.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

struct Person {
	std::string first_name;
	std::string last_name;
	std::string phone;
};

bool operator==(const std::string& str, const Person& p) { return str == p.last_name; }
bool operator<(const std::string& str, const Person& p) { return str < p.last_name; }
bool operator==(const Person& p, const std::string& str) { return p.last_name == str; }
bool operator<(const Person& p, const std::string& str) { return p.last_name < str; }

std::ostream& operator<<(std::ostream& out, const Person& p) {
	out << p.first_name << ' ' << p.last_name << '\t' << p.phone;
	return out;
}

std::istream& operator>>(std::istream& in, Person& p) {
	std::string temp;
	std::getline(in, temp);

	auto pos_space = temp.find(' ');
	auto pos_tab = temp.find('\t');

	p.first_name = temp.substr(0, pos_space);
	p.last_name = temp.substr(pos_space + 1, pos_tab - pos_space - 1);
	p.phone = temp.substr(pos_tab + 1, temp.size() - pos_tab);

	return in;
}

int main() {

	std::ifstream source("ex33.txt", std::ios::in);
	std::vector<Person> vp;
	Person temp;

	while (source >> temp)
		vp.push_back(temp);

	std::sort(vp.begin(), vp.end(),
		[](const Person& a, const Person& b) { return a.first_name < b.first_name; }
	);

	std::sort(vp.begin(), vp.end(),
		[](const Person& a, const Person& b) { return a.last_name < b.last_name; }
	);


	std::cout << "Initial list:\n";
	for(const auto& p : vp)
		std::cout << p << '\n';

	std::string lastname;
	std::cout << "\nLast name: ";
	std::cin >> lastname;

	auto p = std::equal_range(vp.begin(), vp.end(),	lastname);
	std::cout << "\nFound lines:\n";
	std::for_each(p.first, p.second, [](const Person& p) { std::cout << p << '\n'; } );

return 0;
}

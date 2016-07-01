/*
The army wants to recruit people from its selective
service list. They have decided to recruit those that
signed up for the service in 1997 starting from the
oldest down to the youngest. Generate an arbitrary amount
of people (give them data members such as age and yearEnrolled)
into a vector. Partition the vector so that those who
enrolled in 1997 are ordered at the beginning of the list,
starting from the youngest to the oldest, and leave the
remaining part of the list sorted according to age.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct Recruit {
	std::string name;
	int age;
	int year_enrolled;

	Recruit(std::string n, int a, int y)
		: name(n), age(a), year_enrolled(y) {}
};

std::ostream& operator<<(std::ostream& out, const Recruit& r) {
	out << r.name << '\t' << r.age << '\t' << r.year_enrolled;
	return out;
}

int main() {

	std::vector<Recruit> recruits;

	recruits.emplace_back( Recruit("John Doe", 		40, 1997) );
	recruits.emplace_back( Recruit("Alex Smith", 	42, 1996) );
	recruits.emplace_back( Recruit("Jack Doe",		45, 1998) );
	recruits.emplace_back( Recruit("Sam Black", 	47, 1997) );
	recruits.emplace_back( Recruit("Will Burrows",	44, 1995) );
	recruits.emplace_back( Recruit("Mike Jordan",	46, 1997) );
	recruits.emplace_back( Recruit("Bruce Willis",	41, 1999) );
	recruits.emplace_back( Recruit("Larry Hill",	44, 1997) );
	recruits.emplace_back( Recruit("Walter White", 	43, 1996) );

	std::sort(recruits.begin(), recruits.end(),
		[](const Recruit& x, const Recruit& y) { return x.age < y.age; }
	);

	std::stable_partition(recruits.begin(), recruits.end(),
		[](const Recruit& r) { return r.year_enrolled == 1997; }
	);

	for (auto r : recruits)
		std::cout << r << '\n';

return 0;
}

/*
Write an operator<< inserter for the Person struct that
can be used to display records in a format for easy reading.
Demonstrate it by writing data out to a file.

Make a Person struct with fields such as name, age,
address, etc. Make the string fields fixed-size arrays.
The social security number will be the key for each record.
Implement the following Database class.

Write some Person records to disk (do not keep them all in memory).
When the user requests a record, read it off the disk and return it.
The I/O operations in the DataBase class use read( ) and write( )
to process all Person records.
*/

#include <iostream>
#include <fstream>

struct Person {
	size_t	record_number;
	char 	name[20];
	char 	surname[50];
	size_t 	age;
	char 	address[100];
	size_t 	ssn;
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
	return os << p.record_number << '\t'
			  << p.name << '\t'
			  << p.surname << '\t'
			  << p.age << '\t'
			  << p.address << '\t'
			  << p.ssn << '\n';
}

class DataBase {
public:
	DataBase(std::string name) : base_name(name) {}
	// Find where a record is on disk
	size_t query(size_t ssn);
	// Return the person at rn (record number)
	Person retrieve(size_t rn);
	// Record a record on disk
	void add(const Person& p);
private:
	std::string base_name;
};

size_t DataBase::query(size_t ssn) {
	size_t rn = 0;
	Person temp;
	std::ifstream base(base_name.c_str(), std::ios::binary);

	while( base.read( reinterpret_cast<char*>(&temp), sizeof(temp)) ) {
		if (temp.ssn == ssn) {
			rn = temp.record_number;
			break;
		}
	}

	base.close();
	return rn;
}

Person DataBase::retrieve(size_t rn) {
	Person temp;
	std::ifstream base(base_name.c_str(), std::ios::binary);
	if (rn != 0) {
		base.seekg(sizeof(temp) * (rn - 1));
		base.read( reinterpret_cast<char*>(&temp), sizeof(temp));
		base.close();
	}
	return temp;
}

void DataBase::add(const Person& p) {
    std::ofstream base(base_name.c_str(), std::ios::binary|std::ios::app);
    base.write(reinterpret_cast<const char*>(&p), sizeof(p));
    base.close();
}


int main() {

	DataBase db("ex08.bin");

	Person  s1{1,	"John",		"Levinsoners",	21,	"Dawson drive, 85",		5743581};
	Person  s2{2,	"Lisa",		"Masterson",	17,	"Park street, 231",		8372767};
	Person  s3{3,	"Martin",	"Lawrence",		44,	"South avenue, 111",	8683473};
	Person  s4{4,	"Emily",	"Keaney",		19,	"Redmond street, 85",	9828856};
	Person  s5{5,	"Michael",	"Parks",		41,	"Brightons alley, 2",	9834848};
	Person  s6{6,	"John",		"Levinsoners",	65,	"Milestone parkway, 3",	4239548};

	db.add(s1); db.add(s2); db.add(s3); db.add(s4); db.add(s5); db.add(s6);

	int n;
	std::cout << "Please enter SSN for a record which you want to retrieve: ";
	std::cin >> n;

	Person p = db.retrieve( db.query(n) );

	std::ofstream result("ex09.txt");
	result << p;

return 0;
}

/*
Suppose you are given line-oriented data in a file
formatted as follows:

The heading of each section is a region, and every
line under that heading is a seller in that region.
Each comma-separated field represents the data about
each seller. The first field in a line is the SELLER_ID
which unfortunately was written out in hexadecimal format.
The second is the PHONE_NUMBER (notice that some are
missing area codes). LAST_NAME and FIRST_NAME then follow.
TOTAL_SALES is the second to the last column. The last
column is the decimal amount of the total sales that the
seller represents for the company. You are to format the
data on the terminal window so that an executive can easily
interpret the trends. Sample output is given below.

						   Australia
              ---------------------------------

*Last Name*  *First Name*   *ID*    *Phone*        *Sales*   *Percent*

Langler       Tyson          24150   766-723-0284     31.24   4.21E-02
Oneill        Zeke           11159   XXX-758-6701    553.43   7.47E-01
(etc.)

SELLER_ID (in hex) - PHONE_NUMBER (without area code) - LAST_NAME - FIRST_NAME - TOTAL_SALES - PERCENT
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

bool is_country(const std::string& str) {
	return ( str.find(".") == std::string::npos );
}

void print_header(const std::string& str) {
	std::cout << "\n\t\t\t\t\t" << str
			  << "\n\t\t\t\t-------------------------\n"
			  << "*Last Name*\t*First Name*\t*ID*\t*Phone*\t\t*Sales*\t\t*Percent*\n";
}

std::string format_phone(const std::string str) {

	std::string formated = str;

	if (str.size() == 10) {
		formated.insert(6,"-");
		formated.insert(3,"-");
	}
	else {
		formated.insert(3,"-");
		formated.insert(0,"XXX-");
	}

	return formated;
}

void parse_record(const std::string line) {

	std::string temp = line;

    int id;
    std::string phone;
    std::string lastname;
    std::string firstname;
    double sales;
    double percent;

    std::replace(temp.begin(), temp.end(), ',', ' ');
    std::stringstream ss(temp);

	ss >> std::hex >> id >> std::dec >> phone >> lastname >> firstname >> sales >> percent;

	std::cout << std::left << std::setw(16) << lastname << std::setw(16) << firstname <<  std::setw(9) << id;
	std::cout  << std::setw(10) << std::right << format_phone(phone);
	std::cout << std::fixed << std::right << std::setprecision(2) << std::setw(11) << sales;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::right << std::scientific << std::setw(17) << percent;
	std::cout << '\n';
}

int main() {

    std::ifstream in("ex15.txt", std::ios::in);

    std::string buf;

	while (in >> buf) {

		if (is_country(buf))
			print_header(buf);
        else
        	parse_record(buf);
    }

return 0;
}

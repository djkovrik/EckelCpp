/*
After being separated for one picture, the bride and
groom decided they wanted to be together for all of them.
Find all the possible ways to arrange the people for the
picture if the bride and groom (Jon Brittle and Jane Brittle)
are to be next to each other.

Previous exercise:
Using the following names:

Jon Brittle
Jane Brittle
Mike Brittle
Sharon Jensen
George Jensen
Evelyn Jensen

Find all the possible ways to arrange them for a wedding picture.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {

	std::vector<std::string> males;
	std::vector<std::string> females;

	males.push_back("Jon Brittle");
	males.push_back("Mike Brittle");
	males.push_back("George Jensen");

	females.push_back("Jane Brittle");
	females.push_back("Sharon Jensen");
	females.push_back("Evelyn Jensen");

	do {
		 do {

			 bool print = false;

			 for (size_t i = 0; i < males.size(); ++i)
				 if (males.at(i) == "Jon Brittle" && females.at(i) == "Jane Brittle")
					 print = true;

			 if (print) {
				 std::cout << "Snapshot:\n";

				 for (size_t i = 0; i < males.size(); ++i)
				 	std::cout << males.at(i) + " + " + females.at(i) + "\n";
			 }

		 } while ( std::next_permutation(females.begin(), females.end()) );
	} while ( std::next_permutation(males.begin(), males.end()) );

return 0;
}

/*
Create a framework (that is, use the Template Method pattern)
that takes a list of file names on the command line. It opens
each file except the last for reading, and the last file it opens
for writing. The framework will process each input file using
an undetermined policy and write the output to the last file.
Inherit to customize this framework to create two separate
applications:

 1) Converts all the letters in each file to uppercase.
 2) Searches the files for words given in the first file.
*/

#ifndef EX06_H_
#define EX06_H_

#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

class AppFramework {
protected:
	virtual void file_handler(std::string , std::ofstream& ) = 0;
public:
	void templateMethod(int argc, char** argv) {
		std::vector<std::string> arg_list;

		for (int i = 1; i < argc; i++)
			arg_list.emplace_back(std::string(argv[i]));

		std::ofstream result( arg_list.back(), std::ios::app );

		std::for_each(arg_list.begin(), arg_list.end() - 1,
			[&](const std::string& filename) {
				file_handler(filename, result);
			}
		);
	}

	virtual ~AppFramework() {}
};

#endif /* EX06_H_ */

/*
Modify Exercise 6 to use Strategy instead of Template Method.

Exercise 6:
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

#ifndef EX07_H_
#define EX07_H_

#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

class FileStrategy {
public:
	virtual void file_handler(std::string , std::ofstream& ) = 0;
	virtual ~FileStrategy() {}
};

class ToLower : public FileStrategy {
public:
	void file_handler(std::string filename, std::ofstream& result) {

		std::ifstream file(filename, std::ios::in);

		std::string buf;

		while (getline(file, buf)) {
			std::transform(buf.begin(), buf.end(), buf.begin(), ::tolower);
			result << buf << '\n';
		}

		file.close();
	}
};

class Searcher : public FileStrategy {
public:
	void file_handler(std::string filename, std::ofstream& result) {

		std::ifstream file(filename, std::ios::in);

		static int file_counter = 0;
		static std::vector<std::string> words;
		std::string buf;

		if (file_counter++ == 0) {

			while (file >> buf)
				words.push_back(buf);

			return;
		}

		int line_counter = 0;
		while (getline(file, buf)) {
			++line_counter;

			for (auto word : words) {
				auto pos = buf.find(word);

				while (pos != std::string::npos) {
					result << word << " has been found, file: " << filename
						   << ", line: " << line_counter
						   << ", pos: " << pos << '\n';

					pos = buf.find(word, pos + 1);
				}
			}
		}

		file.close();
	}
};

class Context {
public:
	Context(FileStrategy& fstr) : strategy(fstr) {}

	void handler(int argc, char** argv) {
		std::vector<std::string> arg_list;

			for (int i = 1; i < argc; i++)
				arg_list.emplace_back(std::string(argv[i]));

			std::ofstream result( arg_list.back(), std::ios::app );

			std::for_each(arg_list.begin(), arg_list.end() - 1,
				[&](const std::string& filename) {
					strategy.file_handler(filename, result);
				}
			);
	}

private:
	FileStrategy& strategy;
};

#endif /* EX07_H_ */

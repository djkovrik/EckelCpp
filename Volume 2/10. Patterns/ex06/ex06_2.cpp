#include <iostream>
#include "ex06.h"

class MyApp2 : public AppFramework {
protected:
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

int main(int argc, char** argv) {

	MyApp2 app2;
	app2.templateMethod(argc, argv);

return 0;
}

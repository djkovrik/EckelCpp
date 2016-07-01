#include <iostream>
#include "ex06.h"

class MyApp1 : public AppFramework {
protected:
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

int main(int argc, char** argv) {

	MyApp1 app1;
	app1.templateMethod(argc, argv);

return 0;
}

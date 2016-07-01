/*
Starting with SingletonPattern.cpp, create a class
that provides a connection to a service that stores
and retrieves data from a configuration file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class SettingsFile {
	static SettingsFile s;

	std::string file_name;
	std::fstream file;
	std::map<std::string, std::string> settings;

	SettingsFile(std::string fname) : file_name(fname) {

		std::fstream file(file_name, std::ios::in);

		std::string buf;

		while (std::getline(file, buf)) {
			auto pos = buf.find("=");

			if (pos != std::string::npos) {
				auto str1 = buf.substr(0, pos);
				auto str2 = buf.substr(pos + 1);
				settings[str1] = str2;
			}
		}
		//std::cout << "Settings loaded, size: " << settings.size() << '\n';
		file.close();
	}

	~SettingsFile() {

		file.open(file_name, std::ios::out);

		for (auto iter : settings)
			file << iter.first << '=' << iter.second << '\n';

		file.close();
		settings.clear();
	}

	SettingsFile& operator=(SettingsFile&) = delete;
	SettingsFile(const SettingsFile&) = delete;

public:
	static SettingsFile& instance() { return s; }

	static void print_all() {
		for (const auto x : s.settings)
			std::cout << x.first << '=' << x.second << '\n';
	}

	void set_parameter(std::string key, std::string value) {
		settings[key] = value;
	}

	std::string get_parameter(std::string key) {
		return settings[key];
	}

	void erase_parameter(std::string key) {
		settings.erase(key);
	}

};

SettingsFile SettingsFile::s("ex02.cfg");

int main() {

	SettingsFile::print_all();
	std::cout << "------------\n";

	SettingsFile& s1 = SettingsFile::instance();
	std::cout << "Option2 = " << s1.get_parameter("Option2") << '\n';

	// some code here...
	// Adding new option with another instance
	SettingsFile& s2 = SettingsFile::instance();
	s2.set_parameter("SomeNewOption", "1234567");
	// And deleting Option1
	s2.erase_parameter("Option1");

	std::cout << "------------\n";
	std::cout << "Updated content:\n";
	SettingsFile::print_all();

return 0;
}

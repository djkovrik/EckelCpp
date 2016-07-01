/*
Break a text file up into an input stream of words (keep it simple:
just break the input stream on white space). Create one Builder
that puts the words into a set, and another that produces a map
containing words and occurrences of those words
(that is, it does a word count).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

class ListBuilder {
public:
	ListBuilder() = default;
	virtual ~ListBuilder() = default;

	virtual void push_string(std::string str) = 0;
	virtual void print_list() = 0;
};

class ListFromSet : public ListBuilder {
public:
	ListFromSet() : ListBuilder() {}
	void push_string(std::string str) { st.insert(str); }

	void print_list() {
		for (const auto& element : st)
			std::cout << element << '\n';
	}

private:
	std::set<std::string> st;
};

class ListFromMap : public ListBuilder {
public:
	ListFromMap() : ListBuilder() {}
	void push_string(std::string str) { ++mp[str]; }

	void print_list() {

		std::stringstream ss;

		for (const auto& pair : mp) {
			ss << pair.first << " - " << pair.second << '\n';
			std::cout << ss.str() << '\n';
			ss.clear();
		}
	}

private:
	std::map<std::string, int> mp;
};

class ListUser {
public:
	ListUser(ListBuilder* ptr) : builder(ptr) {}
	void set_list_builder(ListBuilder* ptr) { builder = ptr; }

	void make_the_list(std::string filename) {

		std::ifstream source(filename, std::ios::in);
		std::string buf;

		while (source >> buf)
			builder->push_string(buf);

		builder->print_list();
	}

private:
	ListBuilder* builder;
};

int main() {

	ListFromMap m;
	ListUser user(&m);
	user.make_the_list("ex15.cpp");


	ListFromSet s;
	user.set_list_builder(&s);
	user.make_the_list("ex15.cpp");



return 0;
}

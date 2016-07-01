/*
Using the characters

"~`!@#$%^&*( )_-+=}{[]|\:;"'<.>,?/",

generate a codebook using an input file given on the
command line as a dictionary of words. Don’t worry about
stripping off the non-alphabetic characters nor worry about
case of the words in the dictionary file. Map each permutation
of the character string to a word such as the following:

"=')/%[}]|{*@?!"`,;>&^-~_:$+.#(<\"   apple
"|]\~>#.+%(/-_[`':;=}{*"$^!&?),@<"   carrot
"@=~['].\/<-`>#*)^%+,";&?!_{:|$}("   Carrot

etc.

Make sure that no duplicate codes or words exist in your code book.
Use lexicographical_compare( ) to perform a sort on the codes.
Use your code book to encode the dictionary file. Decode your
encoding of the dictionary file, and make sure you get the same
contents back.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <utility>
#include <map>

int main() {

	std::string key = "~`!@#$%^&*()_-+=}{[]|\\:;\"\'<.>,?/";
	std::map<std::string, std::string> codes;
	std::vector<std::string> dictionary;

	std::ifstream source("ex20_src.txt", std::ios::in);
	std::ofstream encoded("ex20_encoded.txt", std::ios::out);
	std::ofstream decoded("ex20_decoded.txt", std::ios::out);

	std::string buf;

	while (source >> buf)
		dictionary.push_back(buf);

	std::sort(dictionary.begin(), dictionary.end());
	auto last = std::unique(dictionary.begin(), dictionary.end());
	dictionary.erase(last, dictionary.end());

	std::sort(dictionary.begin(), dictionary.end(),
		[](const std::string a, const std::string b) { return a.size() > b.size(); }
	);

	std::random_shuffle(key.begin(), key.end());

	for (const auto& d : dictionary) {

		while (codes.find(key) != codes.end())
			std::random_shuffle(key.begin(), key.end());
		codes.insert(std::make_pair(key, d));
	}

	source.clear();
	source.seekg(0, std::ios::beg);

	std::ostringstream os;
	os << source.rdbuf();
	std::string content = os.str();

	std::map<std::string, std::string> reversed_codes;

	for (const auto& m : codes)
		reversed_codes.insert( make_pair(m.second, m.first) );

	for(const auto& word : dictionary) {
		while( content.find(word) != std::string::npos ) {
			content.replace( content.find(word), word.size(), reversed_codes[word] );
		}
	}

	encoded << content;
	encoded.close();

	std::ifstream source_enc("ex20_encoded.txt", std::ios::in);
	std::ostringstream os_enc;
	os_enc << source_enc.rdbuf();
	std::string content_enc = os_enc.str();

	for (const auto& line : codes) {
		while( content_enc.find(line.first) != std::string::npos )
			content_enc.replace( content_enc.find(line.first), line.first.size(), codes[line.first] );
	}

	decoded << content_enc;

return 0;
}

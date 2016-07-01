/*
Create a kind of “hangman” game. Create a class
that contains a char and a bool to indicate whether
that char has been guessed yet. Randomly select a
word from a file, and read it into a vector of your
new type. Repeatedly ask the user for a character
guess, and after each guess, display the characters
in the word that have been guessed, and display
underscores for the characters that haven’t.
Allow a way for the user to guess the whole word.
Decrement a value for each guess, and if the user
can get the whole word before the value goes to zero,
they win.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

class CharactersPool {
public:
	CharactersPool() {
		// initialize pool
		for (char ch = 'a'; ch <='z'; ch++)
			letters.insert(std::make_pair(ch, false));
	}

	bool check_letter(char c) { return letters[std::tolower(c)]; }
	void add_letter(char c) { letters[c] = true; }

private:
	std::map<char, bool> letters;
};

int main() {

	std::srand(std::time(0));

	std::ifstream source("ex15_dict.txt", std::ios::in);
	std::vector<std::string> dictionary;
	std::string buf;

	while (source >> buf)
		dictionary.push_back(buf);

	std::string keyword = dictionary.at( std::rand() % dictionary.size() );
	int attempts = keyword.size() * 2;

	CharactersPool pool;

	while (attempts-- > 0) {

		if (attempts == 0)
			break;

		std::cout << "Tries left: " << attempts << ", the word is: ";

		std::for_each(keyword.begin(), keyword.end(),
			[&pool](char c) {
				if ( pool.check_letter(c) )
					std::cout << c << ' ';
				else
					std::cout << '_' << ' ';
			}
		);

		int choice = 0;
		std::cout << "\nWhat you want to do?\n"
				  << " 1. Enter new character.\n"
				  << " 2. Try to guess the whole word.\n";
		std::cin >> choice;

		if (choice == 1) {
			std::cout << "Please enter new character: ";
			char ch;
			std::cin >> ch;

			if (std::isalpha(ch) != 0)
				pool.add_letter( std::tolower(ch) );
		}
		else {
			std::string guess;
			std::cout << "Your guess is: ";
			std::cin >> guess;

			if (keyword == guess) {
				std::cout << "Bingo!\n";
				return 0;
			} else {
				std::cout << "You are wrong!\n";
				continue;
			}
		}
	}
	std::cout << "You lost! The word is " << keyword << '\n';
return 0;
}

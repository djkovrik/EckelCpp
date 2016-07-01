/*
Modify the previous exercise to place a prepareInstrument( )
function in the base class, which calls appropriate functions
(such as clearSpitValve( ), when it fits). Note that
prepareInstrument( ) is a sensible function to place in the
base class, and it eliminates the need for RTTI in the
previous exercise.

Exercise 4:
Modify the Instrument hierarchy from Chapter 14 of
Volume 1 by first copying Wind5.cpp to a new location.
Now add a virtual clearSpitValve( ) function to the Wind
class, and redefine it for all the classes inherited from
Wind. Instantiate a vector to hold Instrument pointers,
and fill it with various types of Instrument objects
created using the new operator. Now use RTTI to move
through the container looking for objects in class
Wind, or derived from Wind. Call the clearSpitValve( )
function for these objects. Notice that it would unpleasantly
confuse the Instrument base class if it contained a
clearSpitValve( ) function.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>

enum note { middleC, Csharp, Cflat };

class Instrument {
public:
	virtual void play(note) const = 0;
	virtual std::string what() const = 0;
	virtual void adjust(int) = 0;
	~Instrument(){}
	virtual void prepareInstrument() {  std::cout << "Instrument::prepareInstrument()" << std::endl; }
};

class Wind : public Instrument {
public:
	void play(note) const {
		std::cout << "Wind::play" << std::endl;
	}
	std::string what() const { return "Wind"; }
	void adjust(int) {}

	virtual void clearSpitValve() { std::cout << "Wind::clearSpitValve()" << std::endl; }
	void prepareInstrument() { this->clearSpitValve(); }
};

class Percussion : public Instrument {
public:
	void play(note) const {
		std::cout << "Percussion::play" << std::endl;
	}
	std::string what() const { return "Percussion"; }
	void adjust(int) {}
};

class Stringed : public Instrument {
public:
	void play(note) const {
		std::cout << "Stringed::play" << std::endl;
	}
	std::string what() const { return "Stringed"; }
	void adjust(int) {}
};

class Brass : public Wind {
public:
	void play(note) const {
		std::cout << "Brass::play" << std::endl;
	}
	std::string what() const { return "Brass"; }
	void clearSpitValve() override { std::cout << "Brass::clearSpitValve()" << std::endl; }
};

class Woodwind : public Wind {
public:
	void play(note) const {
		std::cout << "Woodwind::play" << std::endl;
	}
	std::string what() const { return "Woodwind"; }
	void clearSpitValve() override { std::cout << "Woodwind::clearSpitValve()" << std::endl; }
};


int main() {

	std::srand(std::time(0));

	std::vector<Instrument*> vi;

	std::generate_n(std::back_inserter(vi), 20,
		[]() -> Instrument* {
			if (std::rand()%5 == 0)
				return new Wind();
			else if (std::rand()%5 == 1)
				return new Percussion();
			else if (std::rand()%5 == 2)
				return new Stringed();
			else if (std::rand()%5 == 3)
				return new Brass();
			else
				return new Woodwind();
		}
	);

	for (auto instr : vi) {
		instr->prepareInstrument();
	}

return 0;
}

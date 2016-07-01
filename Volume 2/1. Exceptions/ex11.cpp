/*
Write a Garage class that has a Car that is having
troubles with its Motor. Use a function-level try
block in the Garage class constructor to catch an
exception (thrown from the Motor class) when its
Car object is initialized. Throw a different
exception from the body of the Garage constructor’s
handler and catch it in main( ).
*/

#include <iostream>
#include <cstdlib>

class MotorException{};

class Garage {
public:
	Garage()
		try : c() {}
		catch (MotorException& m) {
			std::cout << "MotorException detected\n";
			std::exit(0);
		}
	class Car {
	public:
		Car() : m() {}
		class Motor {
		public:
			Motor() { throw MotorException(); }
		};
	private:
		Motor m;
	};
private:
	Car c;
};

int main() {

	Garage g;

return 0;
}

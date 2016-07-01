/*
Create a variation of SingletonPattern.cpp where all
functions are static. Is the instance( ) function still
necessary in this case?
*/

#include <iostream>

using namespace std;

class Singleton {
	static Singleton s;
	int i;
	Singleton(int x) : i(x) { }
	Singleton& operator=(Singleton&);	// Disallowed
	Singleton(const Singleton&);			 // Disallowed
public:
	//static Singleton& instance() { return s; }
	static int getValue() { return s.i; }
	static void setValue(int x) { s.i = x; }
};

Singleton Singleton::s(47);

int main() {
	//Singleton& s = Singleton::instance();
	cout << Singleton::getValue() << endl;
	//Singleton& s2 = Singleton::instance();
	Singleton::setValue(9);
	cout << Singleton::getValue() << endl;
} ///:~

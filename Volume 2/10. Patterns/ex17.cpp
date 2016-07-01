/*
Change InnerClassIdiom.cpp so that Outer uses multiple
inheritance instead of the inner class idiom.
*/
#include <iostream>
#include <string>

using namespace std;

class Poingable {
public:
	virtual void poing() = 0;
	virtual ~Poingable() {}
};

void callPoing(Poingable& p) {
	p.poing();
}

class Bingable {
public:
	virtual void bing() = 0;
	virtual ~Bingable() {}
};

void callBing(Bingable& b) {
	b.bing();
}

class Outer : public Bingable, public Poingable{
	string name;
public:
	Outer(const string& nm)	: Bingable(), Poingable(), name(nm)  {}

	void poing() { cout << "poing called for " << name << endl;	}
	void bing() { cout << "bing called for " << name << endl; }
};

int main() {
	Outer x("Ping Pong");

	callPoing(x);
	callBing(x);
}

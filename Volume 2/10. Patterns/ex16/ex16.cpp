#include <iostream>
#include "Observable.h"

class Bank : public Observable {
public:
	void notify_observers() {
		std::cout << "Bank has been closed.\n";
		Observable::notify_observers();
	}
};

class Robber : public Observer {
public:
	Robber(std::string n) : name(n) {}

	void update(Observable* o) {
		std::cout << name << " says: time to rob!\n";
	}
private:
	std::string name;
};

class Thug : public Observer {
public:
	Thug(std::string n) : name(n) {}

	void update(Observable* o) {
			std::cout << name << " now knows that the bank is closed!\n";
		}
private:
	std::string name;
};


int main() {

	Robber r("James Bond");
	Thug t("John Doe");

	Bank b;

	b.add_observer(r);
	b.add_observer(t);

	b.notify_observers();

return 0;
}

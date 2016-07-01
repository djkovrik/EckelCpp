/*
Add a new type of GameEnvironment called GnomesAndFairies to AbstractFactory.cpp.
*/

#include <iostream>
using namespace std;

class Obstacle {
public:
	virtual void action() = 0;
	virtual ~Obstacle() {}
};

class Player {
public:
	virtual void interactWith(Obstacle*) = 0;
	virtual ~Player() {}
};

class Kitty: public Player {
	virtual void interactWith(Obstacle* ob) {
		cout << "Kitty has encountered a ";
		ob->action();
	}
};

class KungFuGuy: public Player {
	virtual void interactWith(Obstacle* ob) {
		cout << "KungFuGuy now battles against a ";
		ob->action();
	}
};

class Gnome: public Player {
	virtual void interactWith(Obstacle* ob) {
		cout << "Gnome catches a ";
		ob->action();
	}
};


class Puzzle: public Obstacle {
public:
	void action() { cout << "Puzzle" << endl; }
};

class NastyWeapon: public Obstacle {
public:
	void action() { cout << "NastyWeapon" << endl; }
};

class Fairie: public Obstacle {
public:
	void action() { cout << "Fairie" << endl; }
};

// The abstract factory:
class GameElementFactory {
public:
	virtual Player* makePlayer() = 0;
	virtual Obstacle* makeObstacle() = 0;
	virtual ~GameElementFactory() {}
};

// Concrete factories:
class KittiesAndPuzzles : public GameElementFactory {
public:
	virtual Player* makePlayer() { return new Kitty; }
	virtual Obstacle* makeObstacle() { return new Puzzle; }
};

class KillAndDismember : public GameElementFactory {
public:
	virtual Player* makePlayer() { return new KungFuGuy; }
	virtual Obstacle* makeObstacle() {
		return new NastyWeapon;
	}
};

class GnomesAndFairies : public GameElementFactory {
public:
	virtual Player* makePlayer() { return new Gnome; }
	virtual Obstacle* makeObstacle() { return new Fairie; }
};

class GameEnvironment {
	GameElementFactory* gef;
	Player* p;
	Obstacle* ob;
public:
	GameEnvironment(GameElementFactory* factory)
	: gef(factory), p(factory->makePlayer()),
		ob(factory->makeObstacle()) {}
	void play() { p->interactWith(ob); }
	~GameEnvironment() {
		delete p;
		delete ob;
		delete gef;
	}
};

int main() {
	GameEnvironment
		g1(new KittiesAndPuzzles),
		g2(new KillAndDismember),
		g3(new GnomesAndFairies);
	g1.play();
	g2.play();
	g3.play();
}


#ifndef STASH_H
#define STASH_H

#include <vector>

using std::vector;

struct Stash {
	Stash() {}
	int size;
	int quantity;
	int next;

	vector<char> storage;

	void initialize(int size);
	int add(const void* element);
	void* fetch(int index);
	int count();
	void inflate(int increase);
};

#endif // STASH_H
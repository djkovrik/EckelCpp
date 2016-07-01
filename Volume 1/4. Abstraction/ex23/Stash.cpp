#include "Stash.h"
#include <iostream>
#include <cassert>

using namespace std;

const int increment = 100;

void Stash::initialize(int sz) {
	size = sz;
	quantity = 0;
	next = 0;
	storage.reserve(100);
}

void Stash::inflate(int increase) {
	assert(increase > 0);
	int newQuantity = quantity + increase;
	int newBytes = newQuantity * size;
	storage.resize(newBytes);
}

int Stash::add(const void* element) {

	if(next >= quantity)
		inflate(increment);

	int startBytes = next * size;

	unsigned char* e = (unsigned char*)element;

	for(int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];

	next++;
	return(next - 1);
}


void* Stash::fetch(int index) {

	assert(0 <= index);
	if(index >= next)
		return 0;

	return &(storage[index * size]);
}

int Stash::count() {
	return next;
}


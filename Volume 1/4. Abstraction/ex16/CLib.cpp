//: C04:CLib.cpp {O}
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Implementation of example C-like library
// Declare structure and functions:
#include "CLib.h"
#include <iostream>
#include <cassert>

using namespace std;

const int increment = 100;

void initialize(CStash* s, int sz) {
	s->size = sz;
	s->quantity = 0;
	s->storage.reserve(100);
	s->next = 0;
}

int add(CStash* s, const void* element) {
	if(s->next >= s->quantity)
		inflate(s, increment);

	int startBytes = s->next * s->size;
	unsigned char* e = (unsigned char*)element;
	for(int i = 0; i < s->size; i++)
		s->storage[startBytes + i] = e[i];
	s->next++;
	return(s->next - 1); // Index number
}

void* fetch(CStash* s, int index) {

	assert(0 <= index);
	if(index >= s->next)
		return 0;

	return &(s->storage[index * s->size]);
}

int count(CStash* s) {
	return s->next;
}

void inflate(CStash* s, int increase) {
	assert(increase > 0);
	int newQuantity = s->quantity + increase;
	int newBytes = newQuantity * s->size;

	s->storage.resize(newBytes);
}

void cleanup(CStash* s) {
	if(! (s->storage.empty()) ) {
	 cout << "freeing storage" << endl;
	 s->storage.clear();
	}
}

//: C07:Stash3.cpp {O}
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Function overloading
#include "Stash3.h"
#include <iostream>
#include <cassert>
using namespace std;
const int increment = 100;

Stash::Stash(int sz) : storage(new Mem(sz)) {
    block_size = sz;
    blocks_quantity = 0;
    next = 0;
}

Stash::Stash(int sz, int initQuantity) : storage(new Mem(sz * initQuantity)) {

    block_size = sz;
    blocks_quantity = 0;
    next = 0;
    inflate(initQuantity);
}

Stash::~Stash() {
    if(storage != 0) {
        cout << "Freeing storage..." << endl;
        delete storage;
    }
}

void Stash::inflate(int increase) {

    int newQuantity = blocks_quantity + increase;
    blocks_quantity = newQuantity;

    int newMemory = newQuantity * block_size;
    storage->ensureMinSize(newMemory);

}

int Stash::add(void* element) {

    if(next >= blocks_quantity)
        inflate(increment);

    // Copy element into storage,
    // starting at next empty space:
    int startBytes = next * block_size;
    unsigned char* e = (unsigned char*)element;
    byte* temp = storage->pointer();

    for(int i = 0; i < block_size; i++)
        *(temp + startBytes + i) = e[i];

    next++;
    return(next - 1); // Index number
}

void* Stash::fetch(int index) {

    if(index >= next)
        return 0; // To indicate the end

    // Produce pointer to desired element:

    byte* temp = storage->pointer();
    return (temp + index * block_size);
}

int Stash::count() {
    return next; // Number of elements in CStash
}

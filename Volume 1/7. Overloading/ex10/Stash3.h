//: C07:Stash3.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Function overloading
#ifndef STASH3_H
#define STASH3_H

#include "Mem2.h"

class Stash {
    int block_size;         // Block size
    int blocks_quantity;    // Blocks quantity
    int next;               // Next empty space

    Mem* storage;           // Storage, instead of unsigned char*

    void inflate(int increase);
public:
    Stash(int block_size); // Zero quantity
    Stash(int block_size, int initQuantity);
    ~Stash();
    int add(void* element); // Adds element
    void* fetch(int index); // Returns element[index]
    int count();            // Returns size
};
#endif

//: C07:Mem.cpp {O}
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include "Mem2.h"
#include <cstring>
using namespace std;

Mem::Mem(int sz) {

    mem = 0; size = 0;

    if (sz != 0)
        ensureMinSize(sz);
}

Mem::~Mem() { delete []mem; }

int Mem::msize() { return size; }

void Mem::ensureMinSize(int minSize) {

    if(size < minSize) {
        byte* newmem = new byte[minSize];
        memset(newmem + size, 0, minSize - size);
        memcpy(newmem, mem, size);
        delete []mem;
        mem = newmem;
        size = minSize;
  }
}

byte* Mem::pointer(int minSize) {
    if (minSize != 0)
        ensureMinSize(minSize);

  return mem;
}

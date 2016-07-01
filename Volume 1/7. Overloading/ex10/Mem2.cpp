#include "Mem2.h"
#include <cstring>
#include <iostream>
using namespace std;

Mem::Mem(int sz) {

    memory = 0; memory_size = 0;

    if (sz != 0)
        ensureMinSize(sz);
}

Mem::~Mem() { delete []memory; }

int Mem::msize() { return memory_size; }


void Mem::ensureMinSize(int minSize) {

    if(memory_size < minSize) {
        byte* newmem = new byte[minSize];
        memset(newmem + memory_size, 0, minSize - memory_size);
        memcpy(newmem, memory, memory_size);
        delete []memory;
        memory = newmem;
        memory_size = minSize;
  }
}


byte* Mem::pointer(int minSize) {

    if (minSize != 0)
        ensureMinSize(minSize);

    return memory;
}

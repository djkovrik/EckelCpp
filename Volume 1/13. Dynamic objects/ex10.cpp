/**
Execute NewHandler.cpp on your machine to see the resulting count.
Calculate the amount of free store available for your program.
**/
#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

int count = 0;

void out_of_memory() {
    cerr << "memory exhausted after " << count
         << " allocations!" << endl;
    cerr << "Available memory: " << count * sizeof(int) * 1000 / 1024 / 1024 << " Mb" << endl;
    exit(1);
}

int main() {
    set_new_handler(out_of_memory);
    while(1) {
        count++;
    new int[1000]; // Exhausts memory
  }
} ///:~

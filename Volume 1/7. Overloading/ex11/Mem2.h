//: C07:Mem2.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#ifndef MEM2_H
#define MEM2_H
typedef unsigned char byte;

class Mem {
  byte* mem;
  byte* initial_ptr;
  bool not_initialized;
  int size;

public:
  Mem(int sz = 0);
  ~Mem();

  int msize();
  void ensureMinSize(int minSize);
  byte* pointer(int minSize = 0);
  byte* init_ptr() {return initial_ptr;}
  bool moved(byte* ptr);
};
#endif // MEM2_H ///:~

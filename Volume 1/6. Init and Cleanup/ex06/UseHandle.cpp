/**
Modify the Handle.h, Handle.cpp, and UseHandle.cpp files at the end 
of Chapter 5 to use constructors and destructors.
**/

//: C05:UseHandle.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
//{L} Handle
// Use the Handle class
#include "Handle.h"

int main() {
  Handle u;
  //u.initialize();
  u.read();
  u.change(1);
  //u.cleanup();
} ///:~

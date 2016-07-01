//: C06:Generators.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Different ways to fill sequences.
#ifndef GENERATORS_H
#define GENERATORS_H
#include <cstring>
#include <set>
#include <cstdlib>
#include <iostream>

// A generator that can skip over numbers:
class SkipGen {
  int i;
  int skp;
public:
  SkipGen(int start = 0, int skip = 1)
  : i(start), skp(skip) {}
  int operator()() {
    int r = i;
    i += skp;
    return r;
  }
};

// Generate unique random numbers from 0 to mod:
class URandGen {
  std::set<float> used;
  int limit;
public:
  URandGen(int lim) : limit(lim) {}
  float operator()() {
    while(true) {
      float f = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / limit));
      if(used.find(f) == used.end()) {
        used.insert(f);
        return f;
      }
    }
  }
};

// Produces random characters:
class CharGen {
  static const char* source;
  static const int len;
public:
  char operator()() {
    return source[std::rand() % len];
  }
};
#endif // GENERATORS_H ///:~

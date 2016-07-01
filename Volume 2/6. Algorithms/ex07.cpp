/*
Modify FunctionObjects.cpp so that it uses float instead of int.
*/

//: C06:FunctionObjects.cpp {-bor}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Illustrates selected predefined function object
// templates from the Standard C++ library.
//{L} Generators
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& dest,
  UnaryFunc f) {
  transform(source.begin(), source.end(), dest.begin(), f);
}

template<typename Contain1, typename Contain2,
  typename BinaryFunc>
void testBinary(Contain1& src1, Contain1& src2,
  Contain2& dest, BinaryFunc f) {
  transform(src1.begin(), src1.end(),
    src2.begin(), dest.begin(), f);
}

// Executes the expression, then stringizes the
// expression into the print statement:
#define T(EXPR) EXPR; print(r.begin(), r.end(), \
  "After " #EXPR);
// For Boolean tests:
#define B(EXPR) EXPR; print(br.begin(), br.end(), \
  "After " #EXPR);

// Boolean random generator:
struct BRand {
  bool operator()() { return rand() % 2 == 0; }
};

int main() {
  const int SZ = 10;
  const int MAX = 50;
  vector<float> x(SZ), y(SZ), r(SZ);
  // An integer random number generator:
  URandGen urg(MAX);
  srand(time(0));  // Randomize
  generate_n(x.begin(), SZ, urg);
  generate_n(y.begin(), SZ, urg);
  // Add one to each to guarantee nonzero divide:
  transform(y.begin(), y.end(), y.begin(),
    bind2nd(plus<float>(), 1.0));
  // Guarantee one pair of elements is ==:
  x[0] = y[0];
  print(x.begin(), x.end(), "x");
  print(y.begin(), y.end(), "y");
  // Operate on each element pair of x & y,
  // putting the result into r:
  T(testBinary(x, y, r, plus<float>()));
  T(testBinary(x, y, r, minus<float>()));
  T(testBinary(x, y, r, multiplies<float>()));
  T(testBinary(x, y, r, divides<float>()));
  //T(testBinary(x, y, r, modulus<float>()));
  T(testUnary(x, r, negate<float>()));
  vector<bool> br(SZ); // For Boolean results
  B(testBinary(x, y, br, equal_to<float>()));
  B(testBinary(x, y, br, not_equal_to<float>()));
  B(testBinary(x, y, br, greater<float>()));
  B(testBinary(x, y, br, less<float>()));
  B(testBinary(x, y, br, greater_equal<float>()));
  B(testBinary(x, y, br, less_equal<int>()));
  B(testBinary(x, y, br, not2(greater_equal<float>())));
  B(testBinary(x,y,br,not2(less_equal<float>())));
  vector<float> b1(SZ), b2(SZ);
  generate_n(b1.begin(), SZ, BRand());
  generate_n(b2.begin(), SZ, BRand());
  print(b1.begin(), b1.end(), "b1");
  print(b2.begin(), b2.end(), "b2");
  B(testBinary(b1, b2, br, logical_and<float>()));
  B(testBinary(b1, b2, br, logical_or<float>()));
  //B(testUnary(b1, br, logical_not<float>()));
  //B(testUnary(b1, br, not1(logical_not<float>())));
} ///:~

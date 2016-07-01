/**
Modify Cheshire in Handle.cpp, and verify that your project manager recompiles
and relinks only this file, but doesn’t recompile UseHandle.cpp.
**/
#include "Handle.h"

int main() {
  Handle u;
  u.initialize();
  u.read();
  u.change(1);
  u.cleanup();
} ///:~

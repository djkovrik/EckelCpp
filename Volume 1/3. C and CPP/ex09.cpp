/**
Compile and run Static.cpp. Remove the static keyword from the code,
compile and run it again, and explain what happens.
**/

#include <iostream>
using namespace std;

void func() {
  /*static*/ int i = 0;
  cout << "i = " << ++i << endl;
}

int main() {
  for(int x = 0; x < 10; x++)
    func();
} ///:~

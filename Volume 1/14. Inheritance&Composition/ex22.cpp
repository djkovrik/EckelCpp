/**
Modify Instrument.cpp so that play( ) prints a message to cout,
and Wind redefines play( ) to print a different message to cout.
Run the program and explain why you probably wouldn’t want this
behavior. Now put the virtual keyword (which you will learn about
in Chapter 15) in front of the play( ) declaration in Instrument
and observe the change in the behavior.
**/

#include <iostream>

using namespace std;

enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
  //virtual
  void play(note) const { cout << "Instrument::play() called." << endl; }
};

class Wind : public Instrument {
public:
  void play(note) const { cout << "Wind::play() called." << endl; }
};

void tune(Instrument& i) {
  i.play(middleC);
}

int main() {
  Wind flute;
  tune(flute);
}

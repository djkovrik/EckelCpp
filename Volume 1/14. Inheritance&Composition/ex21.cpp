/**
Modify Instrument.cpp to add a prepare( ) method to Instrument. Call prepare( ) inside tune( ).
**/

#include <iostream>

using namespace std;

enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
  void play(note) const {}
  void prepare(int i) const { cout << "prepare(" << i << ") called." << endl; }
};

class Wind : public Instrument {};

void tune(Instrument& i) {
  i.play(middleC);
  i.prepare(1);
}

int main() {
  Wind flute;
  tune(flute);
}

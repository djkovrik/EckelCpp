/**
Modify Instrument3.cpp by adding a virtual prepare( ) function. Call prepare( ) inside tune( ).
**/

#include <iostream>

using namespace std;

enum note { middleC, Csharp, Cflat };

class Instrument {
public:
  virtual void play(note) const {
    cout << "Instrument::play" << endl;
  }

  virtual void prepare() const {
    cout << "Instrument::prepare" << endl;
  }
};

class Wind : public Instrument {
public:
  void play(note) const {
    cout << "Wind::play" << endl;
  }
};

void tune(Instrument& i) {
  i.prepare();
  i.play(middleC);
}

int main() {
  Wind flute;
  tune(flute);
}

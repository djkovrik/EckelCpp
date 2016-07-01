/**
Look up more of the member functions for ifstream. In FName2.cpp, try them out on the file object.
**/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FName2 : public ifstream {
  string fileName;
  bool named;
public:
  FName2() : named(false) {}
  FName2(const string& fname)
    : ifstream(fname.c_str()), fileName(fname) {
    named = true;
  }
  string name() const { return fileName; }
  void name(const string& newName) {
    if(named) return; // Don't overwrite
    fileName = newName;
    named = true;
  }
};

int main() {
  FName2 file("ex16.cpp");
  cout << "name: " << file.name() << endl;
  string s;
  if (file.is_open()) //ex16
    cout << "File opened." << endl; //ex16
  getline(file, s);
  file.seekg(-200, ios::end);
  file.peek(); //ex16
  file.close();
}

/**
Modify InheritStack2.cpp to use a vector<string> instead of a Stack.
**/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class StringStack {
    vector<string*> stack;
public:
    void push(string* str) { stack.push_back(str); }
    string* peek() const { return stack.back(); }

    string* pop() {
        string* temp = 0;
        if (stack.size() != 0 ) {
            temp = stack.back();
            stack.pop_back();
        }
        return temp;
    }
};

int main() {
  ifstream in("ex25.cpp");
  string line;
  StringStack textlines;
  while(getline(in, line))
    textlines.push(new string(line));
  string* s;
  while((s = textlines.pop()) != 0)
    cout << *s << endl;
}

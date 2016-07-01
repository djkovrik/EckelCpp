/**
Create a Message class with a constructor that takes a single
string with a default value. Create a private member string,
and in the constructor simply assign the argument string to
your internal string. Create two overloaded member functions
called print( ): one that takes no arguments and simply prints
the message stored in the object, and one that takes a
string argument, which it prints in addition to the internal
message. Does it make sense to use this approach instead of
the one used for the constructor?
**/

#include <iostream>
#include <string>

using namespace std;

class Message {
public:
    Message(string text = "Default text here.") : str(text) {}
    void print() { cout << str << endl; }
    void print(string prefix) { cout << prefix << str << endl; }
private:
    string str;
};

int main() {

    Message m;

    m.print();
    m.print("Some text: ");

return 0;
}

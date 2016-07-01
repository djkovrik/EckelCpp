/**
Create a Text class that contains a string object to hold
the text of a file. Give it two constructors: a default
constructor and a constructor that takes a string argument
that is the name of the file to open. When the second
constructor is used, open the file and read the contents
into the string member object. Add a member function
contents( ) to return the string so (for example)
it can be printed. In main( ), open a file using
Text and print the contents.
**/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Text {
public:
    Text();
    Text(string filename);
    string contents();
private:
    string data;
};

Text::Text() { data = "Empty string here."; }

Text::Text(string filename) : data() {

    ifstream in(filename.c_str());
    string buf;

    while ( getline(in, buf) ) {
        data += buf;
        data += '\n';
    }
}

string Text::contents() { return data; }

int main() {

    Text t1;
    cout << t1.contents() << endl;

    Text t2("ex01.cpp");
    cout << t2.contents() << endl;

return 0;
}

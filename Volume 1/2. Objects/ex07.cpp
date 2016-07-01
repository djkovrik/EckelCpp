/**
Display a file a line at a time, waiting for the user to press the “Enter” key after each line.
**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("ex07.cpp");
    string buf;

    while ( getline(inputFile, buf)  ) {
        cout << buf;
        cin.get();
    }

return 0;
}

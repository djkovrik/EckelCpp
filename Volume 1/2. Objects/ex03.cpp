/**
Create a program that opens a file and counts the whitespace-separated words in that file.
**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int counter = 0;
    ifstream inputFile("03.txt");
    string buf;

    while (inputFile >> buf)
        ++counter;

    cout << "Whitespace-separated words: " << counter << endl;


return 0;
}

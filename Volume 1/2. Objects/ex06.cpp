/**
Change Fillvector.cpp so that it concatenates all the elements in the vector
into a single string before printing it out, but don’t try to add line numbering.
**/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    vector<string> v;
    ifstream in("ex06.cpp");
    string line;
    string overall;

    while(getline(in, line))
        v.push_back(line);

    for(int i = 0; i < v.size(); i++)
        overall = overall + v[i] + '\n';

    cout << overall << endl;

return 0;
}

/**
Create two functions, one that takes a string* and one that
takes a string&. Each of these functions should modify the
outside string object in its own unique way. In main( ),
create and initialize a string object, print it, then pass
it to each of the two functions, printing the results.
**/

#include <iostream>
#include <string>

using namespace std;

void func1(string *str) {
    *str += " modified by func1()";
}

void func2(string &str) {
    str += " and by func2()";
}

int main() {

    string line = "New string";

    cout << "Initial string: " << line << endl;
    func1(&line);
    cout << "After first function: " << line << endl;
    func2(line);
    cout << "After second function: " << line << endl;

return 0;
}

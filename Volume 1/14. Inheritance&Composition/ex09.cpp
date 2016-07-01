/**
Inherit a class StringVector from vector<void*> and redefine the push_back( )
and operator[] member functions to accept and produce string*.
What happens if you try to push_back( ) a void*?
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StringVector : public vector<void*> {
public:
    StringVector() : vs() {}
    void push_back(string* s) { vs.push_back(s); }
    string* operator[](size_t index) { return vs[index]; }
private:
    vector<string*> vs;
};



int main () {

    StringVector v;
    string str = "test";
    void* vPtr = static_cast<void*>(&str);

    //!v.push_back(vPtr);
    //!error: invalid conversion from 'void*' to 'std::string* {aka std::basic_string<char>*}' [-fpermissive]|

return 0;
}

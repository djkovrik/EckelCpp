/**
Modify MacroSideEffects.cpp so that BAND( ) works properly.
**/
#include <fstream>
using namespace std;

//#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)
int y;
#define BAND(x) (((y)=x, (y)>5 && (y)<10) ? (y) : 0)

int main() {
    ofstream out("macro.out");
    for(int i = 4; i < 11; i++) {
        int a = i;
        out << "a = " << a << endl << '\t';
        out << "BAND(++a)=" << BAND(++a) << endl;
        out << "\t a = " << a << endl;
    }
}

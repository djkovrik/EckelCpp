/**
In StaticDestructors.cpp, test the default error handling of your implementation
by turning the original definition of out into an extern declaration and putting
the actual definition after the definition of a (whose Obj constructor sends
information to out). Make sure there’s nothing else important running on your
machine when you run the program or that your machine will handle faults robustly.
**/
#include <fstream>

using namespace std;
extern ofstream out;

class Obj {
    char c;
public:
    Obj(char cc) : c(cc) {
        out << "Obj::Obj() for " << c << endl;
    }
    ~Obj() {
        out << "Obj::~Obj() for " << c << endl;
    }
};

Obj a('a');

ofstream out("statdest.out");

void f() {
    static Obj b('b');
}

void g() {
    static Obj c('c');
}

int main() {
    out << "inside main()" << endl;
    g();
    f();
    out << "leaving main()" << endl;
}

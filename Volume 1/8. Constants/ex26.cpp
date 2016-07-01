/**
Modify Quoter.cpp by making quote( ) a const member function and lastquote mutable.
**/
#include <iostream>
#include <cstdlib> // Random number generator
#include <ctime> // To seed random generator
using namespace std;

class Quoter {
    mutable int lastquote;
public:
    Quoter();
    int lastQuote() const;
    const char* quote() const;
};

Quoter::Quoter() {
    lastquote = -1;
    srand(time(0)); // Seed random number generator
}

int Quoter::lastQuote() const {
    return lastquote;
}

const char* Quoter::quote() const {
    static const char* quotes[] = {
        "Are we having fun yet?",
        "Doctors always know best",
        "Is it ... Atomic?",
        "Fear is obscene",
        "There is no scientific evidence "
        "to support the idea "
        "that life is serious",
        "Things that make us happy, make us wise",
    };
    const int qsize = sizeof quotes/sizeof *quotes;
    int qnum = rand() % qsize;
    while(lastquote >= 0 && qnum == lastquote)
        qnum = rand() % qsize;
    return quotes[lastquote = qnum];
}

int main() {
    Quoter q;
    const Quoter cq;
    cq.lastQuote(); // OK
//!  cq.quote(); // Not OK; non const function
    for(int i = 0; i < 20; i++)
        cout << q.quote() << endl;
} ///:~

/*
Repeat the previous exercise but replace all instances
of from regardless of case.

Write a program named replace that takes three command-line
arguments representing an input text file, a string to replace
(call it from), and a replacement string (call it to).
The program should write a new file to standard output
with all occurrences of from replaced by to.
*/

#include <iostream>
#include <fstream>
#include "ichar_traits.h"

int main() {

	/*Declarations instead of command line args*/
    std::ifstream source("source.txt", std::ios::in);
    std::ofstream result("result_07.txt", std::ios::out);

    istring from = "%Tag%";
    istring to = "John";

    std::string buf;
    size_t pos;

    while (getline(source, buf)) {

    	istring ibuf(buf.begin(), buf.end());

        pos = ibuf.find(from);
        while (pos != std::string::npos) {
            ibuf.replace(pos, from.size(), to);
            pos = ibuf.find(from, pos);
        }
        result << ibuf << '\n';
    }

return 0;
}

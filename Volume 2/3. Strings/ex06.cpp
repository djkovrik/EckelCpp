/*
Write a program named replace that takes three command-line
arguments representing an input text file, a string to replace
(call it from), and a replacement string (call it to).
The program should write a new file to standard output
with all occurrences of from replaced by to.
*/

#include <iostream>
#include <string>
#include <fstream>

int main() {

	/*Declarations instead of the command line args*/
    std::ifstream source("source.txt", std::ios::in);
    std::ofstream result("result_06.txt", std::ios::out);

    std::string from = "%Tag%";
    std::string to = "John";

    std::string buf;
    size_t pos;

    while (getline(source, buf)) {

        pos = buf.find(from);
        while (pos != std::string::npos) {
            buf.replace(pos, from.size(), to);
            pos = buf.find(from, pos);
        }
        result << buf << '\n';
    }

return 0;
}

#ifndef EX25_H_INCLUDED
#define EX25_H_INCLUDED

#include <iostream>
#include <string>

class MyClass {
public:
    MyClass(std::string s) : str (s) {}
    void print() { std::cout << str << std::endl; }
private:
    std::string str;
};

#endif // EX25_H_INCLUDED

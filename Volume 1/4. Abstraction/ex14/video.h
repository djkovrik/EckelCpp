#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <iostream>
#include <string>
using std::string;

struct Video {

    Video() :
    id(0), length(0), price(0), name("-") {}


    Video(int i, int len, int p, string str) :
    id(i), length(len), price(p), name(str) {}

    int id;
    int length;
    int price;
    string name;

    void print();

    void setId(int x) { id = x; }
    int getId() { return id; }

    void setLength(int x) { length = x; }
    int getLength() { return length; }

    void setPrice(int x) { price = x; }
    int getPrice() { return price; }

    void setName(string x) { name = x; }
    string getName() { return name; }
};

#endif // VIDEO_H_INCLUDED

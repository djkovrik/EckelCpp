//: C16:AutoCounter.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#ifndef AUTOCOUNTER_H
#define AUTOCOUNTER_H
#include <iostream>
#include <set> // Standard C++ Library container
#include <string>
#include <typeinfo>

template <typename T>
class AutoCounter {
	static int count;
	int id;
	T* class_ptr;

	// Prevent assignment and copy-construction:
	AutoCounter(const AutoCounter&);
	void operator=(const AutoCounter&);

public:
	AutoCounter(T* ptr) : id(count++), class_ptr(ptr) {
		std::cout << typeid(*class_ptr).name() << " created[" << id << "]"
				  << std::endl;
	}

	~AutoCounter() {
		std::cout << typeid(*class_ptr).name() << " destroyed[" << id
				  << "]" << std::endl;
	}
}; 

template <typename Y>
int AutoCounter<Y>::count = 0;


#endif // AUTOCOUNTER_H ///:~

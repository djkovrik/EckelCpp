/*
Write a class template that uses a vector to implement
a stack data structure.
*/

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class MyStack {
public:
	void push(T& value);
	void pop();
	T& top();
	bool empty() const;
	size_t size() const;
private:
	std::vector<T> data;
};

template<typename T>
void MyStack<T>::push(T& value) {
	data.push_back(value);
}

template<typename T>
void MyStack<T>::pop() {
	if (data.empty())
		throw std::out_of_range("Stack<T>::pop(): stack is empty");

	data.pop_back();
}

template<typename T>
T& MyStack<T>::top() {
	if (data.empty())
			throw std::out_of_range("Stack<T>::top(): stack is empty");

	return data.back();
}

template<typename T>
bool MyStack<T>::empty() const {
	return data.empty();
}

template<typename T>
size_t MyStack<T>::size() const {
	return data.size();
}


int main() {

	MyStack<int> intStack;

	for (int i = 1; i <= 10; ++i)
		intStack.push(i);

	std::cout << "Stack size: " << intStack.size()
			  << "\ntop(): " << intStack.top();

	intStack.pop();
	std::cout << "\nNew stack size: " << intStack.size()
			  << "\nNew top(): " << intStack.top();

return 0;
}

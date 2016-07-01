/*
Modify your solution to the previous exercise so that
the type of the container used to implement the stack
is a template template parameter.

Exercise 2:
Write a class template that uses a vector to implement
a stack data structure.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

template<typename T, typename Container = std::vector<T>>
class MyStack {
public:
	void push(T& value);
	void pop();
	T& top();
	bool empty() const;
	size_t size() const;
private:
	Container data;
};

template<typename T, typename Container>
void MyStack<T, Container>::push(T& value) {
	data.push_back(value);
}

template<typename T, typename Container>
void MyStack<T, Container>::pop() {
	if (data.empty())
		throw std::out_of_range("Stack<T>::pop(): stack is empty");

	data.pop_back();
}

template<typename T, typename Container>
T& MyStack<T, Container>::top() {
	if (data.empty())
			throw std::out_of_range("Stack<T>::top(): stack is empty");

	return data.back();
}

template<typename T, typename Container>
bool MyStack<T, Container>::empty() const {
	return data.empty();
}

template<typename T, typename Container>
size_t MyStack<T, Container>::size() const {
	return data.size();
}


int main() {

	MyStack<int> intStack;

	for (int i = 2; i <= 20; i+=2)
		intStack.push(i);

	std::cout << "int stack size: " << intStack.size()
			  << "\ntop(): " << intStack.top();

	intStack.pop();
	std::cout << "\nNew int stack size: " << intStack.size()
			  << "\nNew top(): " << intStack.top();


	MyStack<double, std::deque<double>> dbStack;

	for (int i = 1; i <= 5; ++i) {
		double d = i * 0.1;
		dbStack.push(d);
	}

	std::cout << "\n\nDouble stack size: " << dbStack.size()
			  << "\ntop(): " << dbStack.top();

	dbStack.pop();
	std::cout << "\nNew double stack size: " << dbStack.size()
			  << "\nNew top(): " << dbStack.top();

return 0;
}

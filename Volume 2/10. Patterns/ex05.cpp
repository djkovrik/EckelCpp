/*
Find C16:TStack.h from Thinking in C++, Volume 1,
2nd Edition (downloadable from www. BruceEckel.com).
Create an Adapter for this class such that you can apply
the STL algorithm for_each( ) to the elements of the TStack,
using your adapter. Create a TStack of string, fill it
with strings and use for_each( ) to count all the
letters in all the strings in the TStack.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "TStack.h"

template <typename T>
class TStackAdapter {
public:
	TStackAdapter(Stack<T>& s) : st(s) {}

	 void push(T* dat) { st.push(dat); }
	 T* peek() const { return st.peek(); }
	 T* pop() { return st.pop(); }

		class iterator;
		friend class iterator;
		class iterator : public std::iterator<
		std::input_iterator_tag, T, ptrdiff_t> {
			typename Stack<T>::Link* ptr;
		public:
			iterator(const TStackAdapter<T>& left) : ptr( left.st.head ) {}
			iterator(const iterator& it) : ptr(it.ptr) {}
			iterator() : ptr(nullptr) {}

			bool operator++() {
				if(ptr->next)
					ptr = ptr->next;
				else ptr = nullptr;
			return bool(ptr);
			}

			bool operator++(int) { return operator++(); }

			T* current() const {
				if(!ptr) return 0;
					return ptr->data;
			}

			T* operator->() const { return current(); }
			T* operator*() const { return current(); }

			bool operator==(const iterator& left) const { return ptr == left.ptr; }
			bool operator!=(const iterator& left) const { return !operator==(left); }
		};

	iterator begin() const { return iterator(*this); }
	iterator end() const { return iterator(); }

private:
	Stack<T>& st;
};

int main() {


	Stack<std::string> lines;

	lines.push( new std::string("Find C16:TStack.h from Thinking in C++, Volume 1"));
	lines.push( new std::string("2nd Edition (downloadable from www. BruceEckel.com)."));
	lines.push( new std::string("Create an Adapter for this class such that you can apply"));

	TStackAdapter<std::string> adapter(lines);

	std::for_each(adapter.begin(), adapter.end(),
		[](std::string* s) {
			std::cout << *s << '\n';
		}
	);

	/* Resources need to be cleaned properly */

return 0;
}

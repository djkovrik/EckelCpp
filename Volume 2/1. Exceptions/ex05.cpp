/*
Create a class with its own operator new. This operator
should allocate ten objects, and on the eleventh object
"run out of memory" and throw an exception. Also add a
static member function that reclaims this memory. Now
create a main( ) with a try block and a catch clause
that calls the memory-restoration routine. Put these
inside a while loop, to demonstrate recovering from an
exception and continuing execution.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>

class MyObject {
public:
	MyObject(int x = 0) : id(x) { std::cout << "+ Creating MyObject[" << id << "]\n"; }
	~MyObject() { std::cout << "- Deleting MyObject[" << id << "]\n"; }
private:
	int id;
};

template<typename T, int size>
class MyStorage {
public:
	void* operator new(size_t sz) {
		for (int i = 1; i <= size; i++) {
			if ( 11 == i)
				throw std::runtime_error("Not enough memory");

			storage.push_back( ::new T(i) );
		}
	}

	static void cleanUp() {
        int sz = storage.size();

        for (int i = 0; i < sz; i++) {
        	MyObject* temp = storage.back();
        	storage.pop_back();
            delete temp;
        }
        assert(storage.size() == 0);
	}

private:
	static std::vector<T*> storage;
};

template<typename T, int size>
std::vector<T*> MyStorage<T, size>::storage;

int main() {

	while (true) {
		try {
			MyStorage<MyObject, 20>* m = new MyStorage<MyObject, 20>();
		}
		catch (std::runtime_error& exc) {
			std::cout << "Exception detected: " << exc.what() << '\n';
			break;
		}
	}
	MyStorage<MyObject, 20>::cleanUp();

return 0;
}

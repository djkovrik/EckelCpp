/*
Create a template that implements a singly-linked list
called SList. Provide a default constructor and begin( )
and end( ) functions (via an appropriate nested iterator),
insert( ), erase( ) and a destructor.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <memory>
#include <list>

template <typename T>
class SList {

	struct SNode {
		T node_data;
		std::shared_ptr<SNode> node_next;

		SNode(const T& x = 0) : node_data(x), node_next(nullptr) {
			//std::cout << "+Node(" << node_data << ")\n";
		}

		~SNode() {
			//std::cout << "~Node(" << node_data << ")\n";
		}
	};

public:
	SList() : list_head(nullptr) { }

	~SList() {
		while(list_head)
			erase();
	}

	class iterator;
	friend class iterator;
	class iterator : public std::iterator<std::forward_iterator_tag, T, ptrdiff_t> {
		std::shared_ptr<SNode> iter;
	public:
		iterator() : iter(nullptr) {}
	    iterator(std::shared_ptr<SNode> ptr) : iter(ptr) {}
	    bool operator==(const iterator& other) const { return iter == other.iter; }
	    bool operator!=(const iterator& other) const { return !operator==(other); }

	    T operator*() const {
	    	if( iter ) {
	    		return iter->node_data;
	    	}
	    	return T();
	    }

	    //prefix
	    iterator& operator++() {
	    	if (iter)
	    		iter = iter->node_next;

	    	return *this;
	    }

	    //postfix
	    iterator operator++(int) {
	    	iterator temp = *this;
	    	++*this;
	    	return temp;
	    }

	    iterator insert(const T& element) {
	    	std::shared_ptr<SNode> temp = iter;
	    	iter = std::make_shared<SNode>(element);
	    	iter->node_next = temp->node_next;
	    	temp->node_next = iter;
	    	return iterator(iter);
	    }
	};

    void insert(const T& element) {
    	auto new_node = std::make_shared<SNode>(element);

    		if (list_head) {

        		auto temp_ptr = list_head;

        		while (temp_ptr->node_next != nullptr)
        			temp_ptr = temp_ptr->node_next;

        		temp_ptr->node_next = new_node;

    		} else
    			list_head = new_node;
    }

    void erase() {
    	if (list_head->node_next == nullptr) {
    		list_head.reset();
    		return;
    	}

    	auto prev_ptr = list_head;
    	auto last_ptr = list_head->node_next;

    	while (last_ptr->node_next != nullptr) {
    		prev_ptr = last_ptr;
    		last_ptr = last_ptr->node_next;
    	}

    	prev_ptr->node_next = nullptr;
    	last_ptr.reset();
    }

    T* head() const {
    	return list_head;
    }

    iterator begin() const { return iterator(list_head); }
    iterator end() const   { return iterator(nullptr); }

	size_t size() const {
		size_t s = 0;
		for( iterator it = begin(); it != end(); ++it, ++s );
		return s;
    }

private:
	std::shared_ptr<SNode> list_head;
};

int main() {

	SList<std::string> strlist;
	strlist.insert("one");
	strlist.insert("two");
	strlist.insert("three");
	strlist.insert("four");
	strlist.insert("five");

	auto it1 = strlist.begin();
	it1++; it1++;
	it1.insert("+++");

	auto it2 = strlist.begin();

	while (it2 != strlist.end()) {
		std::cout << *it2 << '\n';
		it2++;
	}


return 0;
}

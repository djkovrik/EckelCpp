/*
Modify Ring.cpp so that the underlying implementation
can be chosen using a template argument.
(Let that template argument default to list.)
*/

//: C07:Ring.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Making a "ring" data structure from the STL.
#include <iostream>
#include <iterator>
#include <list>
#include <deque>
#include <string>
using namespace std;

template<class T, typename Container = list<T>> class Ring {
	Container lst;
public:
  // Declaration necessary so the following
  // 'friend' statement sees this 'iterator'
  // instead of std::iterator:
  class iterator;
  friend class iterator;
  class iterator : public std::iterator<
    std::bidirectional_iterator_tag,T,ptrdiff_t>{
    typename Container::iterator it;
    Container* r;
  public:
    iterator(Container& lst,
      const typename Container::iterator& i)
    : it(i), r(&lst) {}
    bool operator==(const iterator& x) const {
      return it == x.it;
    }
    bool operator!=(const iterator& x) const {
      return !(*this == x);
    }
    typename Container::reference operator*() const {
      return *it;
    }
    iterator& operator++() {
      ++it;
      if(it == r->end())
        it = r->begin();
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      ++*this;
      return tmp;
    }
    iterator& operator--() {
      if(it == r->begin())
        it = r->end();
      --it;
      return *this;
    }
    iterator operator--(int) {
      iterator tmp = *this;
      --*this;
      return tmp;
    }
    iterator insert(const T& x) {
      return iterator(*r, r->insert(it, x));
    }
    iterator erase() {
      return iterator(*r, r->erase(it));
    }
  };
  void push_back(const T& x) { lst.push_back(x); }
  iterator begin() { return iterator(lst, lst.begin()); }
  int size() { return lst.size(); }
};

int main() {
  //Ring<string> rs;
  Ring<string, deque<string>> rs;
  rs.push_back("one");
  rs.push_back("two");
  rs.push_back("three");
  rs.push_back("four");
  rs.push_back("five");
  //Ring<string>::iterator it = rs.begin();
  Ring<string, deque<string>>::iterator it = rs.begin();
  ++it; ++it;
  it.insert("six");
  it = rs.begin();
  // Twice around the ring:
  for(int i = 0; i < rs.size() * 2; i++)
    cout << *it++ << endl;
} ///:~

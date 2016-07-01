/**
Using the Standard C++ Library vector as an underlying
implementation, create a Set template class that accepts
only one of each type of object that you put into it. Make
a nested iterator class that supports the "end sentinel"
concept in this chapter. Write test code for your Set in
main( ), and then substitute the Standard C++ Library set
template to verify that the behavior is correct.
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <class T>
class Set {
public:
    Set() : data() {}
    bool empty() const { return data.size() == 0; }
    size_t size() const { return data.size(); }

    class iterator;
    friend class iterator;
    class iterator {
    public:
        // Constructors
        iterator(Set& is) : s(is), index(0) {}
        iterator(Set& is, bool) : s(is), index(s.size()) {}
        iterator (const iterator& r) : s(r.s), index(r.index) {}

        // Operators overloading
        T operator*() const { return s.data[index]; }
        T operator->() const { return s.data[index]; }

        // VERY simple implementation, no "out of bounds" check
        iterator& operator++() {
            ++index;
            return *this;
        }

        iterator operator++(int) {
            return operator++();
        }

        iterator& operator--() {
            --index;
            return *this;
        }

        iterator operator--(int) {
            return operator--();
        }

        iterator& operator=(const iterator& rv) {
            s = rv.s;
            index = rv.index;
            return *this;
        }

        bool operator==(const iterator& rv) const { return index == rv.index; }
        bool operator!=(const iterator& rv) const { return index != rv.index; }
        friend ostream& operator<<(ostream& os, const iterator& it) { return os << *it; }


    private:
        Set& s;
        int index;
    };

    bool insert (T element);
    void erase (iterator pos);

    iterator begin() { return iterator(*this); }
    iterator end()   { return iterator(*this, true); }

private:
    vector<T> data;
    bool exists(const T& element);
};

template <class T>
bool Set<T>::exists(const T& element) {
    for (size_t i = 0; i < data.size(); i++)
        if (element == data[i])
            return true;

    return false;
}

template <class T>
bool Set<T>::insert (T element) {

    if ( !exists(element) ) {
        data.push_back(element);
        sort(data.begin(), data.end());
        return true;
    }

    return false;
}

template <class T>
void Set<T>::erase (Set<T>::iterator pos) {

    for (size_t i = 0; i < data.size(); i++ )
        if (data[i] == *pos)
            data.erase( data.begin() + i );
}

template <class set_type>
void printSet(set_type s) {
    for (typename set_type::iterator p = s.begin(); p != s.end(); p++)
        cout << *p << ' ';
    cout << endl;
}

int main() {

    Set<int> a;
    ///set<int> a;

    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(6);
    printSet(a);

    a.erase( a.begin() );
    printSet(a);

return 0;
}

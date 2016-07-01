/**
Use aggregate initialization to create an array of string objects.
Create a Stack to hold these strings and step through your array,
pushing each string on your Stack. Finally, pop the strings off
your Stack and print each one.
**/
#include <iostream>
#include <string>

using namespace std;

class Stack {
  struct Link {
    void* data;
    Link* next;
    Link(void* dat, Link* nxt);
    ~Link();
  }* head;
public:
  Stack();
  ~Stack();
  void push(void* dat);
  void* peek();
  void* pop();
};


Stack::Link::Link(void* dat, Link* nxt) {
  data = dat;
  next = nxt;
}

Stack::Link::~Link() { }

Stack::Stack() { head = 0; }

void Stack::push(void* dat) {
  head = new Link(dat,head);
}

void* Stack::peek() {
  return head->data;
}

void* Stack::pop() {
  if(head == 0) return 0;
  void* result = head->data;
  Link* oldHead = head;
  head = head->next;
  delete oldHead;
  return result;
}

Stack::~Stack() {

}

int main() {

    string str[] = { "one", "two", "three", "four", "five"};
    int array_size = sizeof(str) / sizeof(*str);

    Stack lines;

    for (int i = 0; i < array_size; i++)
        lines.push(new string(str[i]));

    string* s;

    while((s = (string*)lines.pop()) != 0) {
        cout << *s << endl;
        delete s;
    }

return 0;
}

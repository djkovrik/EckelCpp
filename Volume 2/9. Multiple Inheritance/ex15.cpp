/*
Define a reference-counted error logging mixin class, ErrorLog,
that holds a static file stream to which you can send messages.
The class opens the stream when its reference count exceeds 0
and closes the stream when the count returns to 0 (and always
appends to the file). Have objects of multiple classes send
messages to the static log stream. Watch the stream open and
close via trace statements in ErrorLog.
*/

#include <iostream>
#include <fstream>
#include <string>

// Logging class - START
class ErrorLog {
public:
	ErrorLog() {
		if (reference_counter++ == 0)
			message("Log has been created.");
	}

	~ErrorLog() {
		if (--reference_counter == 0) {
			message("Log has been closed.");
			log.close();
		}
	}

	static void message(std::string str) { log << str << std::endl; }


private:
	static std::ofstream log;
	static int reference_counter;
};

std::ofstream ErrorLog::log("ex15_log.txt", std::ios::app);
int ErrorLog::reference_counter = 0;
// Logging class - END

class A : public ErrorLog {
public:
	A() { message("A()"); }
	virtual ~A() { message("~A()"); }
	virtual void f() { message("A::f()"); }
};

class B : virtual public A {
public:
	B() { message("B()"); }
	~B() { message("~B()"); }
};

class C : virtual public A {
public:
	C() { message("C()"); }
	~C() { message("~C()"); }
};

class D : public B, public C {
public:
	D() { message("D()"); }
	~D() { message("~D()"); }
	void f() { message("D::f()"); }
};

int main() {

	A a;
	a.f();

	D d;
	d.f();

return 0;
}

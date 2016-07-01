/*
Write three functions: one that returns an error value
to indicate an error condition, one that sets errno, and
one that uses signal( ). Write code that calls these
functions and responds to the errors. Now write a fourth
function that throws an exception. Call this function and
catch the exception. Describe the differences between these
four approaches, and why exception handling is an improvement.
*/

#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <csignal>
#include <csetjmp>
#include <cerrno>
#include <cstring>
#include <cmath>

void signal_handler(int sig);

int  foo1(int);
void foo2();
void foo3();
void foo4();

namespace {
  volatile std::sig_atomic_t gSignalStatus;
}

class MyError : public std::runtime_error {
public:
	MyError(const std::string& msg = "") : runtime_error(msg) {}
};

int main() {

	foo1(-1);
	foo2();
	foo3();

	try {
		foo4();
	}
	catch (const MyError& exc) {
		std::cout << "Exception caught: " << exc.what() << '\n';
	}

return 0;
}

void signal_handler(int sig) {
	gSignalStatus = sig;
	std::cout << "signal_handler() call.\n";
}

int foo1(int x) {
	std::cout << "foo1(" << x << ") call.\n";
	if (x < 0) return -1;
	return x * x;
}

void foo2() {
	std::cout << "foo2() call.\n";

	auto bad_sqrt = std::sqrt(-1);

	if (errno == EDOM)
		std::cout << "\tsqrt failed: " << std::strerror(errno) << '\n';
}

void foo3() {
	std::cout << "foo3() call.\n";
	std::signal(SIGINT, signal_handler);
	std::cout << "\tSignal value: " << gSignalStatus << '\n';
	std::cout << "\tSending signal " << SIGINT << '\n';
	std::raise(SIGINT);
	std::cout << "\tSignal value: " << gSignalStatus << '\n';
}

void foo4() {
	std::cout << "foo4() call.\n";
	throw MyError("exception from foo4()");
}

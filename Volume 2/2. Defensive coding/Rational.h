/*
Suppose you are asked to develop a class named Rational
that supports rational numbers (fractions). The fraction
in a Rational object should always be stored in lowest
terms, and a denominator of zero is an error. Here is
a sample interface for such a Rational class.

Write a complete specification for this class, including
preconditions, postconditions, and exception specifications.

Write a test using the TestSuite framework that thoroughly
tests all the specifications from the previous exercise,
including testing exceptions.

Implement the Rational class so that all the tests from the
previous exercise pass. Use assertions only for invariants.
*/

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>
#include <stdexcept>
#include <string>

class Zero_argument : public std::invalid_argument {
public:
	Zero_argument(const std::string& msg) : std::invalid_argument(msg) {}
};

class Rational {
public:
	Rational(int num = 0, int denom = 1);
	Rational(const Rational& rhs);

	void set_numerator(int n);
	void set_denominator(int d);
	void reduction();

	Rational& operator=(const Rational& rhs);

	Rational operator-() const;

	friend Rational operator+(const Rational&,
                              const Rational&);
	friend Rational operator-(const Rational&,
                              const Rational&);
	friend Rational operator*(const Rational&,
                              const Rational&);
	friend Rational operator/(const Rational&,
                              const Rational&);

	friend std::ostream&
	operator<<(std::ostream&, const Rational&);
	friend std::istream&
	operator>>(std::istream&, Rational&);

	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);

	friend bool operator<(const Rational&,
                          const Rational&);
	friend bool operator>(const Rational&,
                          const Rational&);
	friend bool operator<=(const Rational&,
                           const Rational&);
	friend bool operator>=(const Rational&,
                           const Rational&);
	friend bool operator==(const Rational&,
                           const Rational&);
	friend bool operator!=(const Rational&,
                           const Rational&);
private:
	int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

	int numerator;
	int denominator;
};
#endif // RATIONAL_H ///:~

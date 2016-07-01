#include "Rational.h"

Rational::Rational(int num, int denom)  {
	if(0 == denom)
		throw( Zero_argument("Division by zero.") );

	set_numerator(num);
	set_denominator(denom);
	reduction();
}

Rational::Rational(const Rational& rhs) : numerator(rhs.numerator), denominator(rhs.denominator) {
	reduction();
}

void Rational::set_numerator(int n) {
	numerator = n;
}

void Rational::set_denominator(int d) {
	denominator = d;
}

void Rational::reduction() {
	int current_gcd = gcd(numerator, denominator);
	numerator /= current_gcd;
	denominator /= current_gcd;

	if(denominator < 0) {
		set_numerator(-numerator);
		set_denominator(-denominator);
	}
}

Rational& Rational::operator=(const Rational& rhs) {
	if (this != &rhs) {
		set_numerator(rhs.numerator);
		set_denominator(rhs.denominator);
	}

	return *this;
}

Rational Rational::operator-() const {
	return Rational(-numerator, denominator);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator,
			        lhs.denominator * rhs.denominator);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
 	return Rational(lhs.numerator * rhs.denominator - lhs.denominator * rhs.numerator,
 			        lhs.denominator * rhs.denominator);
 }


Rational operator*(const Rational& lhs, const Rational& rhs) {
 	return Rational(lhs.numerator * rhs.numerator,
 			        lhs.denominator * rhs.denominator);
 }

Rational operator/(const Rational& lhs, const Rational& rhs) {
 	return Rational(lhs.numerator * rhs.denominator,
 			        lhs.denominator * rhs.numerator);
 }

std::ostream& operator<<(std::ostream& os, const Rational& r) {
	if (r.numerator == 0)
		os << 0;
	else
		os << r.numerator << '/' << r.denominator;
	return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {

	/* DOES NOT HANDLE UNSAFE INPUT */

	std::string str;
	is >> str;

	auto pos = str.find("/");

	int x = std::stoi( str.substr(0, pos) );
	int y = std::stoi( str.substr(pos+1) );

	r.set_numerator(x);
	r.set_denominator(y);
	r.reduction();

	return is;
}

Rational& Rational::operator+=(const Rational& rhs) {
	set_numerator(numerator * rhs.denominator + denominator * rhs.numerator);
	set_denominator(denominator * rhs.denominator);
	reduction();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
	set_numerator(numerator * rhs.denominator - denominator * rhs.numerator);
	set_denominator(denominator * rhs.denominator);
	reduction();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	set_numerator(numerator * rhs.numerator);
	set_denominator(denominator * rhs.denominator);
	reduction();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	set_numerator(numerator * rhs.denominator);
	set_denominator(denominator * rhs.numerator);
	reduction();
	return *this;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return ( lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator );
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	return ( lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator );
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	return ( lhs.numerator * rhs.denominator <= rhs.numerator * lhs.denominator );
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	return ( lhs.numerator * rhs.denominator >= rhs.numerator * lhs.denominator );
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	return ( (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator) );
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
	return ( !(operator==(lhs,rhs)) );
}

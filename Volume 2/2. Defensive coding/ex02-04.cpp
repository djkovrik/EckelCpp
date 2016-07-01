#include <iostream>
#include "Rational.h"
#include "TestSuite/Suite.h"

class TestRational : public TestSuite::Test {
public:
	TestRational() : Test() {}

	void testAssignment() {
		Rational a1(1,5);
		Rational a2 = a1;
		test_(a1 == a2);

		Rational a3(1,3);
		test_( (a3 += Rational(3,7))  == Rational(16,21) );

		Rational a4(2,5);
		test_( (a4 -= Rational(1,6))  == Rational(7,30) );

		Rational a5(1,3);
		test_( (a5 *= Rational(3,4))  == Rational(1,4) );

		Rational a6(1,4);
		test_( (a6 /= Rational(3,4))  == Rational(1,3) );

	}

	void testMath() {
		test_( (Rational(2,5) + Rational(1,3)) == Rational(11,15) );
		test_( (Rational(1,2) - Rational(2,5)) == Rational(1,10) );
		test_( (Rational(2,3) * Rational(3,5)) == Rational(2,5) );
		test_( (Rational(1,5) / Rational(2,3)) == Rational(3,10) );

		Rational m1(1,3);
		Rational m2(-1,3);
		test_( m1 == -m2);
	}

	void testComparison() {
		test_ ( Rational(1,3) < Rational(3,4) );
		test_ ( Rational(2,3) > Rational(1,5) );
		test_ ( Rational(1,3) <= Rational(3,4) );
		test_ ( Rational(2,3) >= Rational(1,5) );
		test_ ( Rational(1,3) <= Rational(1,3) );
		test_ ( Rational(2,3) >= Rational(2,3) );
		test_ ( Rational(2,4) == Rational(1,2) );
		test_ ( Rational(1,4) != Rational(1,2) );
	}

	void testException() try {
		Rational r(2,0);
		fail_("Zero denominator was not detected.");
	}
	catch (Zero_argument& ex) {
		std::cout << "! Exception detected: " << ex.what() << '\n';
		succeed_();
	}

	void run() {
		testAssignment();
		testMath();
		testComparison();
		testException();
	}
};

int main() {

	TestRational tr;
	tr.run();

return tr.report();
}

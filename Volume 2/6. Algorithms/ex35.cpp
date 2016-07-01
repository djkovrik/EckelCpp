/*
Make an Employee class with two data members:
hours and hourlyPay. Employee shall also have a
calcSalary( ) function which returns the pay for
that employee. Generate random hourly pay and hours
for an arbitrary amount of employees. Keep a
vector<Employee*>. Find out how much money the
company is going to spend for this pay period.
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <memory>

class Employee {
public:
	Employee(int h = 0, int hp = 0) : hours(h), hourly_pay(hp) {}
	int calc_salary() const { return hours*hourly_pay; }

	int hours;
	int hourly_pay;
};

int main() {

	std::srand(std::time(0));

	const int staff = 30;
	// smart pointers instead of Employee*
	std::vector<std::unique_ptr<Employee>> people;

	for (size_t i = 0; i < staff; ++i) {
		auto hours_per_week = std::rand() % 20 + 20;
		auto hourly_payment = std::rand() % 10 + 1;
		people.push_back( std::make_unique<Employee>( hours_per_week, hourly_payment ) );
	}

	int overall_payment = 0;
	std::for_each(people.begin(), people.end(),
		[&overall_payment](const std::unique_ptr<Employee>& ptr) {
			overall_payment += ptr->calc_salary();
		}
	);

	for (const auto& p : people)
		std::cout << "Hours: " << p->hours << '\t' << "Rate, $: "<< p->hourly_pay << '\n';

	std::cout << "\nOverall payment: " << overall_payment << '\n';

return 0;
}

/*
Create a Sum function object template that will
accumulate all the values in a range when used with
for_each( ).
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main() {

	int a[] = {1,2,3,4,5};
	std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	int sum = 0;
	std::for_each(v.begin(), v.end(), [&sum](int i) { sum += i; });
	std::cout << sum << '\n';

return 0;
}

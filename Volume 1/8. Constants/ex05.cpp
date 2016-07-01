/**
Create a const whose value is determined at runtime by
reading the time when the program starts (you’ll have
to use the <ctime> standard header). Later in the program,
try to read a second value of the time into your const
and see what happens.
**/

// Both constansts will be initialized with the same value

#include <iostream>
#include <ctime>

using namespace std;

int main() {

    time_t timer;
    struct tm* timeinfo;

    time(&timer);
    timeinfo = localtime (&timer);

    const char* first_time = asctime(timeinfo);

    cout << first_time << endl;

    // Takes some CPU time
    for (int i = 0, j = 0; i < 1000000000; i++)
        j++;

    const char* second_time = asctime(timeinfo);

    cout << second_time << endl;

return 0;
}

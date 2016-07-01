/*
Create an example of a “busy wait.” One thread sleeps for
awhile and then sets a flag to true. The second thread watches
that flag inside a while loop (this is the “busy wait”) and,
when the flag becomes true, sets it back to false and reports
the change to the console. Note how much wasted time the
program spends inside the “busy wait,” and create a second
version of the program that uses wait( ) instead of the
“busy wait.” Extra: run a profiler to show the time used
by the CPU in each case.
*/

#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/chrono/include.hpp>

boost::mutex c_mutex;
boost::condition_variable c_variable;
bool flag = false;

void wait() {
	boost::unique_lock<boost::mutex> lock(c_mutex);
	std::cout << "Thread " << boost::this_thread::get_id() << ": waiting...\n";

	c_variable.wait( lock, [] { return flag == true; });

	std::cout << "Thread " << boost::this_thread::get_id() << ": waiting is finished.\n";
}

void worker_thread() {

	std::cout << "Thread " << boost::this_thread::get_id() << ": falls asleep...\n";
	boost::this_thread::sleep_for(boost::chrono::seconds(7));
	std::cout << "Thread " << boost::this_thread::get_id() << ": awaken.\n";

	boost::unique_lock<boost::mutex> lock(c_mutex);
	flag = true;
	c_variable.notify_one();

}


int main() {

	std::cout.setf(std::ios::unitbuf);

	boost::thread t1(wait), t2(worker_thread);
	t1.join();
	t2.join();


return 0;
}

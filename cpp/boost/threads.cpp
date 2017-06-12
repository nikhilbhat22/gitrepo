#include <boost/thread.hpp>
#include <iostream>
#include <thread>

void threadInit()
{
	std::cout << " thread started" << std::endl;
}

int main()
{
	boost::thread t (threadInit);
	std::cout << " main going to exit " << std::endl;
	return 0;
}

#include "logger.hxx"
#include "LinkedList.hxx"
#include <ctime>
#include <cstdlib>

int main()
{
	return 1;
}

void runLinkedList()
{
	LinkedList<int> intList;
	srand( (int) time(0) );

	unsigned int i = 10;
	while (i > 0)
	{
		int rd = rand() % 100;
		intList.Insert(rd);
		--i;
	}
	
	intList.Print();

	int ret = LinkedListHelper<int>::CheckCycle(intList);
	std::cout << " Cycle : " << ret << std::endl;
}

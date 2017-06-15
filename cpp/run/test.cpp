#include "logger.hxx"
#include "LinkedList.hxx"
#include "SQueue.hxx"
#include <ctime>
#include <cstdlib>
#include <vector>

void runSQueue();
void runLinkedList();

int main()
{
	runLinkedList();
	return 1;
}

void runSQueue()
{
	SQueue<int> q;
	srand( (int) time(0) );
	int i = 10;
	while (i > 0)
	{
		int rd = rand() % 100;
		std::cout << " queue i/p " << rd << std::endl; 
		q.Enqueue(rd);
		--i;
	}

	while (q.Size() > 0)
	{
		std::cout << " queue o/p " << q.Dequeue() << std::endl; 
	}
}

void runLinkedList()
{
	LinkedList<int> intList;
	srand( (int) time(0) );

	unsigned int i = 2;
	while (i > 0)
	{
		int rd = rand() % 100;
		intList.Insert(rd);
		--i;
	}
	
	intList.Print();

	int ret = LinkedListHelper<int>::CheckCycle(intList);
	std::cout << " Cycle : " << ret << std::endl;
	LinkedListHelper<int>::Reverse(intList);
	intList.Print();
}

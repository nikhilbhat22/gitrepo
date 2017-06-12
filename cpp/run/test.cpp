#include "logger.hxx"
#include "LinkedList.hxx"
#include "SQueue.hxx"
#include <ctime>
#include <cstdlib>
#include <vector>

void runSQueue();

int main()
{
	std::vector<int> vec;
	std::cout << " vec capacity is " << vec.capacity() << std::endl;
	vec.reserve(10);
	vec.push_back(1);
	std::cout << " vec capacity is " << vec.capacity() << std::endl;
	vec[14] = 5;
	vec[0] = 9;
	std::cout << " vec capacity is " << vec.capacity() << std::endl;
	std::cout << " vec size is " << vec.size() << std::endl;
	std::cout << " vec element is " << vec.at(0) << std::endl;

	int arr[] = {1,2,3};
	std::cout << " arr size is " << sizeof(arr)/sizeof(arr[0]) << " elem size : " << sizeof(int) << std::endl;
	
	int overflow = 2147483650;
	std::cout << " overflow " << overflow << std::endl;

	char c = 65;
	char ch = 'A';
	int ascii = ch;
	std::cout << " c " << c << std::endl;
	std::cout << " ascii " << ascii << std::endl;

	std::vector<int> vecFrmArr(arr,arr+3);
	for (std::vector<int>::iterator it = vecFrmArr.begin(); it != vecFrmArr.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
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


#include "logger.hxx"
#include "LinkedList.hxx"

int main()
{
	Logger::Log("start logging");

	LinkedList<int> intList;
	int a = 1;
	intList.Insert(a);
	int b = 5;
	intList.Insert(b);
	int c = 100;
	intList.Insert(c);
	int d = 22;
	intList.Insert(d);
	intList.Print();
	return 1;
}

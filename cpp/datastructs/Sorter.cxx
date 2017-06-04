#include "Sorter.hxx"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void
Sorter::Sort(int arr[], SortType sType)
{
	/*switch (sType)
	{
		case S_QUICK_SORT:
			return qsort(arr);
	}*/
}

void
Sorter::qsort(int arr[])
{
}

void print(int* arr, int from, int to)
{
	if (to < from)
		return;

	for (int i = from; i < to; ++i)
	{
		cout << arr [i] << "  ";    
	}
	cout << endl;
}

void print(int* arr, const int& size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr [i] << "  ";    
	}
	cout << endl;
}

int partition(int* arr, const int& start, const int& end)
{
	cout << "Partition recvd " << endl;
	print(arr, start, end);
    int pivotVal = arr[end];
    int partitionIdx = start;
    
    for (int i = start; i < end; ++i)
    {
        if ( arr[i] <= pivotVal )
        {
            int temp = arr[partitionIdx];
            arr[partitionIdx] = arr[i];
            arr[i] = temp;
            ++partitionIdx;
        }
    }
    arr[end] = arr[partitionIdx];
    arr[partitionIdx] = pivotVal;
	cout << "Post partition "<< endl;
	print(arr, start, end);
    return partitionIdx;
}

void qsort(int* arr, const int& start, const int& end)
{
	if (start > end)
		return;

    int p = partition(arr, start, end);
    qsort(arr, start, p-1);
    qsort(arr,p+1, end);
}

void qsort(int* arr, int& size)
{
    qsort(arr, 0, size-1);
}

int main()
{
	int arr[10];
    srand( (unsigned int)time(0) );
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (rand() % 100);
    }
	int arrSize = 10;
    print(arr,arrSize);
    qsort(arr,arrSize);
	cout << "sorted list " << endl;
    print(arr,arrSize);
}

#include "Sorter.hxx"

void
Sorter::Sort(int arr[], SortType sType)
{
	switch (sType)
	{
		case S_QUICK_SORT:
			return qsort(arr);
	}
}

void
Sorter::qsort(int arr[])
{
	
}

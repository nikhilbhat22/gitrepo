#ifndef __SORTER_HXX__
#define __SORTER_HXX__
enum SortType
{
	S_QUICK_SORT;
	S_MERGE_SORT;
	S_BUBBLE_SORT;
};

class Sorter
{
private:
			void	qsort(int arr[]);
public:
	static	void	Sort(int arr[], SortType = S_QUICK_SORT);
	static	void	Sort(vector<int> vec, SortType=S_QUICK_SORT);
};

#endif

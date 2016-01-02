#include "SortingAlgorithms.h"

int main()
{
	Sorting s;
	int x[10] = { 0, 9, 2, 4, 7, 5, 6, 1, 3, 8 };
	s.MergeSort(x, 0, 9, 10);

	s.printSortedArray();
	std::cin.get();
	return 0;
}
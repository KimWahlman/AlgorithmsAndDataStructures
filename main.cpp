#include "SortingAlgorithms.h"
#include <iostream>

int main()
{
    Sorting s;

    int x[10] = { 0, 9, 2, 4, 7, 5, 6, 1, 3, 8 },
        y[10] = { 0, 9, 2, 4, 7, 5, 6, 1, 3, 8 };

    std::vector<int> z = { 0, 9, 2, 4, 7, 5, 6, 1, 3, 8 };

    std::cout << "Unsorted array & vector to sort:\n";
    for(int i = 0; i < 10; i++)
        std::cout << x[i] << " ";
    std::cout << "\n";
    for(int i = 0; i < 10; i++)
        std::cout << z[i] << " ";

    std::cout << "\n\nBubbleSort (Array): \n";
    s.BubbleArrayAscend(x, 10);
    s.printSortedArray();
    std::cout << "\n";
    s.BubbleArrayDescend(x, 10);
    s.printSortedArray();

    std::cout << "\n\nInsertionSort: \nArray\n";
    s.InsertionSortArray(y, 10);
    s.printSortedArray();
    std::cout << "\nVector\n";
    s.InsertionSortVector(z);
    s.printSortedVector();
    return 0;
}

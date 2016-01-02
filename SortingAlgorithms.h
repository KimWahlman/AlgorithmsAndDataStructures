#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>
#include <iostream>
class Sorting
{
    std::vector<int> mSortedVector;
    int *mSortedArray, mSize;
    std::vector<int> GetVector() const { return mSortedVector; }

	inline void Merge(int *arr, int l, int m, int r) {
		int n1 = m - l + 1,
			n2 = r - m;
		unsigned int i = 0, j = 0, k = 0;

		int* L = new int[n1];
		int* R = new int[n2]; // Left and Right array.

		for (i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1 + j];
		i = 0;
		j = 0;
		k = l;

		while (i < n1 && j < n2) {
			if (L[i] < R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}

    public:
        Sorting() : mSize(0) { }
		~Sorting() { }//delete[] mSortedArray; }

        // Sort in Ascending order
        inline void BubbleArrayAscend(int *a, int _size) {
            mSize = _size;
            mSortedArray = new int[_size];
            int i = 0, j = 0, temp = 0;
            for(; i < _size - 1; i++ ) {
                for(j = i; j >= 0; j--) {
                    if(a[ j ] > a[ j + 1]) { // swap
                        temp = a[ j + 1 ];
                        a[ j + 1 ] = a[ j ];
                        a[ j ] = temp;
                    }
                }
            }
           mSortedArray = a;
        }
        // Sort in Descending order
        inline void BubbleArrayDescend(int *a, int _size) {
            mSize = _size;
            mSortedArray = new int[_size];
            int i = 0, j = 0, temp = 0;
            for(; i < _size - 1; i++ ) {
                for(j = i; j >= 0; j--) {
                    if(a[ j ] < a[ j + 1]) { // swap
                        temp = a[ j ];
                        a[ j ] = a[ j + 1 ];
                        a[ j + 1 ] = temp;
                    }
                }
            }
           mSortedArray = a;
        }

        // Return a vector sorted in either descending or ascending order.
        inline std::vector<int> BubbleVectorSelectOrder(std::vector<int> &a, bool asc) {
            int i = 0, temp = 0;
            bool swapping = true;
            while(swapping) {
                swapping = false;
                for(i = 0; i < a.size() - 1; i++) {
                    if(asc) {
                        if(a[ i ] > a[ i + 1]) {
                            temp = a[ i + 1 ];
                            a[ i + 1 ] = a[ i ];
                            a[ i ] = temp;
                            swapping = true;
                        }
                    } else {
                        if(a[ i ] < a[ i + 1]) {
                            temp = a[ i + 1 ];
                            a[ i + 1 ] = a[ i ];
                            a[ i ] = temp;
                            swapping = true;
                        }
                    }
                }
            }
            return a;
        }

        inline void InsertionSortArray(int *a, int lenght) {
            mSize = lenght;
            mSortedArray = new int[lenght];
            int i = 0, j = 0, value = 0;
            for(i = 1; i < lenght; i++) {
                value = a[i];
                for(j = i - 1; j >= 0 && a[ j ] > value; j--)
                    a[ j + 1] = a[ j ];
                a[ j + 1 ] = value;
            }
            mSortedArray = a;
        }

        inline void InsertionSortVector(std::vector<int> &a) {
            for(unsigned int i = 1; i < a.size(); i++) {
                int j = i, temp = 0;
                while(j > 0 && a[ j - 1 ] > a[ j ]) {
                    temp = a[ j ];
                    a[ j ] = a[ j - 1 ];
                    a[ j - 1 ] = temp;
                    j--;
                }
            }
            mSortedVector = a;
        }

		inline void SelectionSort(int *arr, int size) {
			mSize = size;
			mSortedArray = new int[size];
			for (unsigned int last = size - 1; last >= 1; last--) {
				unsigned int indexOfLargest = 0;
				for (unsigned int index = 1; index <= last; index++)
					if (arr[index] > arr[indexOfLargest])
						indexOfLargest = index;
				unsigned int temp = arr[indexOfLargest];
				arr[indexOfLargest] = arr[last];
				arr[last] = temp;
			}
			
		}

		inline void MergeSort(int *arr, int l, int r, int size) {
			mSize = size;
			mSortedArray = new int[size];
			if (l < r) {
				int m = l + (r - l) / 2;
				MergeSort(arr, l, m, size);
				MergeSort(arr, m + 1, r, size);
				Merge(arr, l, m, r);
			}
			mSortedArray = arr;
		}

        inline void printSortedVector() const {
            for(unsigned int i = 0; i < mSortedVector.size(); i++)
                std::cout << GetVector()[i] << ", ";
        }

        inline void printSortedArray() const {
            for(unsigned int i = 0; i < mSize; i++)
                std::cout << mSortedArray[i] << ", ";
        }
};

#endif // SORTINGALGORITHMS_H

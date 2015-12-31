#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>

class MyQueue {
	int*			mArray;            // integer that will be used to create an array of size X + 10.
	unsigned int	mSize,              // Current size of the array.
					mCurrentElement;    // Current last used element

	inline void NewSize() {
		std::cout << "Current array full, resizing with 10, new size is ";
		int* temp = new int[mSize];

		for (unsigned int i = 0; i < mSize; i++) {
			temp[i] = mArray[i];
		}

		mSize += 10;
		mArray = new int[mSize];

		for (unsigned int i = 0; i < mSize - 10; i++) {
			mArray[i] = temp[i];
		}
		std::cout << mSize << ".\n\n";
	}

public:
	MyQueue() {
		mCurrentElement = 0;
		mSize = 10;
		mArray = new int[mSize];
	}

	~MyQueue() {
		delete[] mArray;
	}

	// O(n) ?
	inline void Push(int x) {
		if (mCurrentElement < mSize)
		{
			mArray[mCurrentElement] = x;
			mCurrentElement++;
		}
		else {
			NewSize();
			mArray[mCurrentElement] = x;
			mCurrentElement++;
		}
	}

	// Pops from the front
	// O(n)
	inline int Pop() {
		if (mCurrentElement > 0) {
			int* temp = new int[mSize];
			int fetchTemp = mArray[0];

			for (unsigned int i = 0; i < mSize; i++) {
				temp[i] = mArray[i + 1];
			}
			//delete[] mArray;
			//mArray = new int[mSize];
			for (unsigned int i = 0; i < mSize; i++) {
				mArray[i] = temp[i];
			}
			mCurrentElement--;
			return fetchTemp;
		}
	}

	//inline int GetElement(int x) const {
	//	int temp = mArray[x];
	//	if (x > mCurrentElement - 1) {
	//		std::cout << "Element " << x << " doesn't exist!\n";
	//		return -1;
	//	}
	//	return mArray[x];
	//}

	inline int GetSize() const { return mSize; }

	// Will produce the output
	// 10
	// 5
	// 34
	inline void Example() {
		if (mCurrentElement == 0) {
			Push(10);
			Push(5);
			Push(34);
			Push(58);
			Push(99);
			Push(98);
			Push(91);
			Push(19);
			Push(39);
			Push(779);
			Push(99923);

			std::cout << Pop() << "\n";
			std::cout << Pop() << "\n";
			std::cout << Pop() << "\n";
			std::cin.get();

			delete[] mArray;
			mCurrentElement = 0;
			mArray = new int[mSize];
		} else {
			std::cout << "Only use the example on a empty array please!\n\n";
		}
	}
};

#endif

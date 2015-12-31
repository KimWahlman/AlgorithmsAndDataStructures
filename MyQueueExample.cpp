#include "MyQueue.h"

int main() {
	MyQueue mq;

	mq.Example();

	mq.Push(10);
	mq.Push(5);
	mq.Push(34);
	mq.Push(58);
	mq.Push(99);
	mq.Push(98);
	mq.Push(91);
	mq.Push(19);
	mq.Push(39);
	mq.Push(779);
	mq.Push(99923);

	mq.Example();

	std::cout << mq.GetElement(0) << "\n";
	mq.Pop();
	std::cout << mq.GetElement(0) << "\n";
	mq.Pop();
	std::cout << mq.GetElement(0) << "\n";
	std::cin.get();
	return 0;
}
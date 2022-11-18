#include <iostream>
#include <array>

#define MAX_SIZE 10

class Queue {
private:
	int arr[MAX_SIZE];
	int f, r;
public:
	Queue()
		:f(-1), r(-1){}
	bool IsFull();
	bool IsEmpty();
	void Print();
	void Enqueue(int x);
	void Dequeue();
};

bool Queue::IsFull()
{
	if ((r+1)%MAX_SIZE == f) //cirular array, if the array element after rear is == f, the array is full
	{
		std::cout << "The queue is full" << std::endl;
		return true;
	}
	return false;
}

bool Queue::IsEmpty()
{
	if (f == -1 && r == -1)
		return true;

	return false;
}

void Queue::Enqueue(int x)
{
	if (IsFull())
		return;
	else if (IsEmpty())
	{
		f = 0;
		r = 0;
	}
	else
	{
		r = (r + 1) % MAX_SIZE; //set rear as the next element in the circular array
	}
	arr[r] = x; 
	std::cout << "[INFO] Queued: " << x << std::endl;
	return;
}

void Queue::Dequeue()
{
	std::cout << "[INFO] Dequeuing. " << std::endl;
	if (IsEmpty())
		return;
	else if (r == f)
	{
		f = -1;
		r = -1;
	}
	else
		f = (f + 1) % MAX_SIZE;

	return;
}

void Queue::Print()
{
	int count = (r + MAX_SIZE - f) % MAX_SIZE + 1;
	std::cout << "Queue: ";
	for (int i = 0; i < count; i++)
	{
		int index = (f + i) % MAX_SIZE;
		std::cout << arr[index] << " ";
	}
	std::cout << "\n";
}

int main()
{
	Queue Q;
	int A[MAX_SIZE];

	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Dequeue();

	Q.Print();
}
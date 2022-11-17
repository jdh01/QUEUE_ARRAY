#include <iostream>
#include <array>

#define MAX_SIZE 10

bool IsFull(int rear)
{
	if (rear == MAX_SIZE - 1)
	{
		std::cout << "The queue is full" << std::endl;
		return true;
	}
	return false;
}

bool IsEmpty(int f, int r)
{
	if (f == -1 && r == -1)
		return true;

	return false;
}

void Print(int A[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << "\n";
}

int* Enqueue(int A[], int f, int r, int x)
{
	//if rear is at max index (sizeof(A)-1)
	//print "queue is full"
	//if the queue is empty set front and rear to 0
	//set rear +1, enqueue the data A[rear] = x
	if ((r + 1) % MAX_SIZE == f)
		return A;
	else if (IsEmpty)
	{
		f = 0;
		r = 0;
	}
	else
	{
		r = (r + 1) % MAX_SIZE;
	}
	A[r] = x;
	return A;
}

int* Deqeue(int A[], int f, int r)
{
	if (IsEmpty)
		return A;
	else if (r == f)
	{
		f = -1;
		r = -1;
	}
	else
		f = (f + 1) % MAX_SIZE;

	return A;
}

int main()
{
	int A[MAX_SIZE];
	int front = -1;
	int rear = -1;
	IsEmpty(front, rear);
	Enqueue(A, front, rear, 1);
	Enqueue(A, front, rear, 2);
	Enqueue(A, front, rear, 3);
	Enqueue(A, front, rear, 4);
	Deqeue(A, front, rear);

	Print(A);
}
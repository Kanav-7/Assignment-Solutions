#include "stdio.h"
#include "stdlib.h"

int MAX=100,Queue[100],front=-1,rear=-1;
void Enqueue(int value)
{
	rear++;
	Queue[rear]=value;
	if (front==-1&&rear==0)
		front++;
	return ;
}

void Dequeue()
{
    front++;
    return ;
}

int head()
{
	return Queue[front];
}

int IsEmpty()
{
	if(front=-1&&rear==-1)
		return 1;
	return 0;
}
void print()
{
	for (int i = front; i <= rear; ++i)
	{
		printf("%d\t",Queue[i]);
	}
	printf("\n");
	return ;
}

int main()
{
	Enqueue(5);
	Enqueue(4);
	Enqueue(76);
	Enqueue(102);
	print();
	Dequeue();
	Dequeue();
	print();
	return 0;
}




#include "stdio.h"
#include "stdlib.h"
int MAX_SIZE=10000;
int Stack[10000],top=-1;
void push(int value)
{
	if (top==MAX_SIZE-1)
	{
		printf("Invalid move\n");
		return ;
	}
	Stack[++top]=value;
	return;
}
void pop()
{
	if (top==-1)
	{
		printf("Invalid move\n");
		return;
	}
	top--;
	return;
}
int val()
{
	if (top==-1)
	{
		printf("Invalid move\n");
		return 0;
	}
	return Stack[top];
}
int size()
{
	return (top+1);
}
void print()
{
	if (top==-1)
	{
		printf("Invalid move\n");
		return;
	}
	for (int i = 0; i <= top; ++i)
	{
		printf("%d\t",Stack[i]);
	}
	printf("\n");
	return;
}


int main()
{
	push(5);
	push(4);
	push(3);
	print();
	pop();
	pop();
	push(67);
	print();
	printf("%d\t%d\n",size(),val());
	return 0;
}
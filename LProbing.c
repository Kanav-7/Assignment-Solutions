#include "stdio.h"

void put(int num,int Arr[])
{
	int j = num%100000;
		while(1)
			{
				if(Arr[j] == -1)
				{
					Arr[j] = num;
					return;
				}
				j++;
				if(j==100000)
					j=0;
				if(j==num%100000)
				{
					printf("No empty Space\n");
					return;
				}
			}
}

void get(int n,int Arr[])
{
	int j = n%100000;
	while(1)
	{
		if(Arr[j] == n)
		{
			printf("Element is present\n");
			return;	
		}
		j++;
		if(j==100000)
			j=0;
		if(Arr[j]==-1||j==n%100000)
		{
			printf("Element is not present\n");
			return;
		}
	}
}

void delete(int n,int Arr[])
{
	int j = n%100000;
	while(1)
	{
		if(Arr[j] == n)
		{
			Arr[j] = -1;
			return;	
		}
		j++;
		if(j==100000)
			j=0;
		if(Arr[j]==-1||j==n%100000)
		{
			printf("Element is not present\n");
			return;
		}
	}
}

int main()
{
	int Arr[100000];
	memset(Arr,-1,sizeof(Arr));
	printf("%d\n",Arr[6]);
	put(5,Arr);
	put(100005,Arr);
	delete(5,Arr);
	get(5,Arr);
	get(100005,Arr);
	return 0;
}

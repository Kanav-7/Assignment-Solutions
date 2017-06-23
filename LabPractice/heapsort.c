#include "stdio.h"

void swap(int* a,int* b)
{		
	int temp = *a;
	*a = *b;
	*b=temp;
	return;
}

void heapify(int a[],int n,int t)
{
	int temp= t;
	if(a[2*t+1] > a[t] && ((2*t+1) < n))
		t = 2*temp+1;
	if(a[2*t+2] > a[t] && ((2*t+2 )< n))
		t = 2*temp+2;
	if(t!=temp)
	{
		swap(&a[temp],&a[t]);
		heapify(a,n,t);
	}
	return;
}

void Hsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>-1;i--)
		heapify(a,n,i);

	for(i=0;i<n;i++)
	{
		swap(&a[0],&a[n-i-1]);
		heapify(a,n-i-1,0);
	}
	return ;
}


int main()
{
	int i,n,a[10000];
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}

	Hsort(a,n);
	for ( i = 0; i < n; ++i)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
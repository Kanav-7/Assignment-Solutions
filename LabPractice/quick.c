#include "stdio.h"

int Upperbound(int a[],int num,int val)
{
	int low = 0,high= num-1;
	int mid = low + (high-low)/2 , ans = high;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if(a[mid] > val)
			ans = mid, high = mid-1;
		else
			low = mid+1;
	}
	return ans-1;
}

int Lowerbound(int a[],int num,int val)
{
	int low = 0,high= num-1;
	int mid = low + (high-low)/2 , ans = high;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if(a[mid] >= val)
			ans = mid, high = mid-1;
		else
			low = mid+1;
	}
	return ans;
}

int BinSearch(int a[],int num,int val)
{
	int low = 0,high= num-1;
	int mid = low + (high-low)/2;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if(a[mid] > val)
			high = mid - 1;
		else if(a[mid] < val)
			low = mid + 1;
		else 
			return 1;
	}
	return 0;
}

int cmp(const int* a , const int* b)
{	
	return *(int*)a - *(int*)b;
}

int main()
{
	int i,n,a,b,c;
	int sd[10000];
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&sd[i]);
	}

	qsort(sd,n,sizeof(int),cmp);
	scanf("%d%d%d",&a,&b,&c);
	printf("Result of BinSearch is %d\n",BinSearch(sd,n,a));
	printf("Lowerbound is %d\n",Lowerbound(sd,n,b));
	printf("Upperbound is %d\nSorted Array is:- \n", Upperbound(sd,n,c));
	for ( i = 0; i < n; ++i)
	{
		printf("%d\n",sd[i]);
	}
	return 0;
}
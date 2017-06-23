//Kanav Gupta
#include "stdio.h"
#include "stdlib.h"

int a[1000000];

int mx(int a,int b)
{
	return ((a>b)?a:b);
}
void update(int arr[],int l,int r,int find,int curr,int val)
{
	if(l == r){	arr[curr] = val; return;}
	int mid = (l+r)/2;
	if(find <= mid && find >= l) update(arr,l,(l+r)/2,find,2*curr,val);
	else if(find>mid && find <= r) update(arr,(l+r)/2+1,r,find,2*curr+1,val);
	arr[curr] = arr[2*curr]+arr[2*curr+1];
	//if(arr[2*curr] > arr[2*curr+1])
}
int search(int arr[],int l,int r,int curr,int x1,int x2)
{
	if(r < x1 || x2 < l) return 0;
	if(l >= x1 && r <= x2) return arr[curr];
	return search(arr,l,(l+r)/2,2*curr,x1,x2)+search(arr,(l+r)/2+1,r,2*curr+1,x1,x2);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d",&num);
		//update(a,1,n,i,1,num);
		update(a,1,n,i,1,num*num*num);
	}
	for (int i = 1; i <= 4*n; ++i)
		printf("%d ",a[i]);

	int k = search(a,1,n,1,2,3);
	//int k = range_query(a,2,3,1,n,1);
	printf("%dA\n",k);	
	return 0;
}

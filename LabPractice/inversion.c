#include "stdio.h"

int Merge(int a;int t;int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;
	int ans = 0;
	while(i<mid && j < right)
	{
		if(a[j] >= a[i])
		{
			t[k++]=a[i++]
		}
		else
		{
			t[k++] = a[j++];
			ans+=mid-i;
		}
	}

	
}
int MergeSort(int a[],int t[],int left,int right)
{
	int mid = left + (right-left)/2;
	int ans = 0;
	if(left < right)
	{
		mid = left + (right-left)/2;
		ans+= MergeSort(a,t,left,mid);
		ans+= MergeSort(a,t,mid,right);
		ans+= Merge(a,t,left,mid+1,right);
	}
	return ans;
}

int main()
{
	int i,n,a[100],t[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	printf("%d\n",MergeSort(a,t,0,n-1));
}
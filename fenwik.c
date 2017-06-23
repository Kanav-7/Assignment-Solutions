#include "stdio.h"

int A[1000000],Fenwik[1000000];

void update(int pos,int val,int n,int key)
{
	int i = pos+1;
	if(key == 1)
	{
		while(i <= n)
		{
			Fenwik[i]+=(val-A[pos]);
			i+=i&(-i);
		}
		A[pos]  = val;
	}
	else
	{
		while(i <= n)
		{
			Fenwik[i]+=val;
			i+=i&(-i);
		}
	}		
}
int range(int pos)
{
	int i = pos+1,ans=0;
	while(i>0)
	{
		ans+=Fenwik[i];
		i-=i&(-i);
	}
	return ans;
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
		update(i,A[i],n,0);
	printf("%d\n",range(3));
	update(3,-5,n,1);
	printf("%d\n",range(3));	
}
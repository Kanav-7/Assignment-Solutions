#include "stdio.h"
	#include "math.h"
int Arr[1000000],MinStack[1000000],MinStack2[1000000];

int evaluate(int a,int b)
{
	return (a|b)*(a|b) - (a&b)*(a&b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	
		int k=2;
		int i,n;
		scanf("%d",&n);
		for (i=1;i <= n; ++i)
		{
			scanf("%d",&Arr[i]);
			if(i==1)
				MinStack[1] = Arr[1];
			else
			{
				MinStack[k]= ((MinStack[k-1] > Arr[i])?Arr[i]:MinStack[k-1]);
				k++;   
			}
		}
		k=n-1;
		for(i=n;i>0;i--)
		{
			if(i==n)
				MinStack2[n] = Arr[n];
			else
			{
				MinStack2[k]= ((MinStack2[k+1] > Arr[i])?Arr[i]:MinStack2[k+1]);
				k--; 
			}
		}
		int max = -1;
		for(i=1;i<=n;i++)
		{
			if(evaluate(Arr[i],MinStack[i]) > max)
				max = evaluate(Arr[i],MinStack[i]);
			if(evaluate(Arr[i],MinStack2[i]) > max)
				max = evaluate(Arr[i],MinStack2[i]);
		}
		printf("%d\n",max);

	}
	return 0;
}




#include "stdio.h"
long long int max=-100,Arr[1000000],Stack[1000000];

long long int evaluate(long long int a,long long int b)
{
	return ((a|b)*(a|b) - (a&b)*(a&b));
}

void check(long long int i,long long int top)
{
	if(evaluate(Arr[i],Stack[top]) > max)
		max = evaluate(Arr[i],Stack[top]);
	return ;
}

int main()
{
	long long int t,x;
	scanf("%lld",&t);
	for(x=1;x<=t;x++)
	{
		long long int i,n;
		scanf("%lld",&n);
		max = -100;
		long long int top = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&Arr[i]);
			if(i==1)
			{
				top++;
				Stack[top] = Arr[i];
			}
			else
			{
				while(Stack[top] >= Arr[i] && top!=-1)
				{
					check(i,top);		
					top--;
				}		
				if(top!=0)
					check(i,top);
				top++;
				Stack[top] = Arr[i];
			}

		}
			printf("%lld\n",max);
	}
	return 0;
}
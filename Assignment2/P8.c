#include "stdio.h"

long long int Stack[100000],top=-1;

void push(long long int value)
{
	Stack[++top]=value;
	return;
}

void pop()
{
	top--;
	return;
}

int val()
{
	return Stack[top];
}
int main()
{
	long long int l,t;
	scanf("%lld",&t);
	for(l=0;l<t;l++)
	{
		top=-1;
		long long int j,q,x,y[100000],temp=0,sum=0;
		scanf("%lld",&q);
		for(j=0;j<q;j++)
		{
			scanf("%lld",&x);
			if(x==1)
			{
				scanf("%lld",&y[temp]);
				temp++;
				sum+=y[temp-1];
				if(y[temp-1] < val()|| temp ==	 1)
					push(y[temp-1]);
				else
					push(val());
				printf("%lld %lld\n",val(),sum);
			}
			if(x==2)
			{
				if(temp > 0)
				{	
					sum-=y[temp-1];
					temp--;
					pop();
					if(temp > 0)
						printf("%lld %lld\n",val(),sum);
					else
						printf("-1 0\n");
				}
				else
					printf("-1 0\n");
			}
		}
	}
	return 0;
}
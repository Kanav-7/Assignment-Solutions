#include "bits/stdc++.h"
using namespace std;

int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int mark[200];
		char a[200];
		scanf("%s",a);
		int x = strlen(a);
		int s=0,m=0;

		for(int i=0;i<110;i++)
			mark[i] = 0;

		for(int i=0;i<x;i++)
		{
			if(a[i] == 's')
				s++;
			else
				m++;
		}
		for(int i=0;i<x;i++)
		{
			if(a[i]== 'm' && a[i-1] == 's' && mark[i-1] == 0 && i!=0)
			{
				s--;
				mark[i-1] = 1;
			}
			else if(a[i]== 'm' && a[i+1] == 's' && mark[i+1] == 0 && i!=x-1)
			{
				s--;
				mark[i+1] = 1;
			}
		}
		if(s==m)
			printf("tie\n");
		else if(s>m)
			printf("snakes\n");
		else
			printf("mongooses\n");

	}
	return 0;
}
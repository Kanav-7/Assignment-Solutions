#include "stdio.h"
#include "stdlib.h"

int G[1002][1002],In[10000],Ans[1000];

void initialize()
{
	int i,j;
	for(i=0;i<1002;i++)
	{
		In[i]  = 0;
		Ans[i] = 0;
		for(j=0;j<1002;j++)
			G[i][j] = 0;
	}
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		initialize();
		int m,n;
		scanf("%d%d",&m,&n);
		while(n--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			In[a]++;
			G[b][a]++;
		}
		int i,j,k;
		for(i=0;i<m;i++)
		{
			int max = 0;
			for(j=1;j<=m;j++)
			{
				if(In[j] == 0 && j > max)
					max = j;
			}
			Ans[m-i-1] = max;
			In[max] = -1;
			for(k=1;k<=m;k++)
			{
				if(G[max][k] > 0)
					In[k]--;
			}
		}
		for(i=0;i<m;i++)
			printf("%d ",Ans[i]);
		printf("\n");
	}
	return 0;
}
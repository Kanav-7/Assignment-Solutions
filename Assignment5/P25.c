#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct vertex
{
	long long int inList;
	long long int minEdge;
}ver;

typedef struct Point
{
	long long int x;
	long long int y;
}point;

ver A[1600];
point Arr[1600];
long long int G[1600][1600],n,Infinite = 2000000005;
long long int ans = 0;

void initialize()
{
	int i;
	for (i = 0; i <= 1600; ++i)
	{
		A[i].minEdge = Infinite;
		A[i].inList = 0;
	}
	return ;
}
long long int prims()
{	
	long long int ans = 0;	
	A[0].minEdge = 0;
	int count = 0;
	while(count <= n)
	{
		long long int u,i,min = Infinite;
		//printf("%lld %lld\n",min,A[1].minEdge);
		for (i = 0; i <=n ; ++i)
		{
			if(A[i].minEdge < min && A[i].inList == 0)
			{
				u = i;
				min = A[i].minEdge;
			}
		}
		//printf("%lldU\n",u);
		ans+=A[u].minEdge;
		A[u].inList = 1;

		for(i = 0; i <=n ;i++)
		{
			if(G[u][i] < A[i].minEdge && A[i].inList == 0)
			{
				A[i].minEdge = G[u][i];
			}
		}

		count++;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		int i,j;
		Arr[0].x = 0;
		Arr[0].y = 0;
		for(i=1;i<=n;i++)
			scanf("%lld %lld",&Arr[i].x,&Arr[i].y);

		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				G[i][j] = abs(Arr[i].x - Arr[j].x) + abs(Arr[i].y - Arr[j].y);
				if(i == j)
					G[i][j] = Infinite;
				//printf("%lld  ",G[i][j]);
			}
			//printf("\n");
		}
		initialize(A,Infinite);
		ans = prims(n,A,G,Infinite);
		printf("%lld\n",ans);
	}
	return 0;
}
#include "stdio.h"
#include "stdlib.h"

typedef struct Unionfy
{
	int parent,height;
}unn;

typedef struct node
{
	int u,v,e;
}nd;

int compare (const void * a, const void * b)
{
  nd *A = (nd *)a;
  nd *B = (nd *)b;

  return ( A->e-B->e);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,m,n;
		nd Arr[500005];
		unn Unon[100005];
		for(i=0;i<500005;i++)
		{
			Unon[i].parent = i;
			Unon[i].height  = 0;	
		}
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&Arr[i].u,&Arr[i].v,&Arr[i].e);
		qsort(Arr,m,sizeof(nd),compare);
		int count=0,key = 1;
		long long int ans=0;
		i=0;
		while(count < n-1 || key==1)
		{
			int p1=Arr[i].u;
			while(Unon[p1].parent!=p1)
				p1=Unon[p1].parent;
			int p2=Arr[i].v;
			while(Unon[p2].parent!=p2)
				p2=Unon[p2].parent;
			if(p2!=p1)
			{
				count++;
				ans+=Arr[i].e;
				if(Unon[p2].height > Unon[p1].height)
				{
					Unon[p1].parent = p2;
				}
				else if(Unon[p1].height == Unon[p2].height)
				{
					Unon[p2].parent = p1;
					Unon[p1].height++;
				}
				else
					Unon[p2].parent = p1;
			}
			else if(p2==p1 && key==1)
			{
				ans+=Arr[i].e;
				key = 0;
			}
			i++;				
		}
		printf("%lld\n",ans);
	}
}



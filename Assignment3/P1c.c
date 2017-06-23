#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

long long int ans[100005],sarr[1000000],arr[1000000],Tsarr[100005],Tarr[100005],Rank[1000000];
char str[1000000];

int cmp(const void*a,const void* b)
{
	long long int i = *(long long int*)a;
	long long int j = *(long long int*)b;
	 if( Tarr[i] - Tarr[j] < 0 )
        return -1;
    if( Tarr[i] - Tarr[j] > 0 )
        return 1;
    if( Tarr[i] - Tarr[j] == 0 )
        return 0;
}

int main()
{
	long long int t,l;
	scanf("%lld",&t);
	for (l= 0; l < t; l++)
	{
		long long int j,i,n;
		long long int k=0;

		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			long long int mask[65] = {0};
			scanf("%s",str);
			for(j=0;j<strlen(str);j++)
			{
				if(str[j] <= '9'&&str[j] >='0')
					mask[str[j]-'0'] = 1;
				else if(str[j] <= 'z'&&str[j] >='a')
					mask[str[j]-'a'+10] = 1;
				else if(str[j] <= 'Z'&&str[j] >='A')
					mask[str[j]-'A'+36] = 1;
			}
			//printf("1\n");
			long long int temp=0;
			for (j = 0; j < 63; j++)
			{
				temp+=pow(2,j)*mask[j];
			}	
			//printf("1\n");
			arr[i] = temp;
			sarr[i] = i;
		}	
		for(i=0;i<n;i++)
		{
			Rank[i]  = i;
			Tarr[i] = arr[i];
			Tsarr[i] = sarr[i];
		}

		//for (i = 0; i < n; ++i)
		//{
		//	printf("%lld %lld\n",arr[i],sarr[i]);
		//}
		//printf("\n");
		qsort(Rank,n,sizeof(long long int),cmp);
		for (i = 0; i < n; ++i)
		{
			arr[i] = Tarr[Rank[i]];
			sarr[i] = Tsarr[Rank[i]];
		}
		//for (int i = 0; i < n; ++i)
		//{
		//	printf("%lld %lld\n",arr[i],sarr[i]);
		//}
		int r=0;
		while(r<n)
		{
			int x=r;
			while(arr[x+1]==arr[x]&&x+1<n)
			{
				x++;
			}
			int y;
			for(y=r;y<=x;y++)
				ans[sarr[y]] = x-r+1;
			r=x+1;
		}
		for (i = 0; i < n-1; ++i)
		{
			printf("%lld ",ans[i]);
		}
		printf("%lld\n",ans[n-1]);
	}
	return 0;
}	
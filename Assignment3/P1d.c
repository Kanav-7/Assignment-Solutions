#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

typedef struct value
{
	long long int data;
	long long int index;
}val;

int ans[1000000];
val arr[1000000];
char str[1000005];

long long int powercal(int x)
{
	long long int i,ans = 1;
	for (i = 0; i < x; ++i)
		ans*=2;
	return ans;
}

int cmp(const void * a, const void * b)
{
  val *i = (val *)a;
  val *j = (val *)b;
	if( i->data - j->data < 0 )
        return -1;
    else if( i->data - j->data > 0 )
        return 1;
    else
        return 0;
}
int main()
{
	int t,l;
	scanf("%d",&t);
	for (l= 0; l < t; l++)
	{
		int j,i,n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			int mask[65] = {0},var;
			long long int temp=0;
			scanf("%s",str);
			for(j=0;j<strlen(str);j++)
			{
				if(str[j] <= '9'&&str[j] >='0')
					var = str[j]-'0';
				else if(str[j] <= 'z'&&str[j] >='a')
					var = str[j]-'a'+10;
				else if(str[j] <= 'Z'&&str[j] >='A')
					var = str[j]-'A'+36;
				if(mask[var] == 0)
				{
					temp+=powercal(var);
					mask[var] = 1;
				}
			}
			arr[i].data = temp;
			arr[i].index = i;
			printf("%lld %lld\n",arr[i].data,arr[i].index);
		}
		for (int i = 0; i < n; ++i)
		{
		printf("%lld %lld\n",arr[i].data,arr[i].index);
		}
		qsort(arr,n,sizeof(val),cmp);
		for (int i = 0; i < n; ++i)
		{
		printf("%lld %lld\n",arr[i].data,arr[i].index);
		}
		for(i=0;i<n;i++)
		{
			int x=i;
			while(arr[x+1].data==arr[x].data&&x+1<n)
				x++;
			int y;
			for(y=i;y<=x;y++)
				ans[arr[y].index] = x-i+1;
			i=x;
		}
		
		for (i = 0; i < n; i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}	
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

typedef struct value
{
	long long int data;
	long long int index;
}val;
long long int power(int x)
{
	long long int ans = 1;
	for (int i = 0; i < x; ++i)
	{
		ans*=2;
	}
	return ans;
}

int ans[1000000];
val arr[1000000];
char str[1000005];

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
					 mask[str[j]-'0'] = 1;
				else if(str[j] <= 'z'&&str[j] >='a')
					 mask[str[j]-'a'+10] = 1;
				else if(str[j] <= 'Z'&&str[j] >='A')
					mask[str[j]-'A'+36] =1;
				//if(mask[var] == 0)
				//{
				//	printf("%lld %d\n",temp,var);
				//	temp+=pow(2,var);
				//	mask[var] = 1;
				//}
			}
			long long  int power = 1;
			for (j = 0; j < 62; j++)
			{
				temp+=power*mask[j];
				power*=2;
			}	
			//printf("%lld %lld\n",temp,power);
			arr[i].data = temp;
			arr[i].index = i;
		}	
		
		qsort(arr,n,sizeof(val),cmp);
		
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
			printf("%d \n",ans[i]);
		printf("\n");
	}
	return 0;
}	
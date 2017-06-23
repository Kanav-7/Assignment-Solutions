#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
int mod = 1000009;
int base = 23;
int sarr[1000000],arr[1000000];
char str[1000000];
int cmp(const void* a,const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int t,l;
	scanf("%d",&t);
	for (l= 0; l < t; l++)
	{
		int hash[1000007] = {0};
		int j,i,n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			int len = strlen(str);
			for(j=0;j<len;j++)
				sarr[j] = str[j]; 
			qsort(sarr,len,sizeof(int),cmp);
			int temp = sarr[0];
			int mult = 17;	
			for(j=1;j<len;j++)
			{
				if(sarr[j-1]!=sarr[j])
				{

					temp = (temp + sarr[j]*mult)%mod;
					mult = (mult*base)%mod;
				}
			}
			arr[i]= temp;
			hash[temp]++;
		}
		for(i=0;i<n-1;i++)
			printf("%d ",hash[arr[i]]);
		printf("%d\n",hash[arr[n-1]]);
	}
	return 0;
}
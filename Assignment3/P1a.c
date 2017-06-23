#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

nt cmp(const void * a, const void * b)
{

  val *i = (val *)a;
  val *j = (val *)b;
	if( i->data - j->data < 0 )
        return -1;
    if( i->data - j->data > 0 )
        return 1;
    if( i->data - j->data == 0 )
        return 0;
}
int sarr[1000000],arr[1000000];
char str[1000000];
int compare (const void *a, const void *b)
{
	int i,j;
    return  (const int*)Arr[i]- (const int *)Arr[j];
}
compare

int main()
{
	int t,l;
	scanf("%d",&t);
	for (l= 0; l < t; l++)
	{
		int hash[1000007] = {0};
		int j,i,n;
		int k=0;

		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			int mask[65] = {0};
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
			long long int temp=0;
			for (j = 0; j < 63; ++j)
			{
				temp+=pow(2,j)*mask[j];
			}
			int flag=0;
			//printf("%d\n",temp);
			for(j=0;j<k;j++)
			{
				//printf("%d\n",arr[0]);
				if(arr[j]==temp)
				{
					hash[i]=j;
					sarr[j]++;
					flag=1;
					//printf("%d ",sarr[j]);
					break;
				}
			}
			if(flag==0)
			{
				hash[i]=k;
				arr[k]=temp;
				sarr[k]=1;
				k++;
			}
		}
		for (i = 0; i < n-1; ++i)
		{
			printf("%d ",sarr[hash[i]]);
		}
		printf("%d\n",sarr[hash[n-1]]);
	}
	return 0;
}
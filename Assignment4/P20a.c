#include "stdio.h"
#include "math.h"
#include "string.h"

char num[1000000],bucket[11][100005];
int main()
{
	scanf("%s",num);
	//printf("%s\n", num);
	int i,j=0,n = strlen(num);
	int k = sqrt(n);

	bucket[num[0] - '0'][0]++;
	if(i=1;i<n;i++)
	{
		for(j=0;j<11;j++)
			bucket[j][i] = bucket[j][i-1];
		bucket[num[i] - '0'][i]++;
	}

	int q;
	scanf("%d",&q);

	while(q--)
	{
		
	}


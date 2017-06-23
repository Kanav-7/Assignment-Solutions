#include "stdio.h"
int i,Rank[1000000],Arr[1000000],Dur[1000000],n;

int compare (const void *a, const void *b)
{
	int i,j;
    return  (const int*)Arr[i]- (const int *)Arr[j];
}
compare

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&Arr[i],&Dur[i]);

	qsort(Rank,sizeof(int),compare);
	for (int i = 0; i < n; ++i)
	{
		Arr[i]=Arr[Rank[i]];
		Dur[i]=Durr[Rank[i]];
		printf("%d\n%d\n",Arr[i],Dur[i]);
	}


}
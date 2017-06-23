#include "stdio.h"

#define scan(x) scanf("%d",&x);
int main()
{
	int test;
	scan(test);
	while(test--)
	{
		int t,i,n,BST[100007],path[100007];
		scan(n);
		for(i=0;i<n;i++)
			scan(BST[i]);
		scan(t);
		for(i=0;i<t;i++)
			scan(path[i]);
		int way1 = path[0],way2 = path[t-1];
		int subpath1[100005],subpath2[100005];
		int min = -100000000,max = 100000000;
		int j=-1;
		for(i=0;i<n;i++)
		{
			if(BST[i]==way1)
			{
				j++;
				subpath1[j]=BST[i];
				break;
			}

		    else if(BST[i] >= min && BST[i] <= max && way1 > BST[i])
			{
				j++;
				subpath1[j]=BST[i];
				min = subpath1[j];
			}

		    else if(BST[i] >= min && BST[i] <= max && way1 < BST[i])
			{
				j++;
				subpath1[j]=BST[i];
				max = subpath1[j];
			}
		}
		min = -100000000,max = 100000000;
		int k=-1;
		for(i=0;i<n;i++)
		{
			//printf("A\n");
			if(BST[i]==way2)
			{
				k++;
				subpath2[k]=BST[i];
				break;
			}

		    else if(BST[i] >= min && BST[i] <= max && way2 > BST[i])
			{
				k++;
				subpath2[k]=BST[i];
				min = subpath2[k];
			}

		    else if(BST[i] >= min && BST[i] <= max && way2 < BST[i])
			{
				k++;
				subpath2[k]=BST[i];
				max = subpath2[k];
			}
			//printf("%dK\n",k );
		}
		/*for (int i = 0; i <= j; ++i)
		{
			printf("%d ",subpath1[i]);
		}
		//printf("\n%dk",k);
		for (int i = 0; i <=k; ++i)
		{
			printf("%d ", subpath2[i]);
		}
		printf("\n");*/
		int m=0,p=0;
		while(subpath1[m+1]==subpath2[p+1]&& m+1 <=j && p+1 <=k)
		{
			m++;
			p++;
		}
		int x=0,combine[100007];
		while(j >= m)
			combine[x++] = subpath1[j--];
		p++;
		while(p <= k)
			combine[x++] = subpath2[p++];
		/*for (int i = 0; i < x; ++i)
		{
			printf("%d ",combine[i]);
		}*/
		int ans = 1;	
		for(i=0;i<x;i++)
		{
			if(combine[i]!=path[i])
			{
				ans = 0;
				break;
			}
		}
		if(x!=t)
			ans =0;		
		if(ans == 1)
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}
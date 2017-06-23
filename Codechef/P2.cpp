#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int maxans = 10000,i,j,p,a[1000][600],mx1[1000],mx2[1000];
		int n,m,maxi=-1,k=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				if(maxi < a[i][j])
					maxi = a[i][j];
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if(a[i][j] == maxi)
				{
					mx1[k] = i;
					mx2[k] = j;
					k++;
				}
			}
		}
		//cout << k << " " ;
		//cout << maxi << mx1[1] << mx2[1];
		int maxdist = 0,flag = 0;
		maxans = max(m,n);
		for (i = 0; i < n; ++i)
		{
			if(flag == 1)
				break;
			for (j = 0; j < m; ++j)
			{
				if(flag == 1)
					break;
				if(a[i][j] != maxi)
				{
					int mindist = 10000;
					for(p=0;p<k;p++)
					{
						int var = max(abs(mx1[p] - i),abs(mx2[p] - j));
						if(var < mindist)
						{
							mindist = var;
						}
						if(var == 1)
							break;
					}
					//cout << mindist;
					if(mindist > maxdist)
					{
						maxdist = mindist;
						if(maxdist == maxans)
							flag = 1;
					}
				}

			}
		}
		printf("%d\n",maxdist);
	}
	return 0;
}
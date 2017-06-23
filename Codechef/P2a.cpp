#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,b[1000][600],a[1000][600];
		int count=0,n,m,maxi=-1;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				b[i][j] = 0;
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
					count++;
				}
			}
		}

		int flag=0,	ans = 0;
		while(count < m*n)
		{	
			for(i = 0;i<n;i++)
			{
				// if(flag == 1)
				// 	break;

				for(j=0;j<m;j++)
				{
					if(a[i][j]!= maxi)
					{
						if((a[i-1][j-1] == maxi && i!=0 && j!=0)
							|| (a[i][j-1] == maxi && j!=0)||
							 (a[i+1][j-1] == maxi && j!=0 && i!=n-1)||
							 ( a[i-1][j] == maxi && i!= 0)||
							 (a[i+1][j] == maxi && i!= n-1) ||
							 (a[i-1][j+1] == maxi && i!=0 && j!= m-1)||
							 (a[i][j+1] == maxi && j!=m-1)||
							 (a[i+1][j+1] == maxi && i!=n-1 && j!= m-1))
						{
							//cout << i << " " << j << "\n";
							b[i][j] = maxi;
							count++;
						}	
					}
					// if(count == m*n)
					// {
					// 	//cout << "yo";
					// 	flag = 1;
					// 	break;
					// }
				}
			}
			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < m; ++j)
				{
					if(b[i][j] == maxi)
						a[i][j] = maxi;
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}	
	return 0;
}
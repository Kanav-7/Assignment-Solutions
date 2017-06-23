#include "stdio.h"
#include "string.h"


int p[100005][3];
int dp[1005][1005];

void initialize()
{
	int i,j;
	for(i = 0;i<1005;i++)
		for(j=0;j<1005;j++)
			dp[i][j] = 1000000007;
}

int main()
{
	initialize();
	int n,m,k,i,j;
	scanf("%d%d%d",&n,&m,&k);
	for (i = 0; i < m; ++i)
		scanf("%d%d%d",&p[i][0],&p[i][1],&p[i][2]);

	dp[1][1] = 0;

	int ans=0;
	for (i=1;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			int u = p[j][0],v = p[j][1],w = p[j][2];
			if (dp[u][i] + w < dp[v][i+1])
				dp[v][i+1] = dp[u][i] + w;
		}
		if (dp[n][i+1] <= k)
			ans = i+1;
	}
	printf("%d\n",ans);
	return 0;
}
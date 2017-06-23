#include "iostream"
using namespace std;

int INF = 10000000;
int A[1000][1000];

int main()
{
	int n,m;
	cin >> n >> m;
	long long int ans = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			{
				A[i][j] = INF;
				if(i==j)
					A[i][j] = 0;
			}

	for(int i=0;i<m;i++)
	{
		int u,v,t;
		cin >> u >> v >> t;
		if(A[u][v] < t || A[u][v] == INF)
		{
			A[v][u] = t;
			A[u][v] = t;
		}
	}

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ans += A[i][j];

	cout << ans << endl;
	return 0;
}
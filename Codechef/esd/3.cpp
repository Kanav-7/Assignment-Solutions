#include "bits/stdc++.h"
using namespace std;

vector<int> G[3000];
int visited[3000];
int degree[3000];

void dfs(int start)
{
	visited[start] = 1;
	for(auto v: G[start])
	{
		if(visited[v] == 0)
		{
			dfs(v);
			break;
		}
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		char a[1000],b[1000];
		cin >> a >> b;
		for(int i=0;i<3*n;i++)
		{
			degree[i] = 0;
			visited[i] = 0;
			G[i].clear();
		}

		for(int i=0;i<n;i++)
		{
			if(a[i]=='#')
			{
				if(i < (n-1) && a[i+1] == '#')
				{
					G[i].push_back(i+1);
					G[i+1].push_back(i);
					// degree[i]++;
					// degree[i+1]++;
				}
				if(b[i] == '#')
				{
					G[i].push_back(i+n);
					G[i+n].push_back(i);
					// degree[i]++;
					// degree[i+n]++;
				}
			}
			if(b[i] == '#')
			{
				if(i < (n-1) && b[i+1] == '#')
				{
					G[i+n].push_back(i+n+1);
					G[i+1+n].push_back(i+n);
					// degree[i+n]++;
					// degree[i+n+1]++;
				}
			}
			if(a[i] == '.')
				visited[i] = 1;
			if(b[i] == '.')
				visited[i+n] = 1;
			//if(degree[i] > 2 || degree[i+n] > 2 || degree[])
		}
		int count = 0;
		for(int i=0;i<2*n;i++)
		{
			if(visited[i] == 0)
			{
				dfs(i);
				count++;
			}
			if(count > 1)
				break;
		}
		int fleg = 0;
		if(count > 1)
			fleg = 1;

		for(int i=0;i<2*n;i++)
		{
			if(visited[i]==0)
			{
				fleg = 1;
				break;
			}
		}
		if(fleg == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}
	return 0;
}
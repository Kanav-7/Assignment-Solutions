#include "iostream"
#include "stack"
#include "vector"
using namespace std;


vector<long long int> G[1000000],GP[1000000];
stack<long long int> end_time;
int visited[1000000],visited2[1000000];
long long int ans,nov;



// long long int calculate(long long int a,long long int b,long long int mod)
// {	
// 	long long int val=0;
// 	while(b)
// {
// 		if(b&1)
// 			val=(val+a)%mod;
// 		a=(a<<1)%mod;
// 		b=b>>1;
// 	}
// 	return val;
// }


long long int calculate(long long int a,long long int b,long long int mod)
{
	long long int val=0;
	while(b)
	{
		if(b&1)
			val = (val+a)%mod;
		a=(2*a)%mod;
		b/=2;
	}
	return val;
}

void dfs(long long int start)
{
	visited[start] = 1;
	for(auto v: G[start])
	{
		if(visited[v] == 0)
			dfs(v);
	}
	end_time.push(start);
	return;
}

long long int dfsans(long long int start,long long int mod)
{
	nov++;
	if(nov>1)
		ans = calculate(ans, start, mod);
	long long int ans = 1;
	visited2[start] = 1;
	// if(GP[start].size() != 0)
		// ans*= start;
	for(auto v: GP[start])
	{
		if(visited2[v] == 0)
			dfsans(v,mod);
	}
	// printf("%lld\n",ans);
	return ans;
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,m,mod;
		scanf("%lld %lld %lld",&n,&m,&mod);
		for(int i=0;i<m;i++)
		{
			long long int a,b;
			scanf("%lld %lld",&a,&b);
			G[a].push_back(b);
 			GP[b].push_back(a);	
		}
		ans = 1;
		for(int i = 1;i<=n;i++)
		{
			visited[i] = visited2[i] = 0;
		}
		for(int i=1;i<=n;i++)
			if(visited[i] == 0)
				dfs(i);

		while(!end_time.empty())
		{
			// printf("%lld\n",end_time.top());
			// printf("%lld\n",GP[1].size());	
			if(visited2[end_time.top()] == 0)
			{
				nov = 0;
				dfsans(end_time.top(),mod);
				if(nov > 1)
					ans = calculate(ans,end_time.top(),mod);
			}

			end_time.pop();
		}
		for (int i=1;i<= n; i++)
		{
			G[i].clear();
			GP[i].clear();
		}
		// printf("%lld\n",GP[1].size());
		if(ans == 1)
			printf("-1\n");
		else		
			printf("%lld\n",ans);
		// printf("\n");	
	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

long long mod = 1000000007;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long ans=0,i,j,k,a,b,c;
		long long A[10000],B[10000],C[10000];
		cin >> a >> b >> c;
		for(i=0;i<a;i++)
			cin >> A[i];
		for(i=0;i<b;i++)
			cin >> B[i];
		for(i=0;i<c;i++)
			cin >> C[i];

		for(i=0;i<a;i++)
		{
			for(j=0;i<b;j++)
			{
				for(k=0;k<c;k++)
				{
					if((A[i] <= B[j]) && (B[j] >= C[k]))
						ans+= (((A[i] + B[j])%mod)*((B[j] + C[k])%mod))%mod;
				}
			}
		}
		cout << ans;
	}
}
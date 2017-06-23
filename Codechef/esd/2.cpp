#include "bits/stdc++.h"
using namespace std;


long long int a[1000000], leftarr[1000000], rightarr[1000000], answer[1000000];

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long int i,sum=0;

		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			sum+=a[i];
		}

		leftarr[1]=rightarr[n]=1;

		for(i=1;i<n;i++) 
		{
			leftarr[i+1] = min(a[i+1],leftarr[i]+1);
			rightarr[n-i]=min(a[n-i],rightarr[n-i+1]+1);
		}
			
		long long int ans=-1;
		long long int len=0;
		
		for(i=1;i<=n;i++) 
		{
			answer[i]= min(rightarr[i],leftarr[i])*2 - 1;
			len = max(answer[i],len);
		}

		ans = sum - (len/2+1)*(len/2+1);

		printf("%lld\n",ans);
	}
	return 0;
}

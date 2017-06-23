#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,a[1000000],b[1000000],mina = 10000000,smina = 10000000,sminb = 10000000,minb = 10000000,mininda = -1,minindb = -1;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if(a[i] < mina)
		{
			mina = a[i];
			mininda = i;
		}
	}

	for(int i=0;i<n;i++)
	{
		cin >> b[i];
		if(b[i] < minb)
		{
			minb = b[i];
			minindb = i;
		}
	}

	if(mininda != minindb)
	{
		cout << mina + minb << endl;
	}
	else
	{
		sort(a,a+n);
		sort(b,b+n);
		cout << min(a[0]+b[1],a[1]+b[0]) << endl;
	}
	return 0;

}
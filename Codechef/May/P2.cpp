#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int maxi = 0;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin >> a;
			maxi = max(maxi,a); 
		}
		cout << n - maxi << endl;
	}
	return 0;
}
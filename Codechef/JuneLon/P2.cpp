#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long u,v;
		cin >> u >> v;
		long long x = u+v;
		cout << (((x*(x+1))/2) + 1 + u) << endl;
	}
	return 0;
}
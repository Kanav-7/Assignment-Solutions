#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,ans = -1,flag = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if(i+a+1 > n && flag == 0)
		{
			flag = 1;
			ans = i+1;
		}

	}
	cout << ans << endl;
}
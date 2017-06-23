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
		int a[2*n+10];
		for(int i=1;i<=2*n;i++)
			cin >> a[i];
		sort(a + 1,a+2*n+1);
		cout << a[n + (n+1)/2] << endl;
		for(int i = 1;i<=n;i++)
			cout << a[i] << " " << a[n+i] << " ";
		cout << "\n";
	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string a;
		cin >> a;
		int j;
		for(j=1;j<a.length();j++)
		{
			if(a[j] < a[j-1])
			{
				printf("no\n");
				break;
			}
		}
		if(j==a.length())
			printf("yes\n");
	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int count=0,count2=0,n,a[1000000],min=1000000009,max = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if(a[i] > max) max = a[i];
		if(a[i] < min) min = a[i]; 
	}
	for (int i = 0; i < n; ++i)
	{
		if(a[i]== max) count++;
		if(a[i]== min) count2++;
	}
	if(min == max)
		printf("%d\n",n-count);
	else
		printf("%d\n",n-count-count2);
	return 0;
}
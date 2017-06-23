#include "bits/stdc++.h"
using namespace std;

int A[1000000],a[100000];

int d[1001][1001] = {0};

int Max_Palindrome(int start, int end) 
{
	//cout << start << " " << end <<endl;
    if(d[start][end] != 0) 
    {
    	//cout << "d" << start << end << " = " << d[start][end];
        return d[start][end];
    }
    if(start == end)
    {
        d[start][end] = 1;
        //cout << start << "YO";
        return 1;
    }
    else if(start == end-1) 
    {
        d[start][end] = (a[start] == a[end])?2:1;
        return d[start][end];
    }
    else if(a[start] == a[end])
    {
        d[start][end] = max((2 + Max_Palindrome(start+1, end-1)) ,max(Max_Palindrome(start+1, end), Max_Palindrome(start, end-1)));
    }
    else
    {
        d[start][end] = max(Max_Palindrome(start+1, end ), Max_Palindrome(start, end-1));
    }
    return d[start][end];
}

int main()
{

	for (int i = 0; i <= 1000; ++i)
	{
		for (int j= 0; j <= 1000; ++j)
		{
			d[i][j] = 0;
		}
	}
	//cout << d[0][0] << endl;
	int n,k,m;
	cin >> n >> k >> m;
	for (int i = 0; i < n+5; ++i)
	{
		A[i] = i;
	}
	//cout << d[0][0] << endl;
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin >> x >> y;
		while(A[x]!=x)
			x = A[x];

		while(A[y]!=y)
			y = A[y];

		A[max(x,y)] = min(x,y);

	}
	//cout << d[0][0] << endl;
	for(int i=0;i< m ;i++)
	{
		int z;
		cin >> a[i];
		z = a[i];
		//cout << A[z] << endl;
		while(A[z] != z)
			z = A[z];
		a[i] = z;
		//cout << a[i] << " ";
	}
	//cout << d[0][0] << endl;
	cout << Max_Palindrome(0,m-1) << endl;
	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j <m; ++j)
	// 	{
	// 		cout << "d:" << i << j << " = " << d[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	return 0;

}
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char a[100000];
		cin >> a;
		int b = strlen(a),zero = 0,ans = 0,check = 0;

		for(int i=0;i<b;i++)
		{
			if(a[i] == '1' && zero == 1 && check == 1)
			{
				ans++;
				zero = 0;
			}
			else if(a[i] == '1' && check == 0)
			{
				check = 1;
				zero = 0;
			}
			else if(a[i] == '1' && zero == 0 && check == 1)
				zero = 0;

			else if(a[i] == '0')
				zero = 1;

			else 
				check = 0;

		}
		cout << ans << endl;
	}
}
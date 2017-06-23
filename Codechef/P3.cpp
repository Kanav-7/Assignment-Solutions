#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,i,n,flag=0,glag=0,count=0,dount=0;
		char a[3][100005];
		scanf("%d",&n);
		scanf("%s%s",a[0],a[1]);
		for(i=0;i<n;i++)
		{
			if(a[0][i] == '*')
				count++;
			if(a[1][i] == '*')
				dount++;
		}
		if(count && dount)
			ans++;

		for(i=0;i<n;i++)
		{
			if(flag == 1 && glag == 1)
			{
				if(a[0][i] == '*' || a[1][i] == '*')
				{
					flag = glag = 0;
					if(a[0][i] == '*')
						count--;
					if(a[1][i] == '*')
						dount--;
					ans++;
				}
			}
			else if(flag == 1 &&  a[0][i] == '*')
			{
				flag = 0;
				count --;
				ans++;
			}

			else if(glag == 1 &&  a[1][i] == '*')
			{
				glag = 0;
				dount --;
				ans++;
			}

			if(a[0][i] == '*' && count > 1)
				flag = 1;
			if(a[1][i] == '*' && dount > 1)
				glag = 1;

		}
		cout << ans << endl;

	}
	return 0;
}
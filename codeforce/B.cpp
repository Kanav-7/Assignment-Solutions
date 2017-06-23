#include "bits/stdc++.h"

using namespace std;
long long int a[1000000];

int main()
{
	memset(a,-1,sizeof(a));
	long long int i=0,x=2,n,l,r,count=0;
	cin >> n >> l >> r;
	long long int p = log2(n);
	long long int len = pow(2,p+1)-1;
	//cout << len << "\n";
    while(n>1)
    {
    	//cout << n << " ";
 	  	if(n%2 == 0)
    	{
    		//cout << x;
    		long long int w=1;
    		while(((w*len)/x)<len)
    		{
    			//cout << x;
    			if(a[i]==-1)
    				{
    					//cout << x;
    					a[i] = (w*len)/x;
    					i++;
    				}
    			w+=2;
    		}
    	}
    	x*=2;
    	n/=2;
    }
    for(long long int j=0;j<i;j++)
    	{
    		if(a[j] <= r-1 && a[j] >= l-1)
    			count++;
    		//cout << a[j] << "\n";}
    	}
   	long long int ans = r-l-count+1;
   	cout << ans << "\n";
   	return 0;
}
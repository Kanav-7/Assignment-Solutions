#include "bits/stdc++.h"
using namespace std;

char a[1000],b[1000];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int count = 0,total = 0,n,ans=0;
		cin >> n >> a >> b;

		for(int i=0;i<n;i++)
		{	
			if(a[i] == '#' && b[i] == '#')
				total+=2;
			else if (a[i] == '#'|| b[i] == '#')
				total++;
		}	

		//cout << total;
		for(int i=0;i<n;i++)
		{
			if(a[i] == '.' && b[i] == '.')
				continue;
			else if(a[i] == '#' && b[i] == '#')
			{
				count+=2;
				continue;
			}
			int tempa,temp,val=0,fleg=0;
			if(a[i] == '#')
				temp = 1;
			else
				temp = 0;
			count++;
			i++;
			for(i;i<n;i++)
			{
				//cout << i<< "\n";
				if(a[i] == '#' && b[i] == '#')
				{
					val++;
					count+=2;
					continue;
				}
				else if((a[i] == '.' && b[i] == '.') || i==n)
					{
						fleg = 1;
						break;
					}

				else if(a[i] == '#')
					tempa = 1;
				else
					tempa = 0;
				if(!((val%2==0 && temp == tempa )|| (val%2==1 && tempa!=temp)))
					{
						//cout << "yo";
						fleg = 1;
						break;
					}
				count++;	
				temp = tempa;
			//	cout<< temp << endl;
				val = 0; 
				}
			if(fleg == 1)
				break;
		}
		//cout << count << total;
		if(count==total) 
  			cout << "yes" << endl;
    	else
    		cout << "no" << endl;    
	}
	return 0;
}
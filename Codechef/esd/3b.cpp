#include "bits/stdc++.h"
using namespace std;

char arr[1000],brr[1000];
int n;

// int fun(int index)
// {
// 	int k;
// 	for(k=index;k<n;k++)
// 	{
// 		if(arr[k]=='#'&&brr[k]=='#')
// 			continue;
// 		break;
// 	}      
// 	return k;
// }  
int main()
{
	int t,var = 0,vari = 0,i,j,total,count,temp,p;
	cin >> t;
	while(t--)
	{
		cin >> n >> arr >> brr;
		total= count = 0;

		for(int i=0;i<n;i++)
		{	
			if(arr[i] == '#' && brr[i] == '#')
				total+=2;
			else if (arr[i] == '#'|| brr[i] == '#')
				total++;
		}	

		for(j=0;j<n;j++)
		{
			if(arr[j]=='.'&&brr[j]=='.')
				continue;
			else 
				break;
		}
		for(j=j;j<n;j++)
		{
			if(arr[j]=='#'&&brr[j]=='#')
			{
				count+=2;
				continue;
			}
			else 
				break;
		}
		if(arr[j]=='.'&&brr[j]=='.')
		{
			if(count!=total)
				cout << "no\n";
			else
				cout << "yes\n";
			continue;
		}
		if(arr[j]!='#')
			var = 0;
		else
			var = 1;

		while(j<n)
		{
			count++;
			int k;
			for(k=j+1;k<n;k++)
			{
				if(arr[k]=='#'&&brr[k]=='#')
					continue;
				break;
			}   

			count = count + (k-1-j)*2;

			if(k==n)
				break;

			temp=k-j-1;

			if(arr[k]=='.'&&brr[k]=='.')
				break;

			if(arr[k]!='#')
				vari=0;
			else
				vari=1;

			if((vari== var && temp%2==0)||(temp%2==1&&vari!= var))
			{
				j=k;
				var=vari;
			}
			else
				break;
		}

		if(count==total)
			cout << "yes\n";
		else
			cout << "no\n";    
	}
	return 0;
}

#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int size[1000000],minarr[1000000],maxarr[1000000];

int min(int a,int b)
{
	return ((a>b)?b:a);
}

int max(int a,int b)
{
	return ((a<b)?b:a);
}
void initialize()
{
	int i;
	for(i=0;i<1000000;i++)
		minarr[i] = 1000000009;
	return ;
}
int main()
{
	initialize();
	int j=0,i,n,m,count = 0;
	scanf("%d%d",&n,&m);
	int k = sqrt(n);

	for(i=0;i<n;i++)
	{
		if(count == k)
		{
			count = 0;
			j++;
		}
		scanf("%d",&size[i]);
	 		maxarr[j] = max(maxarr[j],size[i]);
	 		minarr[j] = min(minarr[j],size[i]);
	 		count++; 
	}
	//printf("%d\n", j);
	//for(i=0;i<=j;i++)
	//{
	//	printf("%d  %d\n",maxarr[i],minarr[i]);
	//}

	while(m--)
	{
		//printf("%d\n",k );
		int p,ind1,ind2,mx=0,mn=1000000009;
		char a;
		scanf("%s %d %d",&a,&ind1,&ind2);
		//printf("%d %c\n",y,a);
		p = ind1-1;
		//printf("%d\n", p);
		if(a == 't')
		{
			while(p<ind2)
			{
				//printf("%d\n", p);
				if(p%k==0 && (p+k) < ind2)
				{
					mn = min(mn,minarr[p/k]);
					mx = max(mx,maxarr[p/k]);
					p+=k;
				}
				else
				{
					mn = min(mn,size[p]);
					mx = max(mx,size[p]);
					p++;
				}
			}
			//printf("mx%d   mn%d\n", mx,mn);
			if((mx-mn) > (ind2 - ind1+1))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else if(a == 'r')
		{
			//printf("1\n");
			int t;
			int temp = size[p];
			size[p] = ind2;
			if(temp == maxarr[p/k])
			{
				maxarr[p/k] = 0;
				for(t=p/k;t<(p/k+k);t++)
					maxarr[p/k] = max(maxarr[p/k],size[t]);
			}
			else
				maxarr[p/k] = max(maxarr[p/k],size[p]);

			if(temp == minarr[p/k])
			{
				minarr[p/k] = 1000000009;
				for(t=p/k;t<(p/k+k);t++)
					minarr[p/k] = min(minarr[p/k],size[t]);
			}
			else
				minarr[p/k] = min(minarr[p/k],size[p]);
			//printf("2\n");
		}
	}
	return 0;
}

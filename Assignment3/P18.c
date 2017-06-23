#include "stdio.h"

#define scan(x) scanf("%d",&x)
#define print() printf("%d\n",ans)

typedef struct Brackets{
	int index;
	int value;
}bra;

int max(int a,int b)
{
	return ((a>b)?a:b);
}


int main()
{
	int t;
	scan(t);
	while(t--)
	{
		bra arr[1000000];
		int i,n,k,top=0;
		arr[top].index = -1;
		arr[top].value = -1;
		scan(n);
		scan(k);
		int x,ans=0;
		for(i=0;i<n;i++)
		{
			scan(x);
			if(x>0)
			{
				top++;
				arr[top].index = i;
				arr[top].value = x;
			}
			else if(x<0&&arr[top].value!=-x)
			{
				top = 0;
				arr[top].index = i;
				arr[top].value = -1;
			}
			else
			{
				top--;
				if(top==-1)
				{
					top++;
					arr[top].value = -1;
					arr[top].index = i;
				}
				else
				{
					int temp = arr[top].index;
					ans = max(ans,i-temp);
				}
			}
		}
		print();
	}
}
#include "iostream"
#include "algorithm"
using namespace std;


int lower_bond(int A[],int low, int high, int n,int last)
{
	int ans = last;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(A[mid] >= n)
			ans = mid, high = mid-1;
		else
			low = mid + 1;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		int A[n+5];

		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);

		sort(A,A+n);

		for(int i=0;i<q;i++)
		{
			int x;
			scanf("%d",&x);
			int curr = lower_bond(A,0,n-1,x,n);
			int ans = 0 , rem = curr - 1;
			//cout << curr << " ";
			ans = (n - curr);
			//cout << ans << " ";
			while(rem > 0)
			{
				if((x - A[curr-1]) <= rem)
				{
					ans+=1;
					rem-=(x-A[curr-1]+1);
					curr-=1;
				}
				else
					break;
			}
			printf("%d\n",ans);;
		}
	}
}
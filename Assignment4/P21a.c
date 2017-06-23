//Kanav Gupta
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define int long long int
int arr[1000000];
char num[1000000];

int cube(int a)
{
	return a*a*a;
}

void update(int arr[],int l,int r,int find,int curr,int val)
{
	if(l == r){	arr[curr] = val; return;}
	int mid = (l+r)/2;
	if(find <= mid && find >= l) update(arr,l,(l+r)/2,find,2*curr,val);
	else if(find>mid && find <= r) update(arr,(l+r)/2+1,r,find,2*curr+1,val);
	arr[curr] = arr[2*curr]+arr[2*curr+1];
	//if(arr[2*curr] > arr[2*curr+1])
}

int search(int arr[],int l,int r,int curr,int x1,int x2)
{
	if(r < x1 || x2 < l) return 0;
	if(l >= x1 && r <= x2) return arr[curr];
	return search(arr,l,(l+r)/2,2*curr,x1,x2)+search(arr,(l+r)/2+1,r,2*curr+1,x1,x2);
}

int main()
{
	scanf("%s",num);
	int i,l = strlen(num);
	for(i=0;i<l;i++)
		update(arr,1,l,i+1,1,cube(num[i] - '0'));
	//for (int i = 0; i < 4*l; ++i)
	//{
	//	printf("%d\n", arr[i]);
	//}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		if(x == 2)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d   %d\n",search(arr,1,l,1,x1,y1), search(arr,1,l,1,x2,y2));
			if(search(arr,1,l,1,x1,y1) == search(arr,1,l,1,x2,y2) && ((y1-x1) == (y2-x2)))
				printf("YES\n");
			else
				printf("NO\n");
		}
		if(x==1)
		{
			int pos,val;
			scanf("%d%d",&pos,&val);
			update(arr,1,l,pos,1,cube(val));
		}
	}
	return 0;
}

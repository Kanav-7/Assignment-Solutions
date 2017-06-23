#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

char num[1000000];
int count[10][400005];
//[int buck1[10],buck2[10];
void arrAdd(int a)
{
	int i;
	for(i=0;i<10;i++)
		count[i][a] = count[i][2*a] + count[i][2*a+1];
}

void fun(int curr,int val)
{
	int i;
	for(i=0;i<10;i++)
		count[i][curr] = 0;
	count[val][curr] = 1;
}

void fun1(int buck[],int curr)
{
	int i;
	for(i=0;i<10;i++)
		buck[i] += count[i][curr];
}


void update(int l,int r,int find,int curr,int val)
{
	//printf("%d\n", val);
	if(l == r){	fun(curr,val); return;}
	int mid = (l+r)/2;
	if(find <= mid && find >= l){ update(l,mid,find,2*curr,val);}
	if(find>mid && find <= r){ update(mid+1,r,find,2*curr+1,val);}
	arrAdd(curr);
	return;
	//if(arr[2*curr] > arr[2*curr+1])
}

void search(int buck[],int l,int r,int curr,int x1,int x2)
{
	if(r < x1 || x2 < l) return ;
	if(l >= x1 && r <= x2) {fun1(buck,curr); return;}
	search(buck,l,(l+r)/2,2*curr,x1,x2);
	search(buck,(l+r)/2+1,r,2*curr+1,x1,x2);
	return;
}

int main()
{
	scanf("%s",num);
	int i,l = strlen(num);
	for(i=1;i<=l;i++)
		update(1,l,i,1,(num[i-1]- 48));
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int cs;
		scanf("%d",&cs);
		if(cs == 2)
		{
			int j,x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int buck1[10]={0},buck2[10]={0};
			search(buck1,1,l,1,x1,y1);
			search(buck2,1,l,1,x2,y2);
			int flag=1;
			for(j=0;j<10;j++)
			{
				//printf("%d %d\n",buck1[j],buck2[j]);
				if(buck1[j]!=buck2[j])
				{
					//printf("%d %d\n",buck1[j],buck2[j]);
					flag=0;
					break;
				}
			}
			if(flag == 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(cs == 1)
		{
			int pos,val;
			scanf("%d%d",&pos,&val);
			update(1,l,pos,1,val);	
		}

	}
	return 0;
}
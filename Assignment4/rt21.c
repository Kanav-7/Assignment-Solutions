#include <stdio.h>
#include <string.h>

char num[100000];
int count[10][100000];
//[int buck1[10],buck2[10];

void fun(int find,int curr,int val,int key)
{
	if(key == 1)
	{
		count[val][curr]++;
		return;
	}
	//printf("%d\n", num[find-1]);
	count[num[find-1] - '0'][curr]--;
	count[val][curr]++;
	return;
}

void fun1(int buck[],int curr)
{
	int i;
	for(i=0;i<10;i++)
		buck[i] += count[i][curr];
	return;
}


void update(int l,int r,int find,int curr,int val,int key)
{
	//printf("%d\n", val);
	if(l == r){	fun(find,curr,val,key); return;}
	int mid = (l+r)/2;
	if(find <= mid && find >= l){ update(l,mid,find,2*curr,val,key);}
	if(find>mid && find <= r){ update(mid+1,r,find,2*curr+1,val,key);}
	fun(find,curr,val,key);
	return;
	//if(arr[2*curr] > arr[2*curr+1])
}

void search(int buck[],int l,int r,int curr,int x1,int x2)
{
	if(r < x1 || x2 < l) return ;
	if(l >= x1 && r <= x2) {fun1(buck,curr); return;}
	int mid = (l+r)/2;
	if(x2 <= mid && x1 >= l)
		search(buck,l,(l+r)/2,2*curr,x1,x2);
    else if(x1 > mid && x2 <= r)
		search(buck,mid+1,r,2*curr+1,x1,x2);
	else
	{
		search(buck,l,mid,2*curr,x1,mid);
		search(buck,mid+1,r,2*curr+1,mid+1,x2);
		return;
	}
}

int main()
{
	scanf("%s",num);
	int i,l = strlen(num);
	for(i=1;i<=l;i++)
	{
		update(1,l,i,1,(num[i-1]- '0'),1);
	}

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
			if(x1 == x2 && y1 == y2)
			{
				printf("YES\n");
			}
			else if(x1 - y1 != x2 - y2)
			{
				printf("NO\n");
			}
			else
			{
			if(x1 < x2 && y1 >= x2)
			{
				int temp = y1;
				y1 = x2 -1;
				x2 = temp + 1;

			}	
			else if(x2 < x1 && x1 <= y2)
			{
				int temp = y2;
				y2 = x1 -1;
				x1 = temp + 1;
			}
			//sprintf("%d%d%d%d\n",x1,y1,x2,y2);
			int buck1[10]={0},buck2[10]={0};
			search(buck1,1,l,1,x1,y1);
			search(buck2,1,l,1,x2,y2);
			int flag=1;
			for(j=0;j<10;j++)
			{
				if(buck1[j]!=buck2[j])
				{
					flag=0;
					break;
				}
			}
			if(flag == 1)
				printf("YES\n");
			else
				printf("NO\n");
			}
		}
		else if(cs == 1)
		{
			int pos,val;
			scanf("%d%d",&pos,&val);
			update(1,l,pos,1,val,0);
			num[pos-1] = val + 48;	
		}
	}
	return 0;
}

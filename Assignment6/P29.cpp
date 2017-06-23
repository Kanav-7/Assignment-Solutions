#include "iostream"
#include "math.h"
#include "string.h"
using namespace std;

typedef struct node{
	long long int data;
	struct node* link;
}nd;

nd head[1000000];
long long int val[1000000],dp[2][1000000];

void initialize()
{
	int i;
	for(i=0;i<=1000000;i++)
	{
		head[i].link = NULL;
	}
	return;
}

void addNode(int v,int u)
{	
	nd* temp=(nd*)malloc(sizeof(nd));					
	temp->data=u;
	temp->link = head[v].link;
	head[v].link=temp;
	return ;
}

void check(int start,int parent)
{
	long long int sumA = 0, sumB = 0;
	nd* temp=(nd*)malloc(sizeof(nd));
	temp = head[start].link;
	while(temp!=NULL)
	{
		if(temp->data == parent)			
		{
			temp = temp->link;
			continue;
		}
		check(temp->data,start);
		sumA = sumA + dp[1][temp->data];
    	sumB = sumB + max(dp[1][temp->data],dp[0][temp->data]);
		temp = temp->link;
	}
	dp[0][start] = val[start] + sumA;
    dp[1][start] = sumB;
	return ;
}

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	initialize();
	long long int i,m;

	cin >> m;

	for(i=1;i<=m;i++)
		scanf("%lld",&val[i]);
	m = m-1;
	while(m--)
	{
		long long int a,b;	
		cin >> a >> b;
		addNode(a,b);
		addNode(b,a);
	}

	check(1,0);

	cout << max(dp[1][1],dp[0][1]) << endl;

	return 0;
}	
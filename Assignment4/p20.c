#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int data;
	struct node* link;
}nd;


nd head[1000000];
int colour[1000000],flag=1;

void initialize()
{
	int i;
	for(i=1;i<=1000000;i++)
	{
		head[i].link = NULL;
		colour[i] = 2;
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

void check(nd start,int col)
{
	nd* temp=(nd*)malloc(sizeof(nd));
	temp = start.link;
	while(temp!=NULL)
	{
		if(colour[temp->data]==2)	
		{
			colour[temp->data] = col;
			check(head[temp->data],(col+1)%2);
		}
		else
		{
			if(colour[temp->data] != col)
			{
				flag = 0;	
				return;
			}		
		}
		temp = temp->link;
	}
	return ;
}

int main()
{
	initialize();
	int i,m,n;
	scanf("%d%d",&m,&n);
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addNode(a,b);
	}

	colour[1] = 0;
	check(head[1],1);
	
	if(flag == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}	


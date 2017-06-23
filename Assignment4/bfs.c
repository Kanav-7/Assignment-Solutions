#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int val;
	struct node* link;
}nd;

nd headPt[1000000];
int dist[1000000],Q[1000000],visit[1000000],head=0,tail=0;

void addNode(int v,int u)
{
	nd* temp = (nd*)malloc(sizeof(nd));
	temp->val =  u;
	temp->link = headPt[v].link;
	headPt[v].link = temp;
	return;
}

void initialize()
{
	for(int i=0;i<1000000;i++)
		headPt[i].link = NULL;
}
void bfs(int start)
{
	Q[head++] = start;
	visit[start] = 1;
	printf("%d\n",Q[tail]);
	while(tail <	 head)
	{
		nd* temp = headPt[Q[tail]].link;
		while(temp!=NULL)
		{
			if(visit[temp->val] == 0)
			{
				//printf("%d\n", temp->val);
				Q[head++] = temp->val;
				visit[temp->val] = 1;
			}
			temp = temp->link;
		}
		//printf("%d    %d\n",tail,Q[tail]);
		printf("%d   %d\n",Q[tail],tail);
		visit[Q[tail]] = 2;
		tail++;
	}
}


int main()
{
	addNode(1,2);
	addNode(2,3);
	addNode(3,7);
	addNode(7,5);
	addNode(8,7);
	addNode(3,8);
	addNode(5,8);
	bfs(1);
	return 0;
}


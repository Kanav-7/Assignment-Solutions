#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
	int val;
	struct node* right;
	struct node* left;
}nd;

nd* head = NULL;

void insert(int value)
{
	nd* temp = (nd*)malloc(sizeof(nd));
	temp = head;
	nd* temp1 = (nd*)malloc(sizeof(nd));
	temp1->val = value;
	temp1->left = NULL;
	temp1->right = NULL;
	if(head == NULL)
	{
		head = temp1;
		return;
	}

	while(1)
	{
		if(value > temp->val)
		{
			if(temp->right == NULL)
			{
				temp->right = temp1;
				break;
			}
			temp = temp->right;
		}
		else
		{
			if(temp->left == NULL)
			{
				temp->left = temp1;
				break;
			}
			temp = temp->left;
		}
	}
	return;
}

int search(int value)
{
	nd* temp = (nd*)malloc(sizeof(nd));
	temp = head;
	if(head == NULL)
		return 0;
	while(1)
	{
		if(value == temp->val) return 1;
		if(value > temp->val)
		{
			if(temp->right == NULL)
				return 0;
			temp = temp->right;
		}
		else
		{
			if(temp->left == NULL)
				return 0;
			temp = temp->left;
		}
	}
	return;
}


int Recsearch(nd* temp,int val)
{
	if(temp==NULL) return 0;
	if(val == temp->val) return 1;
	if(val > temp->val) return Recsearch(temp->right,val);
	if(val < temp->val) return Recsearch(temp->left,val); 
}

void display(nd* temp)
{
	if(temp == NULL)
		return;
	display(temp->left);
	printf("%d\n",temp->val);
	display(temp->right);
	return ;
}

int getMax(nd* temp)
{
	while(temp->right!=NULL)
		temp = temp->right;
	return temp->val;
	free(temp);
}

int getMin(nd* temp)
{
	while(temp->left!=NULL)
		temp = temp->left;
	return temp->val;
	free(temp);
}

void delete(nd* temp)
{
	if(temp->right==NULL&&temp->left==NULL)
		free(temp);
	else if(temp->right==NULL)
		temp = temp->left;
	else if(temp->left==NULL)
		temp = temp->right;
	else
	{
		node suc* = getMin(temp->right);
		temp->val = suc->val;
		free(suc);
	}
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		insert(t);
		printf("%d %d\n",getMin(),getMax());
	}
	return 0;
}



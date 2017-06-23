#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
}node;

//inserts an element in the linked list

node *insertT(int val,node* tail,node **head)
{
	if(*head == NULL)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->val = val;
		temp->next = temp->prev = NULL;
		*head = temp;
		tail = temp;
		return tail;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->val = val;
	temp->next = NULL;
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	return tail;
}
node *insert(int val, node *head, node **tail)
{
	//either list is empty or I reached the end
	if(head == NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->val = val;
		head->next = head->prev = NULL;
		*tail = head;
		return head;
	}
	head->next = insert(val, head->next, tail);
	head->next->prev = head;
	return head;
}

void print(node *head)
{
	while(head) 
	{
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}

int main()
{
	int n;
	scanf("%d", &n);
	node *head = NULL, *tail = NULL;
	// head = insert(1,head,&tail);
	//head = insert(5,head,&tail);
	//print(head);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		tail = insertT(x,tail,&head);
		print(head);
	}
	return 0;
}

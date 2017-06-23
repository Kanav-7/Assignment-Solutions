#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}nd;
nd* head=NULL;

void insert(int val,int pos)    //Inserting a node at nth position in Linked List

{	
//	printf("check\n");
	int i;
	nd* temp1=(nd*)malloc(sizeof(nd));
	nd* temp=(nd*)malloc(sizeof(nd));
//	printf("check\n");
	temp->data=val;
//	printf("check\n");
	temp1=head;
//	printf("check\n");
	if(pos==1)
	{
//	printf("check\n");
		temp->link=head;
		head=temp;
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp1=temp1->link;
		}
		temp->link=temp1->link;
		temp1->link=temp;
	}
	return ;
}
void print()       //Printong elements of Linked List using Iterition   
{
	nd* temp1=(nd*)malloc(sizeof(nd));
	temp1=head;
	if(temp1==NULL)
		return;
	else
	{
		while(temp1!=NULL)
		{	printf("%d   ",temp1->data);
			temp1=temp1->link;}

	}

	printf("\n");
	return ;
}

void rprint(nd* p)      //Printing elements of Linked List using recurrsion
{
	if(p==NULL)
	{
		printf("\n");
		return ;
	}
	printf("%d   ",p->data);
		rprint(p->link);
}
void rrevprint(nd* p)       //Printing elements of Linked List in reverse order using recurrsion
{
	if(p==NULL)
	return ;
	rrevprint(p->link);
	printf("%d   ",p->data);
	if(p==head)
		printf("\n");
}

void delete(int pos)        //Deleting Node at any particular position
{
	int i;
	nd* temp1=(nd*)malloc(sizeof(nd));
	nd* temp=(nd*)malloc(sizeof(nd));
	temp1=head;
	if(pos==1)
	{
		temp=head->link;
		head->link=temp->link;
		free(temp);
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp1=temp1->link;
		}
		temp=temp1->link;
		temp1->link=temp->link;
		free(temp);
	}
	return ;
}

void reverse()         //Reversing the Linked List
{

	nd* temp1=(nd*)malloc(sizeof(nd));
	nd* prev=(nd*)malloc(sizeof(nd));
	nd* next=(nd*)malloc(sizeof(nd));
	temp1=head;
	prev=NULL;
	while(temp1!=NULL)
	{
		next=temp1->link;
		temp1->link=prev;
		prev=temp1;
		temp1=next;
	}
	head=prev;

}
void sort()        //Sorting Linked Lst by Bubble Sort (swapping data)
{


	nd* temp1=(nd*)malloc(sizeof(nd));
	nd* temp=(nd*)malloc(sizeof(nd));
	int swap;
	temp=head;
	temp1=temp->link;
	while(temp->link!=NULL)
	{
		while(temp1!=NULL)
		{
			if(temp->data>temp1->data)
			{
				swap=temp->data;
				temp->data=temp1->data;
				temp1->data=swap;
			}
			temp1=temp1->link;
		}
		temp=temp->link;
		temp1=temp->link;

	}
	return ;
}




int main()          // Main Function
{
	insert(3,1);
	insert(2,2);
	insert(6,3);
	print();
	rprint(head);
	rrevprint(head);
	sort();
	print();
	reverse();
	print();
	
	return 0;
}

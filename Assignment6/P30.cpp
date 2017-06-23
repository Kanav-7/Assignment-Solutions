#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	long long int val;
	struct node *next;
}node;
typedef long long int lli;
lli count2=0;
lli sum=-1;
lli answer=1;
lli inside=0,count1=0,st[400009],visited1[500009],mod,visited[500009]={0},finished[500009],t=0,prod=1,test,n,i,x,y,l;
node *head[500009],*h[500009];
lli time1[1000009]={0};
lli multiply(lli a,lli b)
{	
	lli ans=0;
	while(b)
{
		count2++;
		if(b&1)
			ans=(ans+a)%mod;
		a=(a<<1)%mod;
		b=b>>1;
	}
	return ans;
}
void insert(lli k,lli l)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=l;
	if(h[k]==NULL)
		h[k]=temp;
	else
	{
		temp->next=h[k];
		h[k]=temp;
	}
	return;
}
void push(lli k)
{
	st[count1++]=k;
	return;
}
lli pop()
{
	return st[--count1];
}
void make(lli k,lli l)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=l;
	if(head[k]==NULL)
		head[k]=temp;
	else
	{
		temp->next=head[k];
		head[k]=temp;
	}
	return;
}
void DFS(lli k)
{
	if(!visited1[k])
		answer=multiply(answer,k);
	visited1[k]=1;
	inside++;
	node *temp=h[k];
	while(temp){
		lli k=temp->val;
		if(!visited1[k]){
			DFS(k);
		}
		temp=temp->next;
	}
	visited1[k]=2;
	return;
}
void makeDFS(lli k){
	visited[k]=1;
	node *temp=head[k];
	t++;
	while(temp){
		lli k=temp->val;
		if(!visited[k]){
			makeDFS(k);
			t++;
		}
		temp=temp->next;
	}
	visited[k]=2;
	finished[k]=t;
	push(k);
	return;
}
int main(){
	cin>>test;
	while(test--){
		scanf("%lld%lld%lld",&n,&l,&mod);
		for(i=0;i<l;i++){
			scanf("%lld%lld",&x,&y);
			make(x,y);
			insert(y,x);
		}
		for(i=1;i<=n;i++)
			if(!visited[i])makeDFS(i);
		for(i=count1-1;i>=0;i--){
			lli h=st[i];
			if(!visited1[h]){
				answer=1,inside=-1;
				DFS(h);
				if(inside>0)sum=multiply(sum,answer);
			}
		}
		if(sum+1){
			printf("%lld\n",-sum);
		}
		else{
			printf("-1\n");
		}
		prod=1;
		count1=0;
		count2=0;
		sum=inside=-1;
		for(i=1;i<=n;i++)time1[i]=visited1[i]=t=visited[i]=0,head[i]=h[i]=NULL;
	}
	return 0;
}

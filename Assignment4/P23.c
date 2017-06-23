#include "stdio.h"
#include "string.h"
#include "stdlib.h"

long long int power[100010],ans[100010],ansr[100010];

void hash(char str[],long long int p,long long int q,long long int ans1[],long long int len)
{
	long long int i;
	ans1[0] = str[0];
	power[0] = 1;
	for(i=1;i<len;i++)
	{
		power[i] = (power[i-1]*p)%q;
		ans1[i] = (ans1[i-1] + (str[i]*power[i])%q)%q;
	}
	return;
}

void hashr(char str[],long long int p,long long int q,long long int ans2[],long long int len)
{
	long long int i;
	ans2[len-1] = (long long int )str[len-1];
	for(i=1;i<len;i++)
		ans2[len-1-i] = (ans2[len-i] + ((long long int)str[len-i-1]*power[i])%q)%q;
	return;
}

long long int range(long long int ans1[],long long int l,long long int r,long long int p,long long int q)
{

	long long int value;
	if(l==0)
		value = ans1[r]%q;
	else value = (ans1[r] - ans1[l-1] + q)%q;
	long long int temp = 1,x = power[l];
	long long int b = q-2;
	while(b)
	{
		if(b&1) temp = (temp*x)%q;
		x = (x*x)%q;
		b = b/2;
	}
	long long int ret = (temp*value)%q;
	return ret;
}

long long int ranger(long long int ans[],long long int l,long long int r,long long int p,long long int q,long long int len)
{
	long long int value;
	if(r==len-1)
		value = ans[l]%q;
	else value = (ans[l] - ans[r+1] + q)%q;
	long long int temp = 1,x = power[len-r-1];
	long long int b = q-2;
	while(b)
	{
		if(b&1) temp = (temp*x)%q;
		x = (x*x)%q;
		 b = b/2; 
	}
	long long int ret = (temp*value)%q;
	return ret;
}

int main()
{
	long long int len,quer,p=37,q=1000000009;
	scanf("%lld%lld",&len,&quer);
	char str[1000010];
	scanf("%s",str);
	hash(str,p,q,ans,len);
	hashr(str,p,q,ansr,len);
	//for(int i=0;i<len;i++)
	//		printf("%d	%d	%d\n",ans[i],ansr[i],power[i]);
	while(quer--)
	{
		int var;
		scanf("%d",&var);
		long long int final = 0,finalr=0,pw=0;
		while(var--)
		{
			long long int l,r;
			scanf("%lld%lld",&l,&r);
			//final = (final*power[r-l+1] + range(ans,l-1,r-1,p,q))%q;
			//printf("%lld\n",ranger(ansr,l-1,r-1,p,q,len));
			final = (final + ((range(ans,l-1,r-1,p,q)%q)*power[pw])%q)%q;
			finalr = ((finalr*power[r-l+1])%q + ranger(ansr,l-1,r-1,p,q,len))%q;
			//printf("%lldF %lldFR\n",final,finalr);
			pw += r - l + 1;
		}

		if(final == finalr)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

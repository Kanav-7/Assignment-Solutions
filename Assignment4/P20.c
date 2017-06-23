#include "stdio.h"
#include "math.h"
#include "string.h"

char num[1000000],bucket[11][100005];
int main()
{
	scanf("%s",num);
	//printf("%s\n", num);
	int i,j=0,count=0,n = strlen(num);
	int k = sqrt(n);

	for(i=0;i<n;i++)
	{
		if(count == k)
		{
			count = 0;
			j++;
		}
	 	bucket[num[i]-'0'][j]++;
	 	count++; 
	}

	int q;
	scanf("%d",&q);
	//printf("%s\n", num);
	while(q--)
	{
		int a;
		scanf("%d",&a);
		if(a==2)
		{
			int x1,x2,y1,y2;
			int buck1[11] = {0},buck2[11]={0};
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int p = x1-1;
			while(p<y1)
			{
				if(p%k==0 && (p+k) < y1)
				{
					int t;
					for (t = 0; t < 11; t++)
						buck1[t] += bucket[t][p/k];
					p+=k;
				}
				else
				{
					buck1[num[p]-'0']++;
					p++;
				}
			}

			p = x2-1;
			while(p<y2)
			{
				//printf("%s\n", num);
				if(p%k==0 && (p+k) < y2)
				{
					int t;
					for (t = 0; t < 11; t++){
						buck2[t] += bucket[t][p/k];
					}
					p+=k;
				}
				else
				{
					buck2[num[p]-'0']++;
					p++;
				}
			}
			int t,flag=0;
			for(t=0;t<11;t++)
			{
				if(buck1[t]!=buck2[t])
				{
					flag = 1;
					break;
				}
			}
			if(flag==0)
				printf("YES\n");
			else
				printf("NO\n");
		}

		else if(a==1)
		{
			//printf("AA%s\n", num);
			int pos;
			int ch;
			//printf("Epos\n");
			scanf("%d",&pos);
			//printf("%d\n",pos);
			scanf("%d",&ch);
			//printf("pos%d\n", pos);
			pos--;
			//printf("%s\n", num);
			//char temp = num[pos];
			//printf("%sA%d\n",num,pos);
			bucket[num[pos]-'0'][pos/k]--;
			num[pos] = ch + '0';
			bucket[ch][pos/k]++;
			//printf("%s\n", num); 
		}
	}
	return 0;
}
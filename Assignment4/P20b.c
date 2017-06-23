#include "stdio.h"
#include "math.h"
#include "string.h"

char num[1000000],bucket[11][100005];
int main()
{
	scanf("%s",num);
	//printf("%s\n", num);
	int x,i,j=0,count=0,n = strlen(num);
	int k = sqrt(n);

	for(i=0;i<n;i++)
	{
		if(count == k)
		{
			count = 0;
			j++;
			for(x=0;x<11;x++)
			{
				bucket[x][j] = bucket[x][j-1];
			}
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
			
			x1--;
			while(x1%k!=0)
			{
				buck1[num[x1] - '0']++;
				x1++;
			}

			y1--;
			while(y1%k!=0)
			{
				buck1[num[y1] - '0']++;
				y1--;
			}
			buck1[num[y1] - '0']++;
			y1--;
			x1/=k;
			y1/=k;
			int w;				
			for(w=0;w<11;w++)
				buck1[w] += bucket[w][y1] - bucket[w][x1];
			

			x2--;
			while(x2%k!=0)
			{
				buck2[num[x2] - '0']++;
				x2++;
			}

			y2--;
			while(y2%k!=0)
			{
				buck2[num[y2] - '0']++;
				y2--;
			}
			buck2[num[y2] - '0']++;
			y2--;
			x2/=k;
			y2/=k;
							
			for(w=0;w<11;w++)
				buck2[w] += bucket[w][y2] - bucket[w][x2];
			
			int t,flag=0;
			for(t=0;t<11;t++)
			{
				printf("%d %d\n", buck1[t],buck2[t]);
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
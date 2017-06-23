#include "stdio.h"

int min(int a,int b)
{
	return ((a>b)?b:a);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,a,b,c;
		scanf("%d",&a);
		int A[a+5],sumA=0;
		for(i=0;i<a;i++)
			{
				scanf("%d",&A[i]);
				sumA+=A[i];
			}
		scanf("%d",&b);
		int B[b+5],sumB=0;
		for(i=0;i<b;i++)
		{
			scanf("%d",&B[i]);
			sumB+=B[i];
		}

		scanf("%d",&c);
		int C[c+5],sumC=0;
		for(i=0;i<c;i++)
		{
			scanf("%d",&C[i]);
			sumC+=C[i];
		}
			
		while((a>0&&b>0&&c>0)&&(sumA!=sumB||sumB!=sumC||sumC!=sumA))
		{
		    
		    if(sumA>=sumB&&sumA>=sumC)
		    {
		 		sumA-=A[a-1];
		 		a--;			 	
			}
			else if(sumB>=sumA&&sumB>=sumC)
		    {
		 		sumB-=B[b-1];
		 		b--;			 	
			}
			else if(sumC>=sumB&&sumC>=sumB)
		    {
		 		sumC-=C[c-1];
		 		c--;		 	
			}
		}
			printf("%d\n",min(sumA,min(sumB,sumC)));
	}
		return 0;		
}

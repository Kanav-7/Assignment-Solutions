#include "stdio.h"

long long int r1=0,r2=0,r3=0,f1=0,f2=0,f3=0,A[1000000],B[1000000],C[1000000];

long long int min(long long int a,long long int b)
{
	return ((a>b)?b:a);
}	

int main()
{
	long long int n,count=0;
	scanf("%lld",&n);
	A[0]=3;
	B[0]=5;
	C[0]=7;
	if(n==1)
		printf("1");
	else
	{
		while(count < n-2)
		{
		  
			  long long int mn = min(A[f1],min(B[f2],C[f3]));
          
         	if(A[f1] == mn)
          	{
          		long long int q = A[f1];
          		f1++;
          		r1++;
          		A[r1]=3*q;
          		r2++;
          		B[r2]=5*q;
          		r3++;
          		C[r3]=7*q;
          	}
          	else if(B[f2] == mn)
          	{
          		long long int q = B[f2];
          		f2++;
           		r2++;
          		B[r2]=5*q;
          		r3++;
          		C[r3]=7*q;
          	}
          	else if(C[f3] == mn)
          	{
          		long long int q = C[f3];
          		f3++;
          		r3++;
          		C[r3]=7*q;
          	}
         	count ++;
        }	
        long long int mn =  min(A[f1],min(B[f2],C[f3]));
	printf("%lld",mn);
	}
	return 0; 	
}
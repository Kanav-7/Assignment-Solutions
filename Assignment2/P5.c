#include <stdio.h>
#include <math.h>

#define print() printf("%lld\n",area%1000000009)
#define scan() scanf("%lld",&n)
#define scpqr() scanf("%lld%lld%lld",&p,&q,&r)

long long int ArrH[1000000],ArrX[1000000],Arr2H[1000000],Arr2X[1000000],Height[1000000],XCord[1000000],i,j,h1,h2,div_1,div_2,n,area=0,r,p,q;

long long int PointMerge(long long int left,long long int mid,long long int right) 
{

    div_1 = mid-left+1;
    div_2 = right-mid;
    for(i=0;i<div_1;i++)
    {
        ArrX[i]=XCord[left+i];
        ArrH[i]=Height[left+i];
    }
    for(i=0;i<div_2;i++)  
    {
        Arr2H[i]=Height[mid+i+1];
        Arr2X[i]=XCord[mid+i+1];
    }
    h1=0;
    h2=0;
    i=0;
    j=0;
    while(1) 
    {
        if(i>=div_1 || j>=div_2) 
            break;   
        if(ArrX[i]>=Arr2X[j]) 
	    { 
            h2 = Arr2H[j];
            Height[left]= ((h1>h2)?h1:h2);
            XCord[left]=Arr2X[j];
            j++;    
        }
        else 
        {  
            h1=ArrH[i];
            Height[left] = ((h1>h2)?h1:h2);
            XCord[left]=ArrX[i];
            i++;  
        }
        left++;
    }
    while(i<div_1) 
    {
         XCord[left]=ArrX[i];
         Height[left]=ArrH[i];
         left++;
         i++;
    }

    while(j<div_2)
    {
         XCord[left]=Arr2X[j];
         Height [left]=Arr2H[j];
         left++;
         j++;
    }
    return 0;         
}
long long int PointMain(long long int left,long long int right) 
{
    if (right-left > 1)
    {
        long long int mid;
        mid = left + (right-left)/2 - (((right-left+1)/2)%2);
        PointMain(left,mid);
        PointMain(mid+1,right);
        PointMerge(left,mid,right);
        return 0;
    }
    return 0;
}

void findarea()
{
    i=1;
    while(i<2*n+1)
    {
         area+=(abs(XCord[i]-XCord[i-1]))*Height[i-1];
         i++;
    }
    return;
}
int  main() 
{  
    scan();
    for(i=0; i<=n-1; i++) 
    {
        scpqr();
        Height[2*i]= p;
        Height[2*i+1]= 0;
        XCord[2*i]=q;
        XCord[2*i+1]=r;
    }
    PointMain(0,2*n-1);
    findarea();
    print();
    return 0;
}

#include <stdio.h>

main()

{

int n;

printf("Enter the no. of processes: ");

scanf("%d",&n);

int id[n],bt[n],rt[n],wt[n],tat[n],st[n],ft[n],q,i,time=0,btsum=0;

for(i=0;i<n;i++)

{

printf("Enter process %d id: ",i+1);

scanf("%d",&id[i]);

printf("Enter process %d burst time: ",i+1);

scanf("%d",&bt[i]);

rt[i]=bt[i];

btsum=btsum+bt[i];

wt[i]=0;

ft[i]=0;

}

printf("Enter q: ");

scanf("%d",&q);

for(i=0;time!=btsum;)

{

i=(i+1)%n;

st[i]=time;

if(bt[i]>q)

{

time+=q;

bt[i]-=q;

wt[i]=wt[i]+st[i]-ft[i];

ft[i]=time;

}

else if(bt[i]<=q && bt[i]!=0)

{

time+=bt[i];

wt[i]=wt[i]+st[i]-ft[i];

bt[i]=0;

}

}

for(i=0;i<n;i++)

{

tat[i]=wt[i]+rt[i];

}

float avwt=0,avtat=0;

printf("Process\tBT\tWT\tTAT\n");

for(i=0;i<n;i++)

{

printf("%d\t%d\t%d\t%d\n",id[i],rt[i],wt[i],tat[i]);

avwt=avwt+wt[i];

avtat=avtat+tat[i];

}

avwt=avwt/n;

avtat=avtat/n;

printf("Average Waiting Time: %f\n",avwt);

printf("\nAverage Turnaround Time: %f",avtat);

}
#include<stdio.h>
 int main()
{
int p[20],bt[20],pri[20], wt[20],tat[20],i, j, n, temp;
float wtavg, tatavg;
printf("Enter the number of processes -");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i] = i;
printf("Enter the Burst Time & Priority of Process %d - ",i);
scanf("%d %d",&bt[i], &pri[i]);
}
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(pri[i] >pri[j])
{
    // pids swap
temp=p[i];
p[i]=p[j];
p[j]=temp;
// burst time swap
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
// priority swap
temp=pri[i];
pri[i]=pri[j];
pri[j]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is - %f",wtavg/n);
printf("\nAverage Turnaround Time is - %f",tatavg/n); }

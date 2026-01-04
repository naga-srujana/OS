#include <stdio.h>

int main()
{
    int n,nm,p,x=0,y=1,t=300,of,i;
    printf("Enter the memory size:\n");
    scanf("%d",&nm);
    printf("Enter the no.of segments:\n");
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++)
    {
        printf("enter the segment size of %d:",i+1);
        scanf("%d",&s[i]);
        x+=s[i];
        if(x>nm)
        {
            printf("memory full segment %d is not allocated",i+1);
            x-=s[i];
            s[i]=0;
        }
    }
    printf("-----OPERATIONS------");
    while(y==1)
    {
        printf("enter the no.of operations:\n");
        scanf("%d",&p);
        printf("enter the offset:");
        scanf("%d",&of);
        if(s[p-1]==0)
        {
            printf("segment is not allocated\n");
        }
        else if(of>s[p-1])
        {
            printf("out of range!..");
        }
        else
        {
            printf("the segment %d the physical address is ranged from %d to %d\n the address of operation is\n",p,t,t+s[p-1],t+of);
        }
        printf("press 1 to continue");
        scanf("%d",&y);
    }
}

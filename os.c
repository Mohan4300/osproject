#include<stdio.h>
#include<conio.h>
void main()
{
    int bursttime[20],process[20],waitingtime[20],totalturnaroundtime[20],i,j,n,total=0,position,temp;
    float averagewaitingtime,averagetotalturnaroundtime;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("process%d:",i+1);
        scanf("%d",&bursttime[i]);
        process[i]=i+1;           
    }
 
    
    for(i=0;i<n;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(bursttime[j]<bursttime[position])
                position=j;
        }
 
        temp=bursttime[i];
        bursttime[i]=bursttime[position];
        bursttime[position]=temp;
 
        temp=process[i];
        process[i]=process[position];
        process[position]=temp;
    }
 
    waitingtime[0]=0;            
 
    //calculating the waiting time
    for(i=1;i<n;i++)
    {
        waitingtime[i]=0;
        for(j=0;j<i;j++)
            waitingtime[i]+=bursttime[j];
 
        total+=waitingtime[i];
    }
 
    averagewaitingtime=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        totalturnaroundtime[i]=bursttime[i]+waitingtime[i];     //calculate turnaround time
        total+=totalturnaroundtime[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],bursttime[i],waitingtime[i],totalturnaroundtime[i]);
    }
 
    averagetotalturnaroundtime=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",averagewaitingtime);
    printf("\nAverage Turnaround Time=%f\n",averagetotalturnaroundtime);
}

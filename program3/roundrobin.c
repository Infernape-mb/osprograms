//Round Robin algorithm
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

 double SumTurnAroundTime=0;
 double SumWaitingTime=0;
 double SumResponseTime=0;
 double totalbursttime=0;
  int  currenttime=0;
  
struct Process
{
    int PID;
    int ArrivalTime;
    int BurstTime;
     int StartTime;
     int CompletionTime;
     int TurnAroundTime;
   int WaitingTime;
    int ResponseTime;
    int burstrem;
};
  
   void sort(struct Process p[],int n)
      {
        struct Process temp;
        for(int i=0;i<n;i++)
         {
          for(int j=0;j<n-i-1;j++)
           {
            if(p[j].ArrivalTime>=p[j+1].ArrivalTime)
             {
             if(p[j].ArrivalTime==p[j+1].ArrivalTime && p[j].PID<p[j+1].PID)
             {
             //do nothing
             }
             else{
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;
                 }
             }
           }
         }
      }
           
  void sjffun(struct Process p[],int n,bool iscompleted[],int quanta)
  {
    sort(p,n);
    int i=0;
   while(totalbursttime>0)
    {
   
      //int flag=0;
     
      if(p[i].ArrivalTime<=currenttime&&iscompleted[i]==false)
      {
       if(p[i].StartTime<0)
        p[i].StartTime=currenttime;
      if(p[i].BurstTime>=quanta)
      {
       p[i].BurstTime-=quanta;
       totalbursttime-=quanta;
       currenttime+=quanta;
       }
       else{
       totalbursttime-=p[i].BurstTime;
       currenttime+=p[i].BurstTime;
       p[i].BurstTime=0;
       }
       
      if(p[i].BurstTime==0)
       {
        p[i].CompletionTime=currenttime;
        iscompleted[i]=true;
       }
       
        printf("|P%d(%d)",p[i].PID,currenttime);
        //flag=1;
      
     }
    //if(flag==0)
      //currenttime++;
         i=(i+1)%n; 
     }
   }
      
void ProcessDetails(struct Process P[],int n, bool IsCompleted[])
{
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Process-ID: "); scanf("%d",&P[i].PID);
        //printf("\nEnter process priority");scanf("%d",&P[i].priority);
        printf("Enter Arrival Time: "); scanf("%d",&P[i].ArrivalTime);
        printf("Enter CPU Burst Time: "); scanf("%d",&P[i].BurstTime);
        P[i].burstrem=P[i].BurstTime;
        P[i].StartTime=-1;
        IsCompleted[i] = false;
        totalbursttime+=P[i].BurstTime;
        
    }
}
    void update(struct Process P[],int n)
     {
     for( int i=0;i<n;i++){
      
      P[i].TurnAroundTime = P[i].CompletionTime - P[i].ArrivalTime;
      P[i].WaitingTime = P[i].TurnAroundTime - P[i].burstrem;
      P[i].ResponseTime = P[i].StartTime - P[i].ArrivalTime;       
      SumTurnAroundTime += P[i].TurnAroundTime;
      SumWaitingTime += P[i].WaitingTime;
      SumResponseTime += P[i].ResponseTime;
      //Completed++;
      //IsCompleted[i] = true;
     }
     }


void Display(struct Process P[],int n)
{
   struct Process temp;
    for(int i = 0; i < n; i++)
    {
     for(int j=0;j<n-i-1;j++)
     {
       if(P[j].PID>P[j+1].PID)
        {
         temp=P[j];
         P[j]=P[j+1];
         P[j+1]=temp;
         }
         }
       
    }
    printf("\nProcess ID\tArrival Time\tCPU Burst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n");
    for(int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",P[i].PID, P[i].ArrivalTime, P[i].burstrem, P[i].CompletionTime, P[i].TurnAroundTime, P[i].WaitingTime, P[i].ResponseTime);
    printf("\nAverage Turn Around time = %.2f ms",SumTurnAroundTime / n);
    printf("\nAverage Waiting Time = %.2f ms",SumWaitingTime / n);
    printf("\nAverage Response Time = %.2f ms",SumResponseTime / n);
  }


  int main()
   {
    int n,quanta;
    printf("Enter total number of processes: ");    scanf("%d",&n);
    printf("\nEnter time quanta");
     scanf("%d",&quanta);
    struct Process P[n];
    bool IsCompleted[n];
    //int burstrem[];
    
   ProcessDetails(P,n,IsCompleted);
    printf("\nGantt Chart: \n\n");
    sjffun(P,n,IsCompleted,quanta);
    update(P,n);
    
    printf("|\n\n");
    Display(P,n);
    return 0;
    }

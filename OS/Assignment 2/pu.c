#include<stdio.h>
#include<stdlib.h>

typedef struct Process{
    int pid;
    int atime;
    int btime;
    int wtime;
    int ttime;
}Process;

void sjf(){
    
    int n,i,j;
    
    printf("Enter the num of Process: ");
    scanf("%d",&n);
    
    Process *p = (Process *)malloc(n*sizeof(Process));
    
    for(i=0;i<n;i++)
    {
        p[i].pid = i+1;
        
        printf("Enter the atime for %d Process: ",i+1);
        scanf("%d",&p[i].atime);
        
        printf("Enter the btime for %d Process: ",i+1);
        scanf("%d",&p[i].btime);
    }
  //Sorting Priority wise
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].atime>p[j+1].atime)
            {
                Process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i-1;j++)
        {
            if(p[j].atime > p[j+1].atime && p[j].btime > p[j+1].btime)
            {
                Process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            
            if(p[j].atime < p[j+1].atime && p[j].btime > p[j+1].btime)
            {
                Process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
 
    //calculating tat and waittime
    int ctime=0;
    
    for(i=0;i<n;i++)
    {
        if(ctime < p[i].atime)
            ctime = p[i].atime;
            
        p[i].wtime = ctime-p[i].atime;
        p[i].ttime = p[i].wtime+p[i].btime;
        ctime +=p[i].btime;
    }
    
    //Gantt chart
    for(i=0;i<n;i++)
    {
        printf("| P%d",p[i].pid);
    }
    printf("\n");
    
    int temp=0;
    for(i=0;i<n;i++)
    {
        printf("%d",temp);
        temp+=p[i].btime;
    }
    
    //Table representation
    printf("\n Process \t Turn \t Wait \n");
    float total_ttime=0;
    float total_wtime=0;
    
  for(i=0;i<n;i++)
    {
        printf("p%d \t %d \t %d \t \n",p[i].pid,p[i].ttime,p[i].wtime);
        total_ttime=p[i].ttime;
        total_wtime=p[i].wtime;
    }
    
    //calculating Avg tat and wait time
    float avg_ttime = total_ttime/n;
    float avg_wtime = total_wtime/n;
    
    printf("Avg Turn: %.2f\n",avg_ttime);
    printf("Avg Wait: %.2f\n",avg_wtime);
}

void main()
{
    sjf();
}
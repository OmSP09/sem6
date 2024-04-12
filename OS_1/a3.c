#include <stdio.h>
#include <stdlib.h>

typedef struct Process{
    int pid;
    int atime;
    int btime;
    int wtime;
    int ttime;
    int pr;
}Process;

void priority()
{
    int n,i,j;
    
    printf("Enter the num of proc: ");
    scanf("%d",&n);
    
    Process *p = (Process *)malloc(n*sizeof(Process));
    
    for(i=0;i<n;i++)
    {
        p[i].pid = i+1;
        
        printf("Enter the atime for Process%d : ",i+1);
        scanf("%d",&p[i].atime);
        
        printf("Enter the btime for Process%d : ",i+1);
        scanf("%d",&p[i].btime);
        
        printf("Enter the Priority for Process%d : ",i+1);
        scanf("%d",&p[i].pr);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;i++)
        {
            if(p[j].atime > p[j+1].atime)
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
        for(j=1;j<n-i-1;i++)
        {
            if(p[j].atime > p[j+1].atime && p[j].pr > p[j+1].pr)
            {
                Process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            
            if(p[j].atime < p[j+1].atime && p[j].pr > p[j+1].pr)
            {
                Process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    int ctime=0;
    for(i=0;i<n;i++)
    {
        if(ctime < p[i].atime)
            ctime = p[i].atime;
        
        p[i].wtime = ctime - p[i].atime;
        p[i].ttime = p[i].wtime + p[i].btime;
        ctime += p[i].btime;
    }
    
    for(i=0;i<n;i++)
    {
        printf("|  P%d  ",p[i].pid);
    }
    printf("|\n");
    
    int temp=0;
    for(i=0;i<n+1;i++)
    {
        printf("%d       ",temp);
        temp += p[i].btime;
    }
    
    printf("\nProcess    TAT    WT\n");
    float total_ttime = 0;
    float total_wtime = 0;
    
    for(i=0;i<n;i++)
    {
        printf("%d       %d       %d\n",p[i].pid,p[i].ttime,p[i].wtime);
        total_ttime = p[i].ttime;
        total_wtime = p[i].wtime;
    }
    
    float avg_ttime = total_ttime/n;
    float avg_wtime = total_wtime/n;
    
    printf("Avg ttime: ",avg_ttime);
    printf("Avg wtime: ",avg_wtime);
}

int main()
{
    priority();
}
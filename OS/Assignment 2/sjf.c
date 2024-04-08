#include<stdio.h>
#include<string.h>
struct node{
char pname[10];
int at,bt,ct,st,tat,wt;
};
int gant_chart[10];
void accept(struct node a[],int n)
{

	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter process name : ");
		scanf("%s",a[i].pname);
		printf("Enter arrival time : ");
		scanf("%d",&a[i].at);
		printf("Enter the burst time : ");
		scanf("%d",&a[i].bt);
			
	}

}

void sort(struct node a[],int n)
{
	int i,j,temp;
	char sname[10];	
	for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j].at>a[j+1].at)
				{	//arrival time
					temp=a[j].at;
					a[j].at=a[j+1].at;
					a[j+1].at=temp;
		
					//burst time
					temp=a[j].bt;
					a[j].bt=a[j+1].bt;
					a[j+1].bt=temp;

					//name
					strcpy(sname,a[j].pname);
					strcpy(a[j].pname,a[j+1].pname);
					strcpy(a[j+1].pname,sname);
				}	
			}
		}

}


void sjf(struct node a[],int n)
{
int c_t=0,minbt,id,n1=0,i,j=0,completed[10]={0};
while(n1!=n)
{
	minbt=1000;
	id=-1;
	for(i=0;i<n;i++)
	{
		
		
			if(completed[i]==0 && a[i].at<=c_t && a[i].bt<minbt )
			{
				minbt=a[i].bt;
				id=i;	
			}	
	}
	if(id>=0)
	{
		a[id].st=c_t;
		a[id].ct=c_t+a[id].bt;
		a[id].tat=a[id].ct-a[id].at;
		a[id].wt=a[id].st-a[id].at;
		completed[id]=1;
		c_t=c_t+a[id].bt;
		n1++;
		gant_chart[j]=id;
		j++;

	}	
	else
	{
		c_t++;
	}

}


}

void display(struct node a[],int n)
{
	int i=0;
	float avg_tat = 0.0;
	float avg_wt = 0.0;
	printf("\n\nTable : \nProcess\t AT \t BT \t ST \t Tat \t CT\t WT\n");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d",a[i].pname,a[i].at,a[i].bt,a[i].st,a[i].tat,a[i].ct,a[i].wt);
		avg_tat += a[i].tat;
		avg_wt += a[i].wt;
	}

	printf("\n\nGantt chart\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d---%s---%d",a[gant_chart[i]].st,a[gant_chart[i]].pname,a[gant_chart[i]].ct);	
	}
	printf("\nAverage TAT : %f", avg_tat/n);
	printf("\nAverage WT : %f", avg_wt/n);

}

int main()
{
	struct node a[10];
	int n;

	printf("Enter the number of process : ");
	scanf("%d",&n);
	
	accept(a,n);
	sort(a,n);
	sjf(a,n);
	display(a,n);

	return 0;
}

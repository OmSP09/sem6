#include <stdio.h>
#include <string.h>
struct node
{
	int at, bt, bt1, tat, wt, ct, st;
	char pname[10];
};
struct gc
{
	char pname[10];
	int st, ct;
};
struct gc gant_chart[10];
struct node a[10];
int n, i, j, q_time, size = 0;

void accept()
{
	printf("Enter the number of process : ");
	scanf("%d", &n);
	printf("Enter the quantum time : ");
	scanf("%d", &q_time);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the process name : ");
		scanf("%s", a[i].pname);
		printf("Enter the arrival time : ");
		scanf("%d", &a[i].at);
		printf("Enter the burst time : ");
		scanf("%d", &a[i].bt);
		a[i].bt1 = a[i].bt;
		a[i].st = -1;
	}
}

void sort()
{
	int temp;
	char s[10];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j].at > a[j + 1].at)
			{
				temp = a[j].at;
				a[j].at = a[j + 1].at;
				a[j + 1].at = temp;

				temp = a[j].bt;
				a[j].bt = a[j + 1].bt;
				a[j + 1].bt = temp;

				temp = a[j].bt1;
				a[j].bt1 = a[j + 1].bt1;
				a[j + 1].bt1 = temp;

				strcpy(s, a[j].pname);
				strcpy(a[j].pname, a[j + 1].pname);
				strcpy(a[j + 1].pname, s);
			}
		}
	}
}

void display()
{
	float avg_tat = 0.0;
	float avg_wt = 0.0;
	printf("\nPname\tAT\tBT\tST\tCT\tWT\tTAT\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pname, a[i].at, a[i].bt, a[i].st, a[i].ct, a[i].wt, a[i].tat);
		avg_tat += a[i].tat;
		avg_wt += a[i].wt;
	}
	for (i = 0; i < size; i++)
	{
		printf("\n%d---%s---%d", gant_chart[i].st, gant_chart[i].pname, gant_chart[i].ct);
	}
	printf("\nAverage TAT : %f", avg_tat/n);
	printf("\nAverage WT : %f", avg_wt/n);
}

void rr()
{

	int n1 = 0, c_t = 0, i = 0, flag, temp, completed[10] = {0};
	while (n1 != n)
	{

		// if process is not completed and its at is less than current time
		if (completed[i] == 0 && a[i].at <= c_t)
		{
			// if process has not started its execution yet
			if (a[i].st == -1)
			{
				a[i].st = c_t;
				a[i].wt = a[i].st - a[i].at;
			}
			else
			{
				a[i].wt += (c_t - a[i].ct);
			}

			temp = c_t;

			// if process has burst time less than tq run it completely
			if (a[i].bt1 < q_time)
			{
				c_t += a[i].bt1;
				a[i].bt1 = 0;
			}
			else
			{
				a[i].bt1 -= q_time;
				c_t += q_time;
			}
			a[i].ct = c_t;
			// gantt chart 
			if (j && !strcmp(a[i].pname, gant_chart[j - 1].pname))
			{
				// to avoid multiple entries
				gant_chart[j - 1].ct = c_t;
			}
			else
			{
				strcpy(gant_chart[size].pname, a[i].pname);
				gant_chart[size].st = temp;
				gant_chart[size].ct = c_t;
				size++;
			}
			if (a[i].bt1 == 0)
			{
				completed[i] = 1;
				a[i].tat = c_t - a[i].at;
				n1++;
			}

			i = (i + 1) % n;
		}
		else
		{
			// if cpu is idle i.e ready q is empty add IDLE to gantt chart
			flag = 0;
			for (j = 0; j < n; j++)
			{
				if (completed[j] == 0 && a[j].at <= c_t)
				{
					// if we have some process in ready q then go back to above if
					flag = 1;
					break;
				}
			}
			if (flag)
				i = (i + 1) % n;
			else
			{
				
				if (j && !strcmp(gant_chart[j - 1].pname, "IDLE"))
				{
					gant_chart[j - 1].ct++;
				}
				else
				{
					gant_chart[j].st = c_t;
					gant_chart[j].ct = c_t + 1;
					strcpy(gant_chart[j].pname, "IDLE");
					j++;
				}
				c_t++;
			}
		}
	}
}

int main(void)
{
	accept();
	sort();
	rr();
	display();
	return 0;
}

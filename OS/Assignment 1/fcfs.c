#include <stdio.h>
#include <string.h>
void main()
{
	int n, i, j, temp, st[10], at[10], bt[10], ct[10], wt[10], tat[10];
	float avg_wt = 0.0, avg_tat = 0.0;
	char name[10][10], sname[10];

	printf("\nEnter the number of process : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter name of process : ");
		scanf("%s", name[i]);
		printf("Enter arrival time of process : ");
		scanf("%d", &at[i]);
		printf("Enter burst time of process : ");
		scanf("%d", &bt[i]);
		printf("\n\n");
	}

	// sorting according to arrival
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (at[j] > at[j + 1])
			{ // arrival time
				temp = at[j];
				at[j] = at[j + 1];
				at[j + 1] = temp;

				// burst time
				temp = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = temp;

				// name
				strcpy(sname, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], sname);
			}
		}
	}

	// completion time
	ct[0] = at[0] + bt[0];
	st[0] = 0;
	for (i = 1; i < n; i++)
	{
		temp = 0;
		if (ct[i - 1] < at[i])
		{
			temp = at[i] - ct[i - 1];
		}
		ct[i] = ct[i - 1] + bt[i] + temp;
	}
	for (i = 1; i < n; i++)
	{
		st[i] = ct[i - 1];
	}

	// turnaround time
	for (i = 0; i < n; i++)
	{
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		avg_wt = avg_wt + wt[i];
		avg_tat = avg_tat + tat[i];
	}

	printf("Process\t BT \t AT \t WT \t Tat\t Ct\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\n", name[i], bt[i], at[i], wt[i], tat[i], ct[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("\n%d---%s---%d", st[i], name[i], ct[i]);
	}

	printf("\n\nAverage waiting time=%f\nAverage turnaround time=%f\n\n", (avg_wt / n), (avg_tat / n));
}

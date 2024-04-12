#include <stdio.h>

int main()
{
    int n, m; // n = number of processes, m = number of resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Dynamic arrays for Max, Allocation, and Need
    int Max[n][m], Allocation[n][m], Need[n][m];

    // Input for Max and Allocation
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Max matrix for process %d: ", i + 1);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &Max[i][j]);
        }
        printf("Enter the Allocation matrix for process %d: ", i + 1);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &Allocation[i][j]);
        }
    }

    // Calculate Need
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Display Allocation, Max, Available, and Need
    printf("\nAllocation:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Allocation[i][j]);
        }
        printf("\n");
    }
    printf("\nMax:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Max[i][j]);
        }
        printf("\n");
    }
    printf("\nNeed:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }

    // Input for Available
    int Available[m];
    printf("Enter the Available array: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &Available[i]);
    }

    // Display Available
    printf("\nAvailable:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", Available[i]);
    }

    // Check if system is in safe state
    int Work[m];
    
    for (int i = 0; i < m; i++)
    {
        Work[i] = Available[i];
    }

    int Finish[n];
    for (int i = 0; i < n; i++)
    {
        Finish[i] = 0;
    }

    int flag, count = 0;
    while (count < n)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (Finish[i] == 0)
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (Need[i][j] > Work[j])
                    {
                        printf("Breaking %d",i);
                        break;
                    }
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                    {
                        Work[k] += Allocation[i][k];
                    }
                    Finish[i] = 1;
                    flag = 1;
                    count++;
                }
            }
        }
        if (flag == 0)
        {
            printf("\nSystem is not in safe state.\n");
            return 0;
        }
    }
    printf("\nSystem is in safe state.\n");
    return 0;
}

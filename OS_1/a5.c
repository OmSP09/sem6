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
                int count_resources = 0;
                for (int j = 0; j < m; j++)
                {
                    if (Need[i][j] <= Work[j])
                    {
                        count_resources++;
                    }
                }
                if (count_resources == m)
                {
                    printf("\nProcess %d can run to completion", i + 1);
                    for (int j = 0; j < m; j++)
                    {
                        Work[j] += Allocation[i][j];
                    }
                    Finish[i] = 1;
                    flag = 1;
                    count++;
                }
            }
        }
        if (flag == 0)
        {
            printf("\nThe system is not in safe state");
            return 0;
        }
    }
    printf("\nThe system is in safe state\n");

    // Accept request for any process and check if request is granted or not
    int process, request[m];
    printf("\nEnter the process number for resource request: ");
    scanf("%d", &process);
    printf("Enter the request array: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &request[i]);

    // Check if request can be granted
    int resources_count = 0;
    for (int i = 0; i < m; i++)
    {
        if (request[i] <= Need[process - 1][i] && request[i] <= Available[i])
        {
            resources_count++;
        }
    }
    if (resources_count == m)
    {
        printf("\nRequest granted for process %d\n", process);
        for (int i = 0; i < m; i++)
        {
            Available[i] -= request[i];
            Allocation[process - 1][i] += request[i];
            Need[process - 1][i] -= request[i];
        }
    }
    else
    {
        printf("\nRequest not granted for process %d\n", process);
    }

    return 0;
}
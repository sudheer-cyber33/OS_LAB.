#include <stdio.h>

int main()
{
    int n, tq;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int visited[20] = {0};
    int queue[100], front = 0, rear = 0;

    int time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    // Find first arriving process
    int min = 0;
    for(int i = 1; i < n; i++)
    {
        if(at[i] < at[min])
            min = i;
    }

    time = at[min];
    queue[rear++] = min;
    visited[min] = 1;

    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        if(front == rear)
        {
            time++;
            for(int i = 0; i < n; i++)
            {
                if(at[i] <= time && rt[i] > 0 && !visited[i])
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];

        printf("P%d ", i + 1);

        if(rt[i] > tq)
        {
            rt[i] -= tq;
            time += tq;
        }
        else
        {
            time += rt[i];
            rt[i] = 0;
            completed++;

            ct[i] = time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            avgWT += wt[i];
            avgTAT += tat[i];
        }

        // Add newly arrived processes
        for(int j = 0; j < n; j++)
        {
            if(at[j] <= time && rt[j] > 0 && !visited[j])
            {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // Add current process again if not completed
        if(rt[i] > 0)
            queue[rear++] = i;
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avgTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);

    return 0;
}

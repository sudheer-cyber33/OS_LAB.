#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int shortest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    while(completed < n)
    {
        shortest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(shortest == -1 || rt[i] < rt[shortest])
                {
                    shortest = i;
                }
            }
        }

        if(shortest == -1)
        {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            completed++;

            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            avg_tat += tat[shortest];
            avg_wt += wt[shortest];
        }
    }

    printf("\n-------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    printf("-------------------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

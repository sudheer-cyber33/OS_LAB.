#include <stdio.h>

struct Process
{
    int pid, at, bt, rt, priority;
    int ct, tat, wt;
};

int main()
{
    int n, time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        printf("Enter Priority of P%d (Lower Number = Higher Priority): ", i + 1);
        scanf("%d", &p[i].priority);

        p[i].rt = p[i].bt;
    }

    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        int highest = -1;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= time && p[i].rt > 0)
            {
                if(highest == -1 ||
                   p[i].priority < p[highest].priority ||
                  (p[i].priority == p[highest].priority &&
                   p[i].at < p[highest].at))
                {
                    highest = i;
                }
            }
        }

        if(highest == -1)
        {
            printf("Idle ");
            time++;
            continue;
        }

        printf("P%d ", p[highest].pid);

        p[highest].rt--;
        time++;

        if(p[highest].rt == 0)
        {
            completed++;

            p[highest].ct = time;
            p[highest].tat = p[highest].ct - p[highest].at;
            p[highest].wt = p[highest].tat - p[highest].bt;

            avgWT += p[highest].wt;
            avgTAT += p[highest].tat;
        }
    }

    printf("\n\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].priority,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", avgTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);

    return 0;
}
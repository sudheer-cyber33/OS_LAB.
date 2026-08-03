#include <stdio.h>

struct Process{
    int pid,at,bt,ct,wt,tat;
};

int main(){
    int n,i,j;
    struct Process p[20],temp;
    float avg_wt=0,avg_tat=0;

    printf("Enter the number of processes: ");



    scanf("%d",&n);

    // Input Arrival Time and Burst Time
    for(i=0; i<n; i++){
        p[i].pid=i+1;
        printf("\nProcess P%d\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }

    // Sort processes based on Arrival Time
    for(i=0; i<n-1;i++){
        for(j=i+1; j<n; j++){
            if(p[i].at >p[j].at){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    // Calculate Completion Time
    p[0].ct=p[0].at+p[0].bt;

    for(i=1; i<n; i++){
        if(p[i].at>p[i-1].ct)
            p[i].ct=p[i].at+p[i].bt;
        else
            p[i].ct=p[i-1].ct+p[i].bt;
    }

    // Calculate Turnaround Time and Waiting Time
    for(i=0; i<n; i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;

        avg_wt+=p[i].wt;
        avg_tat+=p[i].tat;
    }

    // Display Results
    printf("\nPID\t AT\t BT\t CT\t TAT\t WT\n");

    for(i=0; i<n; i++){
        printf("P%d\t %d\t %d\t %d\t %d\t   %d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);

    return 0;
}

#include <stdio.h>
int main(){
    int n, i;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    for(i=0; i<n; i++) {
        printf("Enter Burst Time of Process P%d: ",i+1);
        scanf("%d", &bt[i]);
    }

                 // Waiting Time Calculation
    wt[0]=0;
    for(i=1; i<n; i++){
        wt[i]=wt[i-1]+bt[i-1];
        avg_wt+=wt[i];
    }

                // Turnaround Time Calculation
    for(i=0; i<n; i++){
        tat[i]=wt[i]+bt[i];
        avg_tat+= tat[i];
    }

                // Display Results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0; i<n; i++){
        printf("P%d\t %d\t\t %d\t\t %d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}

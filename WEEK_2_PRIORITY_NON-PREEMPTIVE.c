#include <stdio.h>
int main(){
    int n,i,j;
    int bt[20],pr[20],wt[20],tat[20];
    float avg_wt=0, avg_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Burst Time and Priority:\n");

    for(i=0; i<n; i++){
        printf("P%d Burst Time: ",i+1);
        scanf("%d",&bt[i]);

        printf("P%d Priority: ",i+1);
        scanf("%d",&pr[i]);
    }

                                   // Sorting according to priority
    for(i=0; i<n-1;i++){
        for(j=i+1; j<n; j++){
            if(pr[i]>pr[j]){
                int temp;

                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;

                temp= bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }

    wt[0]=0;

    for(i=1; i<n; i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(i=0; i<n; i++){
        tat[i]=wt[i]+bt[i];
    }

    printf("\nPriority\tBT\tWT\tTAT\n");

    for(i=0; i<n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\n", pr[i], bt[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}

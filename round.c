#include <stdio.h>

int main() {
    int n, q;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    char pid[n][10];
    int bt[n];
    int rt[n]; // current burst time
    int ct[n]; // completion time
    int tat[n];
    int wt[n];
    int t = 0; // current time
    int d;     // done
    int total_tat = 0;
    int total_wt = 0;

    printf("Enter process ID: ");
    for (int i = 0; i < n; i++) {
        scanf("%s", pid[i]);
    }

    printf("Enter burst time: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter the quantum time: ");
    scanf("%d", &q);

    do {
        d = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                d = 0;
                if (rt[i] > q) {
                    t += q;
                    rt[i] -= q;
                } else {
                    t += rt[i];
                    rt[i] = 0;
                    ct[i] = t;
                    tat[i] = ct[i];
                    wt[i] = tat[i] - bt[i];
                    total_tat += tat[i];
                    total_wt += wt[i];
                    printf("Process %s finished at time %d\n", pid[i], t);
                }
            }
        }
    } while (!d);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", pid[i], 0, bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turn Around Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);

    return 0;
}

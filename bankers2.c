#include <stdio.h>

int main() {
    int n, m = 3; // n = number of processes, m = number of resources (A, B, C)
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int alloc[n][3], max[n][3], need[n][3], finish[n];
    int avail[3], work[3], safeSeq[n];

    // Input allocation and max matrices
    for (int i = 0; i < n; i++) {
        printf("Enter P%d Allocation of A B C: ", i + 1);
        for (int j = 0; j < 3; j++)
            scanf("%d", &alloc[i][j]);

        printf("Enter P%d Maximum for A B C: ", i + 1);
        for (int j = 0; j < 3; j++)
            scanf("%d", &max[i][j]);
    }

    // Input available resources
    printf("Enter the number of instances available for A B C: ");
    for (int i = 0; i < 3; i++)
        scanf("%d", &avail[i]);

    // Calculate need matrix and initialize finish
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
        for (int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize work = available
    for (int i = 0; i < 3; i++)
        work[i] = avail[i];

    // Find safe sequence
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < 3; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == 3) {
                    for (int k = 0; k < 3; k++)
                        work[k] += alloc[i][k];

                    printf("Process %d is allocated new available/work = %d %d %d\n",
                           i + 1, work[0], work[1], work[2]);

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state.\n");
            return 1;
        }
    }

    printf("\nSafe sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i] + 1);

    printf("\nAvailable resources after execution: %d %d %d\n", work[0], work[1], work[2]);

    return 0;
}

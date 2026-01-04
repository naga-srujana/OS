#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, pos, min, diff, total_movement = 0;
    int queue[100], visited[100];

    // Input
    printf("Enter total number of locations: ");
    scanf("%d", &n);

    printf("Enter position of disk head: ");
    scanf("%d", &head);

    printf("Enter elements of disk head queue:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        visited[i] = 0; // mark all as not visited
    }

    printf("Seek Sequence: ");

    for (i = 0; i < n; i++) {
        min = 100000;
        pos = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                diff = abs(head - queue[j]);
                if (diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }

        visited[pos] = 1;
        total_movement += abs(head - queue[pos]);
        head = queue[pos];
        printf("%d", head);
        if (i != n - 1) printf(" -> ");
    }

    printf("\nTotal movement of cylinders: %d\n", total_movement);
    return 0;
}

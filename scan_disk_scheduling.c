#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, min, diff, total = 0, pos;

    printf("Enter total number of locations: ");
    scanf("%d", &n);

    int queue[n], visited[n];

    printf("Enter position of disk head: ");
    scanf("%d", &head);

    printf("Enter elements of disk head queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        visited[i] = 0;
    }

    for(i = 0; i < n; i++) {
        min = 10000;  // Large number
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                diff = abs(queue[j] - head);
                if(diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }
        total += min;
        head = queue[pos];
        visited[pos] = 1;
    }

    printf("Total movements of the cylinders: %d\n", total);
    return 0;
}

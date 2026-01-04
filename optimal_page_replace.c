#include <stdio.h>

int main() {
    int pages[100], frames[10];
    int n, f;
    int i, j, k, l, index, max, count = 0, flag, nextUse[10];

    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input page reference string
    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1
    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nOptimal Page Replacement Algorithm\n");
    printf("Page\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page is already in frames
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            // Page fault occurs
            count++;

            // Check for empty frame
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                // Optimal Replacement logic
                for (j = 0; j < f; j++) {
                    nextUse[j] = -1;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            nextUse[j] = k;
                            break;
                        }
                    }
                }

                max = -1;
                index = -1;
                for (j = 0; j < f; j++) {
                    if (nextUse[j] == -1) {
                        index = j;
                        break;
                    }
                    if (nextUse[j] > max) {
                        max = nextUse[j];
                        index = j;
                    }
                }

                frames[index] = pages[i];
            }
        }

        printf("%d\t", pages[i]);
        for (l = 0; l < f; l++) {
            if (frames[l] == -1)
                printf("-1 ");
            else
                printf("%d ", frames[l]);
        }
        printf("\n");
    }

    printf("\nNumber of Page Faults = %d\n", count);

    return 0;
}

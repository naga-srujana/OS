#include <stdio.h>

int main() {
    int i, j, k, n, frames, faults = 0;
    int pages[100], frame[10], index = 0, flag;

    // Get number of pages and the reference string
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Get number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Initialize frames to -1 (empty)
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nRef string\tPage Frames\n");
    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page already exists in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page fault, replace using FIFO
        if (flag == 0) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }

        // Print page reference and current frame content
        printf("    %d\t\t", pages[i]);
        for (k = 0; k < frames; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal number of page faults are = %d\n", faults);
    return 0;
}

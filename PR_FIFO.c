// FIFO Page Replacement Algorithm in C
#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, flag, pageFaults = 0, index = 0;

    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input page reference string
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames with -1
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    // FIFO Algorithm
    for(i = 0; i < n; i++) {

        flag = 0;

        // Check if page already exists
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // Page Fault
        if(flag == 0) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            pageFaults++;
        }

        // Print current frames
        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

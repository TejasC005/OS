// LRU Page Replacement Algorithm in C
#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, flag, pageFaults = 0;
    int count = 0, pos, min;

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

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    // LRU Algorithm
    for(i = 0; i < n; i++) {

        flag = 0;

        // Check if page already exists
        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {
                flag = 1;

                // Update recent use time
                time[j] = count++;
                break;
            }
        }

        // Page Fault
        if(flag == 0) {

            // Find empty frame
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find least recently used
            if(j == f) {
                min = time[0];
                pos = 0;

                for(j = 1; j < f; j++) {
                    if(time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }
            }

            // Replace page
            frames[pos] = pages[i];
            time[pos] = count++;
            pageFaults++;
        }

        // Print frames
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

// Optimal Page Replacement Algorithm in C
#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, flag, pageFaults = 0;
    int pos, farthest, found;

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

    // Optimal Algorithm
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

            // Find empty frame
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame
            if(j == f) {

                farthest = -1;
                pos = 0;

                for(j = 0; j < f; j++) {

                    found = 0;

                    // Check future use
                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {

                            if(k > farthest) {
                                farthest = k;
                                pos = j;
                            }

                            found = 1;
                            break;
                        }
                    }

                    // If page never used again
                    if(found == 0) {
                        pos = j;
                        break;
                    }
                }
            }

            // Replace page
            frames[pos] = pages[i];
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

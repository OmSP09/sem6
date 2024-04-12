#include <stdio.h>
#include <stdlib.h>

void main() {

    int *refString, pagefaults = 0, i, pages, frames;
    printf("Enter number of pages for reference string: ");
    scanf("%d", &pages);
    
    refString = (int *)malloc(pages * sizeof(int));
    printf("\nEnter the reference string value: ");
    for (i = 0; i < pages; i++) {
        printf("Value no. %d:", i + 1);
        scanf("%d", &refString[i]);
    }
    
    printf("\nEnter total number of frames: ");
    scanf("%d", &frames);

    int temp[frames];
    int freq[frames];
    for (i = 0; i < frames; i++) {
        temp[i] = -1;
        freq[i] = 0;
    }

    int j, s = 0;
    for (i = 0; i < pages; i++) {
        s = 0;
        for (j = 0; j < frames; j++) {
            if (refString[i] == temp[j]) {
                s++;
                freq[j]++;
                pagefaults--;
            }
        }
        pagefaults++;
        if ((pagefaults <= frames) && (s == 0)) {
            temp[i] = refString[i];
            freq[i] = 1;
        } else if (s == 0) {
            int minFreq = freq[0];
            int minIndex = 0;
            for (j = 1; j < frames; j++) {
                if (freq[j] < minFreq) {
                    minFreq = freq[j];
                    minIndex = j;
                }
            }
            temp[minIndex] = refString[i];
            freq[minIndex] = 1;
        }

        printf("\n");

        for (j = 0; j < frames; j++) {
            printf("%d\t", temp[j]);
        }
        printf("\n");
    }
    printf("\n\nTotal number of page faults: %d", pagefaults);
}
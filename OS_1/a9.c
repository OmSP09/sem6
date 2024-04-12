#include <stdio.h>
#include <stdlib.h>

int n, p, pfcounter = 0;
int *frame, *pagerefstr, *timestamp;

int findPage(int x) {
    for (int i = 0; i < n; i++)
        if (frame[i] == x)
            return i;
    return -1;
}

void displayFrame() {
    for (int i = 0; i < n; i++)
        printf("%d ", frame[i]);
    printf("\n");
}

int main() {
    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the number of pages in page reference string: ");
    scanf("%d", &p);

    frame = (int *)calloc(n, sizeof(int));
    pagerefstr = (int *)malloc(p * sizeof(int));
    timestamp = (int *)calloc(n, sizeof(int));

    printf("Enter pages: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &pagerefstr[i]);
    }

    int time = 0;
    for (int i = 0; i < p; i++) {
        int ref = pagerefstr[i];
        time++;

        int pos = findPage(ref);
        if (pos == -1) {
            pfcounter++;
            printf("Page fault-%d: ", pfcounter);

            if (frame[0] == -1) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (frame[j] == -1) 
                    {
                        frame[j] = ref;
                        timestamp[j] = time;
                        break;
                    }
                }
            } 
            else
            {
                int lruIndex = 0;
                for (int j = 1; j < n; j++) 
                {
                    if (timestamp[lruIndex] > timestamp[j])
                        lruIndex = j;
                }
                frame[lruIndex] = ref;
                timestamp[lruIndex] = time;
            }
            displayFrame();
        } 
        else 
        {
            timestamp[pos] = time;
            printf("Match found\n");
        }
    }

    printf("Total page faults: %d\n", pfcounter);
    free(frame);
    free(pagerefstr);
    free(timestamp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *refString, pagefaults = 0, i, j, pages, frames;

    printf("Enter number of pages for reference string: ");
    scanf("%d", &pages);

    refString = (int *)malloc(pages * sizeof(int));

    printf("\nEnter the reference string value: ");

    for (i = 0; i < pages; i++)
    {
        printf("Value no. %d:", i + 1);
        scanf("%d", &refString[i]);
    }

    printf("\nEnter total number of frames: ");
    scanf("%d", &frames);

    int *temp = (int *)malloc(frames * sizeof(int));

    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
    }

    for (i = 0; i < pages; i++)
    {
        int pageFound = 0;

		//for page hit
        for (j = 0; j < frames; j++)
        {
            if (refString[i] == temp[j])
            {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
        {
            int replaceIndex = -1;
            for (j = 0; j < frames; j++)
            {
                if (temp[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1)
            {
                replaceIndex = pagefaults % frames;
            }

            temp[replaceIndex] = refString[i];
            pagefaults++;
        }

        printf("\n");
        for (j = 0; j < frames; j++)
        {
            printf("%d\t", temp[j]);
        }
    }

    printf("\n\nTotal number of page faults: %d\n", pagefaults);

    return 0;
}

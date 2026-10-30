#include <stdio.h>

int main()
{
    int n, i, j, count;
    int alreadyPrinted;
    int foundDuplicate = 0;
    int ids[100];

    printf("Enter number of borrow records: ");
    scanf("%d", &n);

    printf("Enter book IDs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ids[i]);
    }

    printf("duplicate book IDs are: ");

    for (i = 0; i < n; i++)
    {
        alreadyPrinted = 0;
        count = 0;

      
        for (j = 0; j < i; j++)
        {
            if (ids[i] == ids[j])
            {
                alreadyPrinted = 1;
                break;
            }
        }

        if (alreadyPrinted)
        {
            continue;
        }

        // Count occurrences
        for (j = 0; j < n; j++)
        {
            if (ids[i] == ids[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            printf("%d ", ids[i]);
            foundDuplicate = 1;
        }
    }

    if (!foundDuplicate)
    {
        printf("No duplicate IDs");
    }
    
printf("\nSwara Patel 25DCS099\n");
printf("Program Compiled DATE: %s\n", __DATE__);
printf("Compilation Time: %s\n", __TIME__);
    return 0;
}
#include <stdio.h>

#define SIZE 10

int main()
{
    int table[SIZE];
    int n, i, id, index, step, j;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter student ID: ");
        scanf("%d", &id);

        index = id % SIZE;
        step = 7 - (id % 7);
        j = 0;

        while (table[index] != -1 && j < SIZE)
        {
            index = (index + step) % SIZE;
            j++;
        }

        if (j == SIZE)
            printf("Hash table is full or no slot found for ID %d\n", id);
        else
            table[index] = id;
    }

    printf("\nFinal Hash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, table[i]);
    }
 printf("\nSwara Patel 25DCS099\n");
    printf("Program Compiled DATE: %s\n", __DATE__);
    printf("Compilation Time: %s\n\n", __TIME__);
    return 0;
}